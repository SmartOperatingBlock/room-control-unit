/*
 * Copyright (c) 2023 Smart Operating Block
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#ifndef __HUMIDITY_SENSOR__
#define __HUMIDITY_SENSOR__

#include "../../model/Humidity.h"

/*
    Interface to model an humidity sensor.
*/
class HumiditySensor {
    public:
        /*
            Get the current humidity.

            @return the current humidity.
        */
        virtual Humidity getHumidity() = 0;
};

#endif