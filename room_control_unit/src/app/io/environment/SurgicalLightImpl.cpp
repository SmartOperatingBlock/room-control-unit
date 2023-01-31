/*
 * Copyright (c) 2023 Smart Operating Block
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#include "SurgicalLightImpl.h"

SurgicalLightImpl::SurgicalLightImpl(const int lightPin): LightImpl(lightPin) {}

void SurgicalLightImpl::turnOn(const int intensityPercentage) {
    LightImpl::turnOn(intensityPercentage);
}

void SurgicalLightImpl::turnOff() {
    LightImpl::turnOff();
}