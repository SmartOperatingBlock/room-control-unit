/*
 * Copyright (c) 2023 Smart Operating Block
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#ifndef __ENV_LUMINOSITY_SENSOR
#define __ENV_LUMINOSITY_SENSOR

#include "../../logic/baseio/LuminositySensor.h"
#include "../../model/Luminosity.h"

#define ADC_RESOLUTION 1023
#define VOLTAGE 5
#define RESISTANCE 10000
#define LUX_CALC_SCALAR 12518931
#define LUX_CALC_EXPONENT -1.405

/*
    Environmental luminosity sensor.
    It is used to determine the luminosity inside an environement.
*/
class EnvironmentLuminositySensor: public LuminositySensor {
    public:
        /*
            Constructor.

            @param pin the pin to which the sensor is attached to.
        */
        EnvironmentLuminositySensor(int pin);
        Luminosity getLuminosity();

    private:
        const int pin; // the pin to which the sensor is attached to.


};

#endif