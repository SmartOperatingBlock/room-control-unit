/*
 * Copyright (c) 2023 Smart Operating Block
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#include "CoolingModule.h"
#include "../utils/Digital.h"

CoolingModule::CoolingModule(const String id, const int coolingPin): id(id), coolingPin(coolingPin) {
    pinMode(this->coolingPin, OUTPUT);

    this->turn(PowerStatus::OFF);
}

String CoolingModule::getId() {
    return this->id;
}

void CoolingModule::turn(const PowerStatus status) {
    Digital::turnPin(this->coolingPin, status);
}