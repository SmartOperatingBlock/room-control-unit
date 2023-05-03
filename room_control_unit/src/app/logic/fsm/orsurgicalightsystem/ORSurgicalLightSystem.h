/*
 * Copyright (c) 2023 Smart Operating Block
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#ifndef __OPERATING_ROOM_SURGICAL_LIGHT_SYSTEM__
#define __OPERATING_ROOM_SURGICAL_LIGHT_SYSTEM__

#include "../AbstractFsm.h"
#include "../../../model/event/Event.h"
#include "../../../model/command/Command.h"
#include "../../baseio/SurgicalLight.h"
#include "../../../../utils/List.h"


struct ORSurgicalLightSystemContext {
    List<Event*>* const eventList;
    Command** currentCommand;
    Room room;
    SurgicalLight* surgicalLight;
};

/*
    Surgical light system task.
    Its main objective is to control the surgical light of an operating room.
*/
class ORSurgicalLightSystem: public AbstractFsm {
    public:
        /*
            Constructor.

            @param period the period of the fsm.
            @param context the local context of the fsm.
        */
        ORSurgicalLightSystem(int period, ORSurgicalLightSystemContext* context);
        ~ORSurgicalLightSystem();

    private:
        ORSurgicalLightSystemContext* const context;

        class SLOFF: public State {
            public:
                SLOFF(ORSurgicalLightSystemContext* context);
                void run(Fsm* parentFsm);
            private:
                ORSurgicalLightSystemContext* const context;
        };

        class SLON: public State {
            public:
                SLON(ORSurgicalLightSystemContext* context, Luminosity lightIntensity);
                void run(Fsm* parentFsm);
            private:
                ORSurgicalLightSystemContext* const context;
        };

};


#endif