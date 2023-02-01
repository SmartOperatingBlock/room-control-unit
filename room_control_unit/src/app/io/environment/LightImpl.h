/*
 * Copyright (c) 2023 Smart Operating Block
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#ifndef __LIGHT_IMPL__
#define __LIGHT_IMPL__

#include "../../logic/baseio/Light.h"

class LightImpl: public Light {
    public:
        /*
            Constructor.

            @param id the identificator of the light.
            @param pin the pin of the light to control.
        */
        LightImpl(String id, int lightPin);
        void turnOn(Percentage intensityPercentage);
        void turnOff();
        String getId();
        virtual ActuatorType getType();

    private:
        const String id;
        const int lightPin;
};

#endif