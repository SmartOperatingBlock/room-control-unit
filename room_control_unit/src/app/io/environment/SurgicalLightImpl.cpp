/*
 * Copyright (c) 2023 Smart Operating Block
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#include "SurgicalLightImpl.h"

SurgicalLightImpl::SurgicalLightImpl(const String id, const int lightPin): LightImpl(id, lightPin) {}

void SurgicalLightImpl::turnOn(Percentage intensityPercentage) {
    LightImpl::turnOn(intensityPercentage);
}

void SurgicalLightImpl::turnOff() {
    LightImpl::turnOff();
}

String SurgicalLightImpl::getId() {
    return LightImpl::getId();
}