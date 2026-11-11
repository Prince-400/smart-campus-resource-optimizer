
#include <iostream>
#include "PriorityQueue.h"

using namespace std;

int main() {

    PriorityQueue pq;

    pq.push(AllocationRequest(
        "A001", "Lecture", 40,
        true, false, 540, 600, 2
    ));

    pq.push(AllocationRequest(
        "A002", "Emergency Meeting", 30,
        false, false, 600, 660, 5
    ));

    pq.push(AllocationRequest(
        "A003", "Lab Session", 25,
        false, true, 660, 720, 3
    ));

    pq.push(AllocationRequest(
        "A004", "Important Seminar", 50,
        true, true, 480, 540, 4
    ));

    cout << "Processing requests by priority:\n\n";

    while (!pq.empty()) {

        AllocationRequest request = pq.top();

        cout << "Request ID: "
             << request.getRequestId() << "\n";

        cout << "Priority: "
             << request.getPriority() << "\n";

        cout << "Purpose: "
             << request.getPurpose() << "\n";

        cout << "---------------------\n";

        pq.pop();
    }

    return 0;
}
