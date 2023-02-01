/*
 * Copyright (c) 2023 Smart Operating Block
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#include "VentilationSystem.h"
#include "../utils/Digital.h"

VentilationSystem::VentilationSystem(const String id, const int ventilationPin): id(id), ventilationPin(ventilationPin) {
    pinMode(this->ventilationPin, OUTPUT);

    this->turn(PowerStatus::OFF);
    this->speedPercentage = 0;
}

String VentilationSystem::getId() {
    return this->id;
}

void VentilationSystem::turn(const PowerStatus status) {
    switch (status)
    {
        case PowerStatus::ON:
                Digital::turnPinPwm(this->ventilationPin, this->speedPercentage);    
            break;
        
        case PowerStatus::OFF:
                Digital::turnPin(this->ventilationPin, PowerStatus::OFF);
            break;
    }
}

void VentilationSystem::setSpeedPercentage(const int speedPercentage) {
    this->speedPercentage = speedPercentage;
}

