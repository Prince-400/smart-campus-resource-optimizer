
#ifndef INTERVAL_TREE_H
#define INTERVAL_TREE_H

#include "Booking.h"
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class IntervalTree {
private:
    struct Node {
        Booking booking;
        int maxEnd;
        Node* left;
        Node* right;

        Node(const Booking& b)
            : booking(b),
              maxEnd(b.getEndTime()),
              left(nullptr),
              right(nullptr) {}
    };

    Node* root = nullptr;

    void updateMaxEnd(Node* node) {
        if (!node) return;

        node->maxEnd = node->booking.getEndTime();

        if (node->left) {
            node->maxEnd = max(
                node->maxEnd, node->left->maxEnd
            );
        }

        if (node->right) {
            node->maxEnd = max(
                node->maxEnd, node->right->maxEnd
            );
        }
    }

    Node* insertNode(Node* node, const Booking& booking) {
        if (!node) {
            return new Node(booking);
        }

        if (booking.getStartTime() <
            node->booking.getStartTime()) {
            node->left = insertNode(node->left, booking);
        }
        else {
            node->right = insertNode(node->right, booking);
        }

        updateMaxEnd(node);
        return node;
    }

    void findOverlaps(
        Node* node,
        const string& roomId,
        int start,
        int end,
        vector<Booking>& results
    ) const {
        if (!node) return;

        // Search left subtree only if it may contain
        // an interval that reaches the requested start.
        if (node->left && node->left->maxEnd > start) {
            findOverlaps(
                node->left, roomId, start, end, results
            );
        }

        int currentStart = node->booking.getStartTime();
        int currentEnd = node->booking.getEndTime();

        // Half-open interval overlap:
        // [currentStart, currentEnd)
        // overlaps [start, end) when both conditions hold.
        bool overlaps =
            currentStart < end && start < currentEnd;

        if (node->booking.getRoomId() == roomId &&
            overlaps) {
            results.push_back(node->booking);
        }

        // The right subtree has start times >= current start.
        if (currentStart < end) {
            findOverlaps(
                node->right, roomId, start, end, results
            );
        }
    }

    void displayInOrder(Node* node) const {
        if (!node) return;

        displayInOrder(node->left);
        node->booking.displayBooking();
        displayInOrder(node->right);
    }

    void clear(Node* node) {
        if (!node) return;

        clear(node->left);
        clear(node->right);
        delete node;
    }

public:
    IntervalTree() = default;

    // Prevent accidental shallow copies of raw pointers.
    IntervalTree(const IntervalTree&) = delete;
    IntervalTree& operator=(const IntervalTree&) = delete;

    ~IntervalTree() {
        clear(root);
    }

    void insert(const Booking& booking) {
        root = insertNode(root, booking);
    }

    vector<Booking> searchOverlaps(
        const string& roomId,
        int start,
        int end
    ) const {
        vector<Booking> results;

        if (start >= end) {
            return results;
        }

        findOverlaps(root, roomId, start, end, results);
        return results;
    }

    void displayAll() const {
        if (!root) {
            cout << "\nNo bookings available.\n";
            return;
        }

        displayInOrder(root);
    }
};

#endif
