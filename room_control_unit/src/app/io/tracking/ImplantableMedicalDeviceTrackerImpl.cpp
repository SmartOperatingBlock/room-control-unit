/*
 * Copyright (c) 2023 Smart Operating Block
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#include "ImplantableMedicalDeviceTrackerImpl.h"
#include "rfid/RfidTagReader.h"

#define DEVICE_BLOCK 20
#define SPLIT_CHAR "#"

ImplantableMedicalDeviceTrackerImpl::ImplantableMedicalDeviceTrackerImpl(const int readerPin, const int resetPin) {
    this->tagReader = new RfidTagReader(readerPin, resetPin);
    this->lastImplantableMedicalDeviceDetected = nullptr;
}

ImplantableMedicalDeviceTrackerImpl::~ImplantableMedicalDeviceTrackerImpl() {
    delete this->tagReader;
    delete this->lastImplantableMedicalDeviceDetected;
}

bool ImplantableMedicalDeviceTrackerImpl::checkNewDevice() {
    if(this->tagReader->isTagAvailable()) {
        const String data = this->tagReader->readBlock(DEVICE_BLOCK);
        const int splitIndex = data.indexOf(SPLIT_CHAR);
        const String deviceID = data.substring(0, splitIndex);
        const String rawDeviceType = data.substring(splitIndex + 1);

        if(deviceID != "" && rawDeviceType != "") {
            const ImplantableMedicalDeviceType deviceType = ImplantableMedicalDeviceType(rawDeviceType.toInt());
            delete this->lastImplantableMedicalDeviceDetected; // clean memory
            this->lastImplantableMedicalDeviceDetected = new ImplantableMedicalDevice(deviceID, deviceType);
            return true;
        }
    }
    return false;
}

ImplantableMedicalDevice ImplantableMedicalDeviceTrackerImpl::getLastDeviceDetected() {
    // return a new stack instance so it will not be deleted by the class.
    return ImplantableMedicalDevice(this->lastImplantableMedicalDeviceDetected->getId(), this->lastImplantableMedicalDeviceDetected->getType());
}