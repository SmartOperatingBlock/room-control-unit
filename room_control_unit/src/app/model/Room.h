/*
 * Copyright (c) 2023 Smart Operating Block
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#ifndef __ROOM__
#define __ROOM__

#include "Arduino.h"

/*
    Class that models a Room.
*/
class Room {
    public:
        /*
            Default constructor.
        */
        Room() {}
        
        /*
            Constructor.

            @param roomId the identificator of the room.
        */
        Room(const String roomId): roomId(roomId) {}

        /*
            Get the room id.

            @return the room id.
        */
        String getId() {
            return this->roomId;
        }

        bool operator==(Room& room) {
            return this->roomId == room.getId();
        }
    private:
        String roomId;
};

#endif