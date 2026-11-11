
#include "ResourceAllocator.h"

#include <limits>
#include <vector>

string ResourceAllocator::findBestRoom(
    const AllocationRequest& request,
    const RoomManager& roomManager,
    BookingManager& bookingManager
) const {

    vector<Room> rooms = roomManager.getAllRooms();

    string bestRoomId = "";
    int minimumUnusedCapacity = numeric_limits<int>::max();

    for (const Room& room : rooms) {

        // Check room capacity.
        if (room.getCapacity() < request.getRequiredCapacity()) {
            continue;
        }

        // Check projector requirement.
        if (request.getNeedsProjector() &&
            !room.getProjector()) {
            continue;
        }

        // Check computer requirement.
        if (request.getNeedsComputers() &&
            !room.getComputers()) {
            continue;
        }

        // Check booking conflicts.
        if (bookingManager.hasConflict(
                room.getRoomId(),
                request.getStartTime(),
                request.getEndTime())) {
            continue;
        }

        // Greedy Best-Fit: minimize unused capacity.
        int unusedCapacity =
            room.getCapacity() - request.getRequiredCapacity();

        if (unusedCapacity < minimumUnusedCapacity) {

            minimumUnusedCapacity = unusedCapacity;
            bestRoomId = room.getRoomId();
        }
    }

    return bestRoomId;
}
