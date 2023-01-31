/*
 * Copyright (c) 2023 Smart Operating Block
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#ifndef __ROOM__
#define __ROOM__

/*
    Class that models a Room.
*/
class Room {
    public:
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
    private:
        const String roomId;
};

#endif