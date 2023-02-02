/*
 * Copyright (c) 2023 Smart Operating Block
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#ifndef __SERIALIZABLE__
#define __SERIALIZABLE__

#include "Arduino.h"
#include "Serializer.h"

class Serializer;

/**
 * Interface that model a serializable object.
*/
class Serializable {

    public:

        /**
         * Function used to comunicate the type to the serializer.
        */
        virtual String accept(Serializer *serializer) = 0;

};

#endif