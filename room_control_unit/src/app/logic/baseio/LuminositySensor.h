/*
 * Copyright (c) 2023 Smart Operating Block
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#ifndef __LUMINOSITY_SENSOR__
#define __LUMINOSITY_SENSOR__

#include "../../model/Luminosity.h"

/*
    Interface that model a luminosity sensor.
*/
class LuminositySensor {
    public:
        /*
            Get luminosity.

            @return the luminosity.
        */
        virtual Luminosity getLuminosity() = 0;
};

#endif