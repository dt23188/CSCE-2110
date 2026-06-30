#ifndef QUEUESYSTEM_H
#define QUEUESYSTEM_H

#include <queue>
#include <string>

struct AdvisingRequest {
    int studentID;
    std::string issueDescription;
};

class QueueSystem {
private:
    std::queue<AdvisingRequest> requests;

public:
    void addRequest(const AdvisingRequest& request);
    bool processNextRequest();
    void displayPendingRequests() const;
    int getPendingCount() const;
};

#endif