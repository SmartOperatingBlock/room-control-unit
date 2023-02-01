/*
 * Copyright (c) 2023 Smart Operating Block
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#ifndef __HEATING_MODULE__
#define __HEATING_MODULE__

#include "../../logic/baseio/Heating.h"
#include "Arduino.h"

class HeatingModule: public Heating {
    public:
        /*
            Constructor.

            @param id the identificator of the heating module.
            @param heatingPin the pin to which the heating module is attached to.
        */
        HeatingModule(String id, int heatingPin);

        void turn(PowerStatus status);
        String getId();

    private:
        const String id;
        const int heatingPin;
};

#endif