/*
 * Copyright (c) 2023 Smart Operating Block
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#ifndef __JSON_COMMAND_DESERIALIZER__
#define __JSON_COMMAND_DESERIALIZER__

#include "../CommandDeserializer.h"

/*
    Class that implements the deserialization of commands sent in the JSON format.
*/
class JsonCommandDeserializer: public CommandDeserializer {
    public:
        /*
            Constructor.
        */
        JsonCommandDeserializer();

        Command* deserialize(String rawCommand);

    private:
        /*
            Convert string in PowerStatus enum.

            @param rawStatus the status expressed as a String.
            @return the PowerStatus enum.
        */
        PowerStatus statusFromString(String rawStatus);
};

#endif