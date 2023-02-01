/*
 * Copyright (c) 2023 Smart Operating Block
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#ifndef __VENTILATION_SYSTEM__
#define __VENTILATION_SYSTEM__

#include "../../logic/baseio/Ventilation.h"
#include "Arduino.h"

class VentilationSystem: public Ventilation {
    public:
        /*
            Constructor.

            @param id the identificator of the ventilation system.
            @param ventilationPin the pin to which the ventilation is attached to.
        */
        VentilationSystem(String id, int ventilationPin);

        void turn(PowerStatus status);
        void setSpeedPercentage(int speedPercentage);
        String getId();

    private:
        const String id;
        const int ventilationPin;
        int speedPercentage;
};

#endif