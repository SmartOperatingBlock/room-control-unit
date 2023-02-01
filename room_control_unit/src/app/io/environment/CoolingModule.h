/*
 * Copyright (c) 2023 Smart Operating Block
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#ifndef __COOLING_MODULE__
#define __COOLING_MODULE__

#include "../../logic/baseio/Cooling.h"
#include "Arduino.h"

class CoolingModule: public Cooling {
    public:
        /*
            Constructor.

            @param id the identificator of the cooling module.
            @param coolingPin the pin to which the cooling module is attached to.
        */
        CoolingModule(String id, int coolingPin);

        void turn(PowerStatus status);
        String getId();
        ActuatorType getType();

    private:
        const String id;
        const int coolingPin;
};

#endif