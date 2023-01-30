/*
 * Copyright (c) 2023 Smart Operating Block
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#ifndef __ABSTRACT_FSM__
#define __ABSTRACT_FSM__

#include "Fsm.h"
#include "../../../system/task/AbstractTask.h"

/*
    Abstract implementation of an Finite State Machine.
*/
class AbstractFsm: public Fsm, public AbstractTask {
    public:
        AbstractFsm(const int period): AbstractTask(period) {
            this->prevState = NULL;
            this->currentState = NULL;
        }

        State* getState() {
            return this->currentState;
        }

        void changeState(State* const newState) {
            this->prevState = this->currentState;
            this->currentState = newState;
        }

        void tick() {
            this->currentState->run(this);

            //Delete old allocated state, in order to save heap memory.
            if(this->prevState != nullptr) {
                delete this->prevState;
                this->prevState = NULL;
            }
        }

        virtual ~AbstractFsm() {
            delete this->currentState;
            delete this->prevState;
        }

    private:
        State* currentState;
        State* prevState; //Save the prev state in order to delete it when unnecessary.
};

#endif