
#include <iostream>

#include "RoomManager.h"
#include "BookingManager.h"
#include "ResourceAllocator.h"

using namespace std;

int main() {

    RoomManager roomManager;
    BookingManager bookingManager;
    ResourceAllocator allocator;

    // Add rooms.
    roomManager.addRoom(
        Room("R101", "Lecture Hall", "Classroom",
             60, true, false)
    );

    roomManager.addRoom(
        Room("R102", "Small Classroom", "Classroom",
             40, true, false)
    );

    roomManager.addRoom(
        Room("L201", "Computer Lab", "Laboratory",
             50, true, true)
    );

    // Block L201 from 10:00 to 12:00.
    bookingManager.addBooking(
        Booking("B001", "L201", "Existing Lab Session",
                600, 720)
    );

    // Request a room for 45 students,
    // requiring a projector and no computers.
    AllocationRequest request(
        "A001",
        "Seminar",
        45,
        true,
        false,
        600,
        720,
        4
    );

    string selectedRoom = allocator.findBestRoom(
        request,
        roomManager,
        bookingManager
    );

    if (selectedRoom.empty()) {
        cout << "No suitable room available!\n";
    }
    else {
        cout << "Best room allocated: "
             << selectedRoom << "\n";
    }

    return 0;
}
