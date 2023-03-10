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

Luminosity EnvironmentLuminositySensor::getLuminosity() {
    const uint16_t readData = analogRead(this->pin);
    const float voltageOnResistor = (float) readData / ADC_RESOLUTION * VOLTAGE; // Compute the voltage on the resistor
    const float voltageOnLdr = VOLTAGE - voltageOnResistor; // Compute the voltage on the photoresistor sensor
    const float ldrResistance = voltageOnLdr / voltageOnResistor * RESISTANCE; // Compute the resistance of the photoresistor (it depends on the current light in the environment)
    return Luminosity(LUX_CALC_SCALAR * pow(ldrResistance, LUX_CALC_EXPONENT), LuminosityUnit::LUX); // Convert the resistance in lux and return
}