/*
 * Copyright (c) 2023 Smart Operating Block
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#ifndef __PERSON_TRACKER__
#define __PERSON_TRACKER__

#include "../../model/Person.h"
#include "../../model/Room.h"

/*
    Interface that models a tracker device to track people.
*/
class PersonTracker {
    public:
        /*
            Check if a new person has been tracked.

            @return true if a new person is detected, false otherwise
        */
        virtual bool checkNewPerson() = 0;

        /*
            Get last Person detected.
            Use checkNewPerson() to refresh it.

            @return the last detected person.
        */
        virtual Person getLastPersonDetected() = 0;

        /*
            Get the room that is before the reader.

            @return the room or nullptr if there is no room before the reader.
        */
        virtual Room* getPreviousRoom() = 0;

        /*
            Get the room that is after the reader.

            @return the room or nullptr if there is no room after the reader.
        */
        virtual Room* getNextRoom() = 0;

        virtual ~PersonTracker() {}
};

#endif