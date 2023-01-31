/*
 * Copyright (c) 2023 Smart Operating Block
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#ifndef __DIGITAL__
#define __DIGITAL__

#include "../../model/PowerStatus.h"
#include "Arduino.h"

/*
    Utility class to handle Digital Pins with or without pwm.
*/
class Digital {
    public:
        /*
            Utility method to turn a digital pin on/off.

            @param pin the pin to control.
            @param status the status of the pin that we want.
        */
        static void turnPin(const int pin, const PowerStatus status) {
            switch (status)
            {
                case PowerStatus::ON:
                        digitalWrite(pin, HIGH);
                    break;
                case PowerStatus::OFF:
                        digitalWrite(pin, LOW);
                    break;
            }
        }

        /*
            Utility method to control a digital pin with PWM.

            @param pin the pin to control.
            @param pwmValue the pwm value to set.
        */
        static void turnPinPwm(const int pin, const int pwmValue) {
            analogWrite(pin, pwmValue);
        }
};


#endif