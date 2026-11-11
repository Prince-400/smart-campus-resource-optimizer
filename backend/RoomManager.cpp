
#include "RoomManager.h"

// Add a new room
bool RoomManager::addRoom(const Room& room) {

    // Check duplicate room ID
    for (const Room& r : rooms) {
        if (r.getRoomId() == room.getRoomId()) {
            cout << "Room ID already exists!\n";
            return false;
        }
    }

    rooms.push_back(room);

    cout << "Room added successfully!\n";
    return true;
}

// Display all rooms
void RoomManager::displayAllRooms() const {

    if (rooms.empty()) {
        cout << "\nNo rooms available.\n";
        return;
    }

    for (const Room& room : rooms) {
        room.displayRoom();
    }
}

// Search room by ID
bool RoomManager::searchRoom(const string& id) const {

    for (const Room& room : rooms) {

        if (room.getRoomId() == id) {
            cout << "\nRoom found!\n";
            room.displayRoom();
            return true;
        }
    }

    cout << "\nRoom not found!\n";
    return false;
}

// Update room capacity
bool RoomManager::updateRoom(
    const string& id,
    int newCapacity
) {

    if (newCapacity <= 0) {
        cout << "Invalid capacity!\n";
        return false;
    }

    for (Room& room : rooms) {

        if (room.getRoomId() == id) {
            room.setCapacity(newCapacity);

            cout << "Room updated successfully!\n";
            return true;
        }
    }

    cout << "Room not found!\n";
    return false;
}

// Delete room
bool RoomManager::deleteRoom(const string& id) {

    for (auto it = rooms.begin();
         it != rooms.end(); ++it) {

        if (it->getRoomId() == id) {

            rooms.erase(it);

            cout << "Room deleted successfully!\n";
            return true;
        }
    }

    cout << "Room not found!\n";
    return false;
}

// Get total rooms
int RoomManager::getTotalRooms() const {
    return static_cast<int>(rooms.size());
}
