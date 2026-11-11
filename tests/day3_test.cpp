
#include "IntervalTree.h"
#include <iostream>
using namespace std;

int main() {
    IntervalTree tree;

    // Existing bookings
    tree.insert(Booking("B001", "R101",
                        "Lecture", 540, 660));

    tree.insert(Booking("B002", "R101",
                        "Meeting", 660, 720));

    tree.insert(Booking("B003", "L201",
                        "Lab Session", 600, 720));

    // New booking: 10:00 to 11:00 in R101
    int newStart = 600;
    int newEnd = 660;

    vector<Booking> conflicts =
        tree.searchOverlaps("R101", newStart, newEnd);

    if (conflicts.empty()) {
        cout << "\nNo scheduling conflict found.\n";
    }
    else {
        cout << "\nScheduling conflicts found:\n";

        for (const Booking& booking : conflicts) {
            booking.displayBooking();
        }
    }

    return 0;
}
