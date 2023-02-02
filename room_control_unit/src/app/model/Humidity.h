/*
 * Copyright (c) 2023 Smart Operating Block
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#ifndef __HUMIDITY__
#define __HUMIDITY__

#include "Percentage.h"

/*
    Class that models the humidity concepts.
*/
class Humidity {
    public:
        /*
            Constructor.

            @param percentage the value of humidity percentage.
        */
        Humidity(const Percentage percentage): percentage(percentage) {}

        /*
            Get the value of humidity percentage.

            @return the humidity percentage.
        */
        Percentage getHumidityPercentage() {
            return this->percentage;
        }

    private:
        const Percentage percentage;
};

#endif