/*
 * Copyright (c) 2023 Smart Operating Block
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#ifndef __LIGHT__
#define __LIGHT__

#include "../../model/Actuator.h"

/*
    Interface that models a light.
*/
class Light: public Actuator {
    /*
        Turn the light on with an intensity.

        @param intensityPercentage the percentage of intensity with which turn on the light.
    */
    virtual void turnOn(int intensityPercentage) = 0;

    /*
        Turn the light off.
    */
    virtual void turnOff() = 0;
};

#endif