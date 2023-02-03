/*
 * Copyright (c) 2023 Smart Operating Block
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#ifndef __COMMAND_DESERIALIZER__
#define __COMMAND_DESERIALIZER__

#include "../../../model/command/Command.h"

/*
    Interface that models a deserializer for commands.
*/
class CommandDeserializer {
    public:
        /*
            Deserialize a command.

            @param rawCommand the command expressed as a String.
            @return the deserialized command.
        */
        virtual Command* deserialize(String rawCommand) = 0;
};

#endif