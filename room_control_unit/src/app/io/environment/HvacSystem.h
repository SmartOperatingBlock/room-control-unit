/*
 * Copyright (c) 2023 Smart Operating Block
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#ifndef __HVAC_SYSTEM__
#define __HVAC_SYSTEM__

#include "../../logic/baseio/Hvac.h"

/*
    Implementation of an Hvac system inside a room.
*/
class HvacSystem: public Hvac {
    public:
        /*
            Constructor.

            @param ventilationPin the pin of the ventilation.
            @param heatingPin the pin of the heating.
            @param coolingPin the pin of the cooling.
        */
        HvacSystem(int ventilationPin, int heatingPin, int coolingPin);

        void turnVentilation(PowerStatus state);
        void setVentilationSpeed(float speedPercentage);
        int getVentilationSpeedPercentage();
        void turnHeating(PowerStatus state);
        void turnCooling(PowerStatus state);

    private:
        const int ventilationPin;
        int ventilationSpeed;
        const int heatingPin;
        const int coolingPin;
};


#endif

