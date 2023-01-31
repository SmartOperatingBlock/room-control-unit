/*
 * Copyright (c) 2023 Smart Operating Block
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#ifndef __PEOPLE_PRESENCE_SENSOR__
#define __PEOPLE_PRESENCE_SENSOR__

#include "../../logic/baseio/PresenceSensor.h"

class PeoplePresenceSensor: public PresenceSensor {
    public:
        /*
            Constructor.

            @param pin pin to which the presence sensor is attached to.
        */
        PeoplePresenceSensor(int pin);
        bool checkPresence();

    private:
        const int pin; // pin to which the presence sensor is attached to.
};

#endif