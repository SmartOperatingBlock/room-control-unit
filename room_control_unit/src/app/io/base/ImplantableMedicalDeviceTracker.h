/*
 * Copyright (c) 2023 Smart Operating Block
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#ifndef __IMPLANTABLE_MEDICAL_DEVICE_TRACKER__
#define __IMPLANTABLE_MEDICAL_DEVICE_TRACKER__

#include "../../model/ImplantableMedicalDevice.h"

/*
    Interface that model a tracker to track implantable medical devices.
*/
class ImplantableMedicalDeviceTracker {
    public:
        /*
            Check if a new implantable medical device is being tracked.

            @return true if a new implantable medical device is detected, false otherwise
        */
        virtual bool checkNewDevice() = 0;

        /*
            Get last implantable medical device detected.
            Use checkNewDevice() to refresh it.

            @return the last detected device.
        */
        virtual ImplantableMedicalDevice getLastDeviceDetected() = 0;
};

#endif