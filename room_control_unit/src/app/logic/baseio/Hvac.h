/*
 * Copyright (c) 2023 Smart Operating Block
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#ifndef __HVAC__
#define __HVAC__

#include "PowerStatus.h"

/*
    Interface for modeling the HVAC System.
*/
class Hvac {
    public:
        /*
            Turn the ventilation on/off.

            @param state if it is set to PowerStatus::ON then the ventilation will be turned on.
            Instead if it is set to PowerStatus::OFF then the ventilation will be turned off.
        */
        virtual void turnVentilation(PowerStatus state) = 0;

        /*
            Set che ventilation speed.

            @param speedPercentage the speed percentage of the ventilation.
        */
        virtual void setVentilationSpeed(float speedPercentage) = 0;

        /*
            Get the current ventilation speed percentage.

            @return the current ventilation speed percentage.
        */
        virtual int getVentilationSpeedPercentage() = 0;

        /*
            Turn the heating on/off based on the parameter.

            @param state if it is set to PowerStatus::ON then the heating will be turned on.
            Instead if it is set to PowerStatus::OFF then the heating will be turned off.
        */
        virtual void turnHeating(PowerStatus state) = 0;

        /*
            Turn the cooling on/off based on the parameter.

            @param state if it is set to PowerStatus::ON then the cooling will be turned on.
            Instead if it is set to PowerStatus::OFF then the cooling will be turned off.
        */
        virtual void turnCooling(PowerStatus state) = 0;
};

#endif
