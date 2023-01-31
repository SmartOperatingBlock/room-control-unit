/*
 * Copyright (c) 2023 Smart Operating Block
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#include "TemperatureHumiditySensor.h"
#include "Arduino.h"

#define MAX_POLLING_PERIOD_MS 1000

TemperatureHumiditySensor::TemperatureHumiditySensor(const uint8_t pin): pin(pin) {}

Temperature TemperatureHumiditySensor::getTemperature() {
    this->readNewData();
    return Temperature(this->sensor.temperature, TemperatureUnit::CELSIUS);
}

Humidity TemperatureHumiditySensor::getHumidity() {
    this->readNewData();
    return Humidity(this->sensor.humidity);
}

void TemperatureHumiditySensor::readNewData() {
    unsigned long readTime = millis();
    if(readTime - this->lastRead >= MAX_POLLING_PERIOD_MS) {
        this->sensor.read11(this->pin);
        this->lastRead = readTime;
    }
}