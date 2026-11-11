
#ifndef BOOKING_H
#define BOOKING_H

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Booking {
private:
    string bookingId;
    string roomId;
    string purpose;
    int startTime; // Minutes since midnight
    int endTime;

public:
    Booking(string id, string room, string reason,
            int start, int end)
        : bookingId(id),
          roomId(room),
          purpose(reason),
          startTime(start),
          endTime(end) {}

    string getBookingId() const {
        return bookingId;
    }

    string getRoomId() const {
        return roomId;
    }

    string getPurpose() const {
        return purpose;
    }

    int getStartTime() const {
        return startTime;
    }

    int getEndTime() const {
        return endTime;
    }

    static string formatTime(int minutes) {
        int hours = minutes / 60;
        int mins = minutes % 60;

        string result =
            (hours < 10 ? "0" : "") + to_string(hours);

        result += ":";
        result += (mins < 10 ? "0" : "") + to_string(mins);

        return result;
    }

    void displayBooking() const {
        cout << "\nBooking ID: " << bookingId;
        cout << "\nRoom ID: " << roomId;
        cout << "\nPurpose: " << purpose;
        cout << "\nStart: " << formatTime(startTime);
        cout << "\nEnd: " << formatTime(endTime);
        cout << "\n--------------------------\n";
    }
};

#endif
