/*
 * Copyright (c) 2023 Smart Operating Block
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#include "LightImpl.h"
#include "Arduino.h"
#include "../utils/Digital.h"

LightImpl::LightImpl(const int lightPin): lightPin(lightPin) {
    pinMode(lightPin, OUTPUT);
}

void LightImpl::turnOn(const int intensityPercentage) {
    Digital::turnPinPwm(this->lightPin, map(intensityPercentage, 0, 100, 0, 255));
}

void LightImpl::turnOff() {
    Digital::turnPin(this->lightPin, PowerStatus::OFF);
}

