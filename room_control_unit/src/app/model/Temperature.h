/*
 * Copyright (c) 2023 Smart Operating Block
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#ifndef __TEMPERATURE__
#define __TEMPERATURE__


/*
    Enum that models the temperature unit of measurement.
*/
enum class TemperatureUnit {
    CELSIUS
};

/*
    Class that models the temperature concepts.
*/
class Temperature {
    public:
        /*
            Constructor.

            @param value the value of temperature.
            @param unit the unit of measurement used to express the value.
        */
        Temperature(const float value, const TemperatureUnit unit): value(value), unit(unit) {}

        /*
            Get the value of temperature.

            @return the temperature.
        */
        float getTemperatureValue() {
            return this->value;
        }

        /*
            Get the unit used to express the value.

            @return the unit.
        */
        TemperatureUnit getTemperatureUnit() {
            return this->unit;
        }

    private:
        const float value;
        const TemperatureUnit unit;
};

#endif