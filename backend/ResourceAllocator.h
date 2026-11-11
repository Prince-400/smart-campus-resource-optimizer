
#ifndef RESOURCE_ALLOCATOR_H
#define RESOURCE_ALLOCATOR_H

#include "RoomManager.h"
#include "BookingManager.h"
#include "AllocationRequest.h"

#include <string>

using namespace std;

class ResourceAllocator {
public:
    // Returns the selected room ID.
    // Returns an empty string if no suitable room exists.
    string findBestRoom(
        const AllocationRequest& request,
        const RoomManager& roomManager,
        BookingManager& bookingManager
    ) const;
};

#endif
