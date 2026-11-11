
#ifndef ROOM_MANAGER_H
#define ROOM_MANAGER_H

#include "HashTable.h"
#include <string>

using namespace std;

class RoomManager {
private:
    HashTable rooms;

public:
    bool addRoom(const Room& room);

    void displayAllRooms() const;

    bool searchRoom(const string& id) const;

    bool updateRoom(
        const string& id,
        int newCapacity
    );

    bool deleteRoom(const string& id);

    int getTotalRooms() const;
};

#endif
