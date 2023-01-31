/*
 * Copyright (c) 2023 Smart Operating Block
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#ifndef __LUMINOSITY__
#define __LUMINOSITY__


/*
    Enum that models the luminosity unit of measurement.
*/
enum class LuminosityUnit {
    LUMEN
};

/*
    Class that models the luminosity concepts.
*/
class Luminosity {
    public:
        /*
            Constructor.

            @param value the value of luminosity.
            @param unit the unit of measurement used to express the value.
        */
        Luminosity(const float value, const LuminosityUnit unit): value(value), unit(unit) {}

        /*
            Get the value of luminosity.

            @return the luminosity.
        */
        float getLuminosityValue();

        /*
            Get the unit used to express the value.

            @return the unit.
        */
        LuminosityUnit getLuminosityUnit();

    private:
        const float value;
        const LuminosityUnit unit;
};

#endif