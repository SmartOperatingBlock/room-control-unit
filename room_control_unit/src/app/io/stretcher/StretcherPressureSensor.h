/*
 * Copyright (c) 2023 Smart Operating Block
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#ifndef __STRETCHER_PRESSURE_SENSOR__
#define __STRETCHER_PRESSURE_SENSOR__

#include "../base/Button.h"

/*
    Stretcher pressure sensor that is need to detect if a patient is on a stretcher.
*/
class StretcherPressureSensor: public Button {
    public:
        /*
            Simple constructor.

            @param pin the pin to which the stretcher pressure sensor is attached. 
        */
        StretcherPressureSensor(int pin);
        bool isPressed();
    private:
        const int pin; // Pin to which the stretcher pressure sensor is attached.
};

#endif