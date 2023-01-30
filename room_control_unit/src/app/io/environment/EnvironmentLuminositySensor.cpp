/*
 * Copyright (c) 2023 Smart Operating Block
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#include "EnvironmentLuminositySensor.h"
#include "Arduino.h"

EnvironmentLuminositySensor::EnvironmentLuminositySensor(const int pin): pin(pin) {
    pinMode(this->pin, INPUT);
}

float EnvironmentLuminositySensor::getLuminosity() {
    uint16_t readData = analogRead(this->pin);
    float voltageOnResistor = (float) readData / ADC_RESOLUTION * VOLTAGE; // Compute the voltage on the resistor
    float voltageOnLdr = VOLTAGE - voltageOnResistor; // Compute the voltage on the photoresistor sensor
    float ldrResistance = voltageOnLdr / voltageOnResistor * RESISTANCE; // Compute the resistance of the photoresistor (it depends on the current light in the environment)
    return LUX_CALC_SCALAR * pow(ldrResistance, LUX_CALC_EXPONENT); // Convert the resistance in lumen and return
}