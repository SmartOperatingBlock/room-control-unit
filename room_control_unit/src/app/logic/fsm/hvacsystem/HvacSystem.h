/*
 * Copyright (c) 2023 Smart Operating Block
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#ifndef __HVAC_SYSTEM__
#define __HVAC_SYSTEM__

#include "../AbstractFsm.h"
#include "../../../model/event/Event.h"
#include "../../../model/command/Command.h"
#include "../../../../utils/List.h"
#include "../../baseio/Cooling.h"
#include "../../baseio/Heating.h"
#include "../../baseio/Ventilation.h"

struct HvacSystemContext {
    List<Event*>* const eventList;
    Command** currentCommand;
    Room room;
    Ventilation* ventilationSystem;
    Heating* heatingModule;
    Cooling* coolingModule;
};

/*
    Hvac System task.
    Its main objective is to control the hvac system of a room.
*/
class HvacSystem: public AbstractFsm {
    public:
        /*
            Constructor.

            @param period the period of the fsm.
            @param context the local context of the fsm.
        */
        HvacSystem(int period, HvacSystemContext* context);
        ~HvacSystem();

    private:
        HvacSystemContext* const context;

        class VOFF: public State {
            public:
                VOFF(HvacSystemContext* context);
                void run(Fsm* parentFsm);
            private:
                HvacSystemContext* const context;
        };

        class VON: public State {
            public:
                VON(HvacSystemContext* context);
                void run(Fsm* parentFsm);
            private:
                HvacSystemContext* const context;
        };

        class HON: public State {
            public:
                HON(HvacSystemContext* context);
                void run(Fsm* parentFsm);
            private:
                HvacSystemContext* const context;
        };

        class CON: public State {
            public:
                CON(HvacSystemContext* context);
                void run(Fsm* parentFsm);
            private:
                HvacSystemContext* const context;
        };

};


#endif