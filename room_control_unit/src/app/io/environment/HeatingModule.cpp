/*
 * Copyright (c) 2023 Smart Operating Block
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#include "HeatingModule.h"
#include "../utils/Digital.h"

HeatingModule::HeatingModule(const String id, const int heatingPin): id(id), heatingPin(heatingPin) {
    pinMode(this->heatingPin, OUTPUT);

    this->turn(PowerStatus::OFF);
}

String HeatingModule::getId() {
    return this->id;
}

ActuatorType HeatingModule::getType() {
    return ActuatorType::HEATING;
}

void HeatingModule::turn(const PowerStatus status) {
    Digital::turnPin(this->heatingPin, status);
}