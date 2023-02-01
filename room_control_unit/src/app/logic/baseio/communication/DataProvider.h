/*
 * Copyright (c) 2023 Smart Operating Block
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#ifndef __DATA_PROVIDER__
#define __DATA_PROVIDER__

#include "Arduino.h"

/*
    Interface that models the provider of data to the system.
*/
class DataProvider {
    public:
        /*
            Check if a new data is available.

            @return true if new data is available, false otherwise.
        */
        virtual bool isNewDataAvailable() = 0;

        /*
            Get the current data.

            @return the data.
        */
        virtual String getData() = 0;
};

#endif