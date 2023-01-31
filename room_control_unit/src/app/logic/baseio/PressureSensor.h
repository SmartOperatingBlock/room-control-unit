/*
 * Copyright (c) 2023 Smart Operating Block
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#ifndef __PRESSURE_SENSOR__
#define __PRESSURE_SENSOR__

/*
* Interface for defining buttons-like pressure sensor.
*/
class PressureSensor {
    public:
        /*
            @return true if the sensor is pressed, false otherwise.
        */
        virtual bool isPressed() = 0;
};

#endif