
#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <string>

using namespace std;

class Room {
private:
    string roomId;
    string roomName;
    string roomType;
    int capacity;
    bool hasProjector;
    bool hasComputers;

public:
    // Constructor
    Room(
        string id,
        string name,
        string type,
        int cap,
        bool projector,
        bool computers
    ) {
        roomId = id;
        roomName = name;
        roomType = type;
        capacity = cap;
        hasProjector = projector;
        hasComputers = computers;
    }

    // Getters
    string getRoomId() const {
        return roomId;
    }

    string getRoomName() const {
        return roomName;
    }

    string getRoomType() const {
        return roomType;
    }

    int getCapacity() const {
        return capacity;
    }

    bool getProjector() const {
        return hasProjector;
    }

    bool getComputers() const {
        return hasComputers;
    }

    // Setters
    void setRoomName(string name) {
        roomName = name;
    }

    void setCapacity(int cap) {
        capacity = cap;
    }

    void setProjector(bool value) {
        hasProjector = value;
    }

    void setComputers(bool value) {
        hasComputers = value;
    }

    // Display room information
    void displayRoom() const {
        cout << "\nRoom ID: " << roomId;
        cout << "\nRoom Name: " << roomName;
        cout << "\nRoom Type: " << roomType;
        cout << "\nCapacity: " << capacity;
        cout << "\nProjector: "
             << (hasProjector ? "Yes" : "No");
        cout << "\nComputers: "
             << (hasComputers ? "Yes" : "No");
        cout << "\n-----------------------------\n";
    }
};

#endif
