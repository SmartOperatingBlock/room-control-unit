/*
 * Copyright (c) 2023 Smart Operating Block
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#ifndef __FSM__
#define __FSM__

#include "State.h"
#include "../../system/task/Task.h"

/*
    Interface that describe a Task modeled as a Finite State Machine.
    In this way we can add directly fsms to the system's scheduler.
*/
class Fsm: public Task {
    public:
        /*
            Change the current state of the fsm.
            This can be safely called also by states.

            @param state the new state.
        */
        virtual void changeState(State* state) = 0;

        /*
            Get the current state.

            @return the current state.
        */
        virtual State* getState() = 0;

        /*
            Deconstructor.
        */
        virtual ~Fsm() {}
};


#endif