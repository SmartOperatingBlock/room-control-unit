/*
 * Copyright (c) 2023 Smart Operating Block
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#ifndef __IMPLANTABLE_MEDICAL_DEVICE__
#define __IMPLANTABLE_MEDICAL_DEVICE__

#include "Arduino.h"

/*
    This enum models the type of an implantable medical device.
*/
enum class DeviceType {
    /*
        Pace maker.
    */
    PACE_MAKER
};

/*
    This class model the necessary information about an implantable medical device.
*/
class ImplantableMedicalDevice {
    public:
        /*
            Constructor.

            @param id the id of the implantable medical device.
            @param type the type of the implantable medical device.
        */
        ImplantableMedicalDevice(const String id, const DeviceType type): id(id), type(type) {}

        /*
            Get the Implantable medical device's ID.

            @return the id.
        */
        String getId() {
            return this->id;
        }

        /*
            Get the Implantable medical device's type.

            @return the type.
        */
        DeviceType getType() {
            return this->type;
        }
    
    private:
        const String id;
        const DeviceType type;
};

#endif