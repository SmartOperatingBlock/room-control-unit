/*
 * Copyright (c) 2023 Smart Operating Block
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#ifndef __HEATING__
#define __HEATING__

#include "../../model/Actuator.h"
#include "../../model/PowerStatus.h"

/*
    Interface that models the Heating Module.
*/
class Heating: public Actuator {
    public:
        /*
            Turn the heating on/off based on the parameter.

            @param status if it is set to PowerStatus::ON then the heating will be turned on.
            Instead if it is set to PowerStatus::OFF then the heating will be turned off.
        */
        virtual void turn(PowerStatus status) = 0;
};

#endif