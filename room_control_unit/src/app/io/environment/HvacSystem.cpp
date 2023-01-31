/*
 * Copyright (c) 2023 Smart Operating Block
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */


#include "HvacSystem.h"
#include "Arduino.h"
#include "../utils/Digital.h"

HvacSystem::HvacSystem(const String id, const int ventilationPin, const int heatingPin, const int coolingPin): 
    id(id), ventilationPin(ventilationPin), heatingPin(heatingPin), coolingPin(coolingPin) {
        pinMode(ventilationPin, OUTPUT);
        pinMode(heatingPin, OUTPUT);
        pinMode(coolingPin, OUTPUT);

        this->turnVentilation(PowerStatus::OFF);
        this->turnHeating(PowerStatus::OFF);
        this->turnCooling(PowerStatus::OFF);
}

void HvacSystem::turnVentilation(const PowerStatus state) {
    switch (state)
    {
        case PowerStatus::ON:
                Digital::turnPinPwm(this->ventilationPin, this->ventilationSpeed);
            break;
        
        case PowerStatus::OFF:
                Digital::turnPinPwm(this->ventilationPin, 0);
            break;
    }
}

void HvacSystem::setVentilationSpeed(const float speedPercentage) {
    this->ventilationSpeed = map(speedPercentage, 0, 100, 0, 255);
}

int HvacSystem::getVentilationSpeedPercentage() {
    return map(this->ventilationSpeed, 0, 255, 0, 100);
}

void HvacSystem::turnHeating(const PowerStatus state) {
    Digital::turnPin(this->heatingPin, state);
}

void HvacSystem::turnCooling(const PowerStatus state) {
    Digital::turnPin(this->coolingPin, state);
}

String HvacSystem::getId() {
    return this->id;
}