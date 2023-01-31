/*
 * Copyright (c) 2023 Smart Operating Block
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#ifndef __SURGICAL_LIGHT_IMPL__
#define __SURGICAL_LIGHT_IMPL__

#include "../../logic/baseio/SurgicalLight.h"
#include "LightImpl.h"

/*
    Implementation of a Surgical Light.
*/
class SurgicalLightImpl: public SurgicalLight, public LightImpl {
    public:
        /*
            Constructor.

            @param pin the pin of the surgical light.
        */
        SurgicalLightImpl(int lightPin);
        void turnOn(int intensityPercentage);
        void turnOff();
};

#endif