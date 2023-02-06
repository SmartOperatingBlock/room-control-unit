/*
 * Copyright (c) 2023 Smart Operating Block
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#ifndef __PRESENCE_SENSOR__
#define __PRESENCE_SENSOR__

/*
    Interface that models a sensor used to detect presence.
*/
class PresenceSensor {
    public:
        /*
            Check current presence.

            @return true if presence is detected, false otherwise.
        */
        virtual bool checkPresence() = 0;
};

#endif