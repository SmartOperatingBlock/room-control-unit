/*
 * Copyright (c) 2023 Smart Operating Block
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#ifndef __TEMPERATURE_SENSOR__
#define __TEMPERATURE_SENSOR__

#include "../../model/Temperature.h"

/*
    Interface to model a temperature sensor.
*/
class TemperatureSensor {
    public:
        /*
            Get the current temperature.

            @return the current temperature.
        */
        virtual Temperature getTemperature() = 0;
};

#endif