/*
 * Copyright (c) 2023 Smart Operating Block
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#include "CommandListener.h"
#include "../../presenter/deserializer/json/JsonCommandDeserializer.h"

CommandListener::CommandListener(const int period, CommandListenerContext* const context): AbstractFsm(period), context(context) {
    this->changeState(new L(context));
}

CommandListener::~CommandListener() {
    delete this->context;
}

/*
##############################################################################
------------------State of CommandListener FSM ---------------
##############################################################################
*/

CommandListener::L::L(CommandListenerContext* const context): context(context) {
    this->commandDeserializer = new JsonCommandDeserializer();
}

CommandListener::L::~L() {
    delete this->commandDeserializer;
}

void CommandListener::L::run(Fsm* const parentFsm) {
    delete *this->context->currentCommand; // clean previous command
    *this->context->currentCommand = nullptr;

    if(this->context->dataProvider->isNewDataAvailable()) {
        String rawData = this->context->dataProvider->getData();
        Command* newCommand = this->commandDeserializer->deserialize(rawData);
        if(newCommand != nullptr) {
            *this->context->currentCommand = newCommand;
        }
    }
}