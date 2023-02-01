/*
 * Copyright (c) 2023 Smart Operating Block
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#ifndef __EXTERNAL_GATEWAY__
#define __EXTERNAL_GATEWAY__

#include "Arduino.h"

/*
    Interface that models the comunication with the external gateway.
*/
class ExternalGateway {
    public:
        /*
            Send raw data to the gateway.

            @param rawData the data to send.
        */
        virtual void send(String rawData) = 0;
};

#endif