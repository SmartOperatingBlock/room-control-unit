/*
 * Copyright (c) 2023 Smart Operating Block
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#ifndef __COMMAND_LISTENER__
#define __COMMAND_LISTENER__

#include "../AbstractFsm.h"
#include "../../baseio/communication/DataProvider.h"
#include "../../../model/command/Command.h"
#include "../../presenter/deserializer/CommandDeserializer.h"

struct CommandListenerContext {
    DataProvider* dataProvider;
    Command* currentCommand;
};

/*
    Command listener task.
    Its main objective is to read data from the external data provider and understand
    the commands for the system making them available to other tasks.
*/
class CommandListener: public AbstractFsm {
    public:
        /*
            Constructor.

            @param period the period of the fsm.
            @param context the local context of the fsm.
        */
        CommandListener(int period, CommandListenerContext* context);
        ~CommandListener();

    private:
        CommandListenerContext* const context;

        class L: public State {
            public:
                L(CommandListenerContext* context);
                ~L();
                void run(Fsm* parentFsm);
            private:
                CommandListenerContext* const context;
                CommandDeserializer* commandDeserializer;
        };

};


#endif