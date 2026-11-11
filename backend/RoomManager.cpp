
#include "RoomManager.h"

// Add a new room
bool RoomManager::addRoom(const Room& room) {

    if (rooms.insert(room)) {
        cout << "Room " <<  room.getRoomId() << " added successfully!\n";
        return true;
    }

    cout << "Room " <<  room.getRoomId() << " ID already exists!\n";
    return false;
}

// Display all rooms
void RoomManager::displayAllRooms() const {

    if (rooms.empty()) {
        cout << "\nNo rooms available.\n";
        return;
    }

    rooms.displayAll();
}

// Search room by ID
bool RoomManager::searchRoom(const string& id) const {

    Room* room = rooms.search(id);

    if (room != nullptr) {
        cout << "\nRoom found!\n";
        room->displayRoom();
        return true;
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

    Room* room = rooms.search(id);

    if (room == nullptr) {
        cout << "Room not found!\n";
        return false;
    }

    room->setCapacity(newCapacity);

    cout << "Room updated successfully!\n";
    return true;
}

// Delete room
bool RoomManager::deleteRoom(const string& id) {

    if (rooms.remove(id)) {
        cout << "Room deleted successfully!\n";
        return true;
    }

    cout << "Room not found!\n";
    return false;
}

// Get total rooms
int RoomManager::getTotalRooms() const {
    return rooms.size();
}
