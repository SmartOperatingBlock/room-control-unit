/*
 * Copyright (c) 2023 Smart Operating Block
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#include "VentilationSystem.h"
#include "../utils/Digital.h"

VentilationSystem::VentilationSystem(const String id, const int ventilationPin): id(id), ventilationPin(ventilationPin), speedPercentage(0) {
    pinMode(this->ventilationPin, OUTPUT);
    this->currentStatus = PowerStatus::OFF;
    this->turn(PowerStatus::OFF);
}

String VentilationSystem::getId() {
    return this->id;
}

ActuatorType VentilationSystem::getType() {
    return ActuatorType::VENTILATION;
}

void VentilationSystem::turn(const PowerStatus status) {
    this->currentStatus = status;
    switch (status)
    {
        case PowerStatus::ON:
                Digital::turnPinPwm(this->ventilationPin, map(this->speedPercentage.get(), 0, 100, 0, 255));
            break;
        
        case PowerStatus::OFF:
                Digital::turnPin(this->ventilationPin, PowerStatus::OFF);
            break;
    }
}

void VentilationSystem::setSpeedPercentage(Percentage speedPercentage) {
    this->speedPercentage = speedPercentage;
    if(this->currentStatus == PowerStatus::ON) {
        this->turn(this->currentStatus);
    }
}

Percentage VentilationSystem::getSpeedPercentage() {
    return this->speedPercentage;
}

PowerStatus VentilationSystem::getStatus() {
    return this->currentStatus;
}

