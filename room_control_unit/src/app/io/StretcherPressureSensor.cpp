/*
 * Copyright (c) 2023 Smart Operating Block
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#include "StretcherPressureSensor.h"
#include "Arduino.h"

StretcherPressureSensor::StretcherPressureSensor(const int pin): pin(pin) {
    pinMode(this->pin, INPUT);
}

bool StretcherPressureSensor::isPressed() {
    return digitalRead(this->pin) == HIGH;
}