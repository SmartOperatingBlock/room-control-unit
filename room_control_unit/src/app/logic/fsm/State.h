/*
 * Copyright (c) 2023 Smart Operating Block
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#ifndef __STATE__
#define __STATE__

#include "Fsm.h"

class Fsm;

/*
    Models a state of a fsm.
*/
class State {
    public:
        /*
            Execute the logic under the current state.

            @param parentFsm the parent fsm of the state. 
            This is needed in case it is needed for example to change state.
        */
        virtual void run(Fsm* parentFsm) = 0;
        virtual ~State() {}
};


#endif