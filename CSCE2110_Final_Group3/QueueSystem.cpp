#include "QueueSystem.h"
#include <iostream>

using namespace std;

void QueueSystem::addRequest(
    const AdvisingRequest& request
) {
    requests.push(request);
    cout << "Advising request added." << endl;
}

bool QueueSystem::processNextRequest() {
    if (requests.empty()) {
        cout << "No advising requests are pending." << endl;
        return false;
    }

    AdvisingRequest request = requests.front();

    cout << "Processing advising request:" << endl;
    cout << "Student ID: " << request.studentID << endl;
    cout << "Issue: " << request.issueDescription << endl;

    requests.pop();
    return true;
}

void QueueSystem::displayPendingRequests() const {
    if (requests.empty()) {
        cout << "No advising requests are pending." << endl;
        return;
    }

    queue<AdvisingRequest> tempQueue = requests;
    int number = 1;

    cout << "Pending Advising Requests:" << endl;

    while (!tempQueue.empty()) {
        AdvisingRequest request = tempQueue.front();

        cout << number
            << ". Student ID: "
            << request.studentID << endl;

        cout << "   Issue: "
            << request.issueDescription << endl;

        tempQueue.pop();
        number++;
    }
}

int QueueSystem::getPendingCount() const {
    return static_cast<int>(requests.size());
}
