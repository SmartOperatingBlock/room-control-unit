/*
 * Copyright (c) 2023 Smart Operating Block
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#ifndef __COOLING__
#define __COOLING__

#include "../../model/Actuator.h"
#include "../../model/PowerStatus.h"

/*
    Interface that models the Cooling Module.
*/
class Cooling: public Actuator {
    public:
        /*
            Turn the cooling on/off based on the parameter.

            @param status if it is set to PowerStatus::ON then the cooling will be turned on.
            Instead if it is set to PowerStatus::OFF then the cooling will be turned off.
        */
        virtual void turn(PowerStatus status) = 0;
};

#endif