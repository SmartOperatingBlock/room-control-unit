/*
 * Copyright (c) 2023 Smart Operating Block
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */


#ifndef __POWER_STATUS__
#define __POWER_STATUS__

/*
    Enum that define the power status of a sensor or an actuator.
*/
enum class PowerStatus {
    /*
        The device is on.
    */
    ON, 

    /*
        The device is off.
    */
    OFF
};


#endif
