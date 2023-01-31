/*
 * Copyright (c) 2023 Smart Operating Block
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#ifndef __HVAC__
#define __HVAC__


enum class HvacStatus {
    /*
        Only ventilation without heating or cooling.
    */
    VENTILATION,

    /*
        The Hvac system is off.
    */
    OFF,

    /*
        Heating is on, so also ventilation.
    */
    HEATING,

    /*
        Cooling is on, so also ventilation.
    */
    COOLING
};

/*
    Interface for modeling the HVAC System.
*/
class Hvac {
    public:
        /*
            Get the current status of the Hvac system.

            @return the status
        */
        HvacStatus getCurrentStatus();

        /*
            Turn the ventilation on/off based on the parameter.

            @param state if it is set to true then the ventilation will be turned on.
            Instead if it is set to off then the ventilation will be turned off.
        */
        void turnVentilation(bool state);

        /*
            Turn the heating on/off based on the parameter.

            @param state if it is set to true then the heating will be turned on.
            Instead if it is set to off then the heating will be turned off.
        */
        void turnHeating(bool state);

        /*
            Turn the cooling on/off based on the parameter.

            @param state if it is set to true then the cooling will be turned on.
            Instead if it is set to off then the cooling will be turned off.
        */
        void turnCooling(bool state);
};

#endif
