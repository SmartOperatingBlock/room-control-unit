/*
 * Copyright (c) 2023 Smart Operating Block
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#ifndef __ROOM_EQUIPMENT__
#define __ROOM_EQUIPMENT__

#include "../../../model/Room.h"

/*
    Class that wrap a tool used inside a room.

    @tparm T the type of the tool.
*/
template<typename T>
class RoomEquipment {
    public:
        /*
            Constructor.

            @param tool the tool in use.
            @param room the room in which the tool is used.
        */
        RoomEquipment(T* const tool, Room* const room): tool(tool), room(room) {}

        /*
            Get the used tool.

            @return the tool.
        */
        T* getTool() {
            return this->tool;
        }

        /*
            Get the room in which the tool is used.

            @return the room.
        */
        Room* getRoom() {
            return this->room;
        }
    private:
        T* const tool;
        Room* const room;

};

#endif