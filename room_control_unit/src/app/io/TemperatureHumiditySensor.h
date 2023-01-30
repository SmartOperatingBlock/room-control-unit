/*
 * Copyright (c) 2023 Smart Operating Block
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#ifndef __TEMPERATURE_HUMIDITY_SENSOR__
#define __TEMPERATURE_HUMIDITY_SENSOR__

#include "TemperatureSensor.h"
#include "HumiditySensor.h"
#include <dht.h>

/*
    Class that model the temperature and humidity sensor used within the Operating Block.
*/
class TemperatureHumiditySensor: public TemperatureSensor, public HumiditySensor {
    public:
        TemperatureHumiditySensor(uint8_t pin);

        /*
            Get the current temperature.

            @return the current temperature.  
        */
        float getTemperature();

        /*
            Get the current humidity.

            @return the current humidity.  
        */
        float getHumidity();
    
    private:
        const uint8_t pin; // Pin to which the temperature and humidity sensor is attached.
        dht sensor; // temperature and humidity sensor
        unsigned long lastRead;

        /*
            Read new data from dht sensor.
        */
        void readNewData();
};

#endif