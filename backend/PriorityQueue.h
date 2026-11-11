
#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include "AllocationRequest.h"
#include <vector>
#include <utility>

using namespace std;

class PriorityQueue {
private:
    vector<AllocationRequest> heap;

    // Returns true if request A has higher priority than B.
    bool hasHigherPriority(
        const AllocationRequest& a,
        const AllocationRequest& b
    ) const {

        if (a.getPriority() != b.getPriority()) {
            return a.getPriority() > b.getPriority();
        }

        // Earlier start time wins in case of a tie.
        return a.getStartTime() < b.getStartTime();
    }

    void heapifyUp(int index) {

        while (index > 0) {

            int parent = (index - 1) / 2;

            if (hasHigherPriority(heap[index], heap[parent])) {
                swap(heap[index], heap[parent]);
                index = parent;
            }
            else {
                break;
            }
        }
    }

    void heapifyDown(int index) {

        int size = static_cast<int>(heap.size());

        while (true) {

            int highest = index;
            int left = 2 * index + 1;
            int right = 2 * index + 2;

            if (left < size &&
                hasHigherPriority(heap[left], heap[highest])) {
                highest = left;
            }

            if (right < size &&
                hasHigherPriority(heap[right], heap[highest])) {
                highest = right;
            }

            if (highest == index) {
                break;
            }

            swap(heap[index], heap[highest]);
            index = highest;
        }
    }

public:

    // Insert a request.
    void push(const AllocationRequest& request) {

        heap.push_back(request);

        heapifyUp(static_cast<int>(heap.size()) - 1);
    }

    // Get the highest-priority request.
    AllocationRequest top() const {

        if (empty()) {
            throw out_of_range("Priority Queue is empty!");
        }

        return heap[0];
    }

    // Remove the highest-priority request.
    void pop() {

        if (empty()) {
            return;
        }

        heap[0] = heap.back();
        heap.pop_back();

        if (!empty()) {
            heapifyDown(0);
        }
    }

    bool empty() const {
        return heap.empty();
    }

    int size() const {
        return static_cast<int>(heap.size());
    }
};

#endif
