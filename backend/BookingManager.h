
#ifndef BOOKING_MANAGER_H
#define BOOKING_MANAGER_H

#include "IntervalTree.h"
#include <vector>
#include <string>
using namespace std;

class BookingManager {
private:
    IntervalTree bookingTree;
    vector<Booking> bookings;

public:
    bool addBooking(const Booking& booking);
    void displayAllBookings() const;
    int getTotalBookings() const;
};

#endif
