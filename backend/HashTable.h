
#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "Room.h"
#include <vector>
#include <string>
#include <functional>

using namespace std;

class HashTable {
private:

    struct Node {
        Room data;
        Node* next;

        Node(const Room& room)
            : data(room), next(nullptr) {
        }       
    };

    vector<Node*> buckets;
    int capacity;
    int totalRooms;

    // Hash function
    int hashFunction(const string& key) const {

        unsigned long long hash = 0;

        for (char ch : key) {
            hash = (hash * 31 +
                    static_cast<unsigned char>(ch))
                    % capacity;
        }

        return static_cast<int>(hash);
    }

public:

    // Constructor
    explicit HashTable(int size = 101)
        : buckets(size, nullptr),
          capacity(size),
          totalRooms(0) {
    }

    // Prevent accidental shallow copying
    HashTable(const HashTable&) = delete;
    HashTable& operator=(const HashTable&) = delete;

    // Destructor
    ~HashTable() {
        clear();
    }

    // Insert a room
    bool insert(const Room& room) {

        int index = hashFunction(room.getRoomId());

        Node* current = buckets[index];

        // Check duplicate
        while (current != nullptr) {

            if (current->data.getRoomId()
                == room.getRoomId()) {
                return false;
            }

            current = current->next;
        }

        // Create new node
        Node* newNode = new Node(room);

        // Insert at beginning of linked list
        newNode->next = buckets[index];
        buckets[index] = newNode;

        totalRooms++;

        return true;
    }

    // Search for a room
    Room* search(const string& id) const {

        int index = hashFunction(id);

        Node* current = buckets[index];

        while (current != nullptr) {

            if (current->data.getRoomId() == id) {
                return &(current->data);
            }

            current = current->next;
        }

        return nullptr;
    }

    // Delete a room
    bool remove(const string& id) {

        int index = hashFunction(id);

        Node* current = buckets[index];
        Node* previous = nullptr;

        while (current != nullptr) {

            if (current->data.getRoomId() == id) {

                if (previous == nullptr) {
                    buckets[index] = current->next;
                }
                else {
                    previous->next = current->next;
                }

                delete current;
                totalRooms--;

                return true;
            }

            previous = current;
            current = current->next;
        }

        return false;
    }

    // Display all rooms
    void displayAll() const {

        for (Node* head : buckets) {

            Node* current = head;

            while (current != nullptr) {
                current->data.displayRoom();
                current = current->next;
            }
        }
    }

    // Get total number of rooms
    int size() const {
        return totalRooms;
    }

    // Check whether table is empty
    bool empty() const {
        return totalRooms == 0;
    }

    // Release allocated memory
    void clear() {

        for (Node*& head : buckets) {

            while (head != nullptr) {

                Node* temp = head;
                head = head->next;

                delete temp;
            }
        }

        totalRooms = 0;
    }

};

#endif
