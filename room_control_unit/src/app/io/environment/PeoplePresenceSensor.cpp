/*
 * Copyright (c) 2023 Smart Operating Block
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#include "PeoplePresenceSensor.h"
#include "Arduino.h"

PeoplePresenceSensor::PeoplePresenceSensor(const int pin): pin(pin) {
    pinMode(this->pin, INPUT);
}

bool PeoplePresenceSensor::checkPresence() {
    return digitalRead(this->pin) == HIGH;
}
