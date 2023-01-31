/*
 * Copyright (c) 2023 Smart Operating Block
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#ifndef __IMPLANTABLE_MEDICAL_DEVICE_TRACKER_IMPL__
#define __IMPLANTABLE_MEDICAL_DEVICE_TRACKER_IMPL__

#include "../base/ImplantableMedicalDeviceTracker.h"
#include "rfid/TagReader.h"

/*
    Implementation of a Implantable medical device Tracker inside the Operating Room.
*/
class ImplantableMedicalDeviceTrackerImpl: public ImplantableMedicalDeviceTracker {
    public:
        /*
            Constructor.

            @param readerPin the tag reader pin.
            @param resetPin the pin to reset the tag reader.
        */
        ImplantableMedicalDeviceTrackerImpl(int readerPin, int resetPin);
        
        /*
            Deconstructor to clean memory.
        */
        ~ImplantableMedicalDeviceTrackerImpl();
        bool checkNewDevice();
        ImplantableMedicalDevice getLastDeviceDetected();

    private:
        TagReader* tagReader;
        ImplantableMedicalDevice* lastImplantableMedicalDeviceDetected;

};

#endif