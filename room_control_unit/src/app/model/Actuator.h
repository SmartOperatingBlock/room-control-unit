/*
 * Copyright (c) 2023 Smart Operating Block
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#ifndef __ACTUATOR__
#define __ACTUATOR__

#include "Arduino.h"

/*
    Interface that model the base information about an Actuator.
*/
class Actuator {
    public:
        /*
            Each Actuator has an own identificator.
            With this method it is possible to get the actuator id.

            @return the id.
        */
        virtual String getId();
};

#endif