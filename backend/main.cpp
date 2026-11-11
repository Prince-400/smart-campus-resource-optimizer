
#include <iostream>
#include <string>
#include <limits>

#include "RoomManager.h"

using namespace std;

int main() {

    RoomManager manager;

    // Add some sample rooms
    manager.addRoom(
        Room("R101", "Lecture Hall 1",
             "Classroom", 60, true, false)
    );

    manager.addRoom(
        Room("R102", "Lecture Hall 2",
             "Classroom", 40, true, false)
    );

    manager.addRoom(
        Room("L201", "Computer Lab 1",
             "Laboratory", 50, true, true)
    );

    manager.addRoom(
        Room("L202", "Electronics Lab",
             "Laboratory", 30, false, true)
    );

    int choice;

    do {

        cout << "\n================================\n";
        cout << " SMART CAMPUS RESOURCE OPTIMIZER\n";
        cout << "================================\n";

        cout << "1. Add Room\n";
        cout << "2. Display All Rooms\n";
        cout << "3. Search Room\n";
        cout << "4. Update Room Capacity\n";
        cout << "5. Delete Room\n";
        cout << "6. Total Room Count\n";
        cout << "0. Exit\n";

        cout << "\nEnter your choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input!\n";
            cin.clear();
            cin.ignore(
                numeric_limits<streamsize>::max(),
                '\n'
            );
            continue;
        }

        cin.ignore(
            numeric_limits<streamsize>::max(),
            '\n'
        );

        switch (choice) {

            case 1: {
                string id, name, type;
                int capacity;
                int projector, computers;

                cout << "Enter Room ID: ";
                getline(cin, id);

                cout << "Enter Room Name: ";
                getline(cin, name);

                cout << "Enter Room Type: ";
                getline(cin, type);

                cout << "Enter Capacity: ";
                if (!(cin >> capacity) || capacity <= 0) {
                    cout << "Invalid capacity!\n";
                    cin.clear();
                    cin.ignore(
                        numeric_limits<streamsize>::max(),
                        '\n'
                    );
                    break;
                }

                cout << "Has Projector? (1=Yes, 0=No): ";
                if (!(cin >> projector) ||
                    (projector != 0 && projector != 1)) {
                    cout << "Invalid input!\n";
                    cin.clear();
                    cin.ignore(
                        numeric_limits<streamsize>::max(),
                        '\n'
                    );
                    break;
                }

                cout << "Has Computers? (1=Yes, 0=No): ";
                if (!(cin >> computers) ||
                    (computers != 0 && computers != 1)) {
                    cout << "Invalid input!\n";
                    cin.clear();
                    cin.ignore(
                        numeric_limits<streamsize>::max(),
                        '\n'
                    );
                    break;
                }

                cin.ignore(
                    numeric_limits<streamsize>::max(),
                    '\n'
                );

                manager.addRoom(
                    Room(
                        id, name, type, capacity,
                        projector == 1,
                        computers == 1
                    )
                );

                break;
            }

            case 2:
                manager.displayAllRooms();
                break;

            case 3: {
                string id;

                cout << "Enter Room ID: ";
                getline(cin, id);

                manager.searchRoom(id);
                break;
            }

            case 4: {
                string id;
                int capacity;

                cout << "Enter Room ID: ";
                getline(cin, id);

                cout << "Enter New Capacity: ";

                if (!(cin >> capacity)) {
                    cout << "Invalid capacity!\n";
                    cin.clear();
                    cin.ignore(
                        numeric_limits<streamsize>::max(),
                        '\n'
                    );
                    break;
                }

                cin.ignore(
                    numeric_limits<streamsize>::max(),
                    '\n'
                );

                manager.updateRoom(id, capacity);
                break;
            }

            case 5: {
                string id;

                cout << "Enter Room ID: ";
                getline(cin, id);

                manager.deleteRoom(id);
                break;
            }

            case 6:
                cout << "Total Rooms: "
                     << manager.getTotalRooms() << "\n";
                break;

            case 0:
                cout << "Thank you for using Smart Campus!\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 0);

    return 0;
}
