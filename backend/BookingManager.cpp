
#include "BookingManager.h"
#include <iostream>
using namespace std;

bool BookingManager::addBooking(const Booking& booking) {

    // Validate time
    if (booking.getStartTime() < 0 ||
        booking.getEndTime() > 1440 ||
        booking.getStartTime() >= booking.getEndTime()) {

        cout << "\nInvalid booking time!\n";
        return false;
    }

    // Check duplicate booking ID
    for (const Booking& existing : bookings) {
        if (existing.getBookingId() == booking.getBookingId()) {
            cout << "\nBooking ID already exists!\n";
            return false;
        }
    }

    // Check room-specific scheduling conflicts
    vector<Booking> conflicts =
        bookingTree.searchOverlaps(
            booking.getRoomId(),
            booking.getStartTime(),
            booking.getEndTime()
        );

    if (!conflicts.empty()) {
        cout << "\nBooking rejected! Room is already booked.\n";
        cout << "Conflicting bookings:\n";

        for (const Booking& conflict : conflicts) {
            conflict.displayBooking();
        }

        return false;
    }

    // No conflict: insert booking
    bookingTree.insert(booking);
    bookings.push_back(booking);

    cout << "\nBooking added successfully!\n";
    return true;
}

void BookingManager::displayAllBookings() const {
    if (bookings.empty()) {
        cout << "\nNo bookings available.\n";
        return;
    }

    cout << "\n========== ALL BOOKINGS ==========\n";
    bookingTree.displayAll();
}

int BookingManager::getTotalBookings() const {
    return static_cast<int>(bookings.size());
}
