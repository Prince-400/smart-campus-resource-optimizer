
#ifndef ALLOCATION_REQUEST_H
#define ALLOCATION_REQUEST_H

#include <string>
using namespace std;

class AllocationRequest {
private:
    string requestId;
    string purpose;
    int requiredCapacity;
    bool needsProjector;
    bool needsComputers;
    int startTime;
    int endTime;
    int priority;

public:
    AllocationRequest(
        string id,
        string reason,
        int capacity,
        bool projector,
        bool computers,
        int start,
        int end,
        int requestPriority
    ) {
        requestId = id;
        purpose = reason;
        requiredCapacity = capacity;
        needsProjector = projector;
        needsComputers = computers;
        startTime = start;
        endTime = end;
        priority = requestPriority;
    }

    string getRequestId() const {
        return requestId;
    }

    string getPurpose() const {
        return purpose;
    }

    int getRequiredCapacity() const {
        return requiredCapacity;
    }

    bool getNeedsProjector() const {
        return needsProjector;
    }

    bool getNeedsComputers() const {
        return needsComputers;
    }

    int getStartTime() const {
        return startTime;
    }

    int getEndTime() const {
        return endTime;
    }

    int getPriority() const {
        return priority;
    }
};

#endif
