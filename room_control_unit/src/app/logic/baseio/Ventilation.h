/*
 * Copyright (c) 2023 Smart Operating Block
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#ifndef __VENTILATION__
#define __VENTILATION__

#include "../../model/Actuator.h"
#include "../../model/PowerStatus.h"

/*
    Interface that models the Ventilation System inside a Room.
*/
class Ventilation: public Actuator {
    public:
        /*
            Change state of the ventilation.
            Turn it on/off based on the status parameter.

            @param status the status to set. If it is set to PowerStatus::ON then the ventilation will be turned on.
            Instead if it is set to PowerStatus::OFF then the ventilation will be turned off.
        */
        virtual void turn(PowerStatus status) = 0;

        /*
            Set che ventilation speed percentage.

            @param speedPercentage the speed percentage of the ventilation.
        */
        virtual void setSpeedPercentage(int speedPercentage) = 0;
};

#endif