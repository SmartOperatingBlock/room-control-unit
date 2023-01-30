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

/*
    Interface that model a tracker to track people.
*/
class PersonTracker {
    public:
        /*
            Check if a new person is being tracked.

            @return true if a new person is detected, false otherwise
        */
        virtual bool checkNewPerson() = 0;

        /*
            Get last Person detected.
            Use checkNewPerson() to refresh it.

            @return the last detected person.
        */
        virtual Person getLastPersonDetected() = 0;
};

#endif