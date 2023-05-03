/*
 * Copyright (c) 2023 Smart Operating Block
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#ifndef __AMBIENT_LIGHT_SYSTEM__
#define __AMBIENT_LIGHT_SYSTEM__

#include "../AbstractFsm.h"
#include "../../../model/event/Event.h"
#include "../../../model/command/Command.h"
#include "../../baseio/Light.h"
#include "../../../../utils/List.h"


struct AmbientLightSystemContext {
    List<Event*>* const eventList;
    Command** const currentCommand;
    Room room;
    Light* ambientLight;
};

/*
    Ambient light system task.
    Its main objective is to control the ambient light of a room.
*/
class AmbientLightSystem: public AbstractFsm {
    public:
        /*
            Constructor.

            @param period the period of the fsm.
            @param context the local context of the fsm.
        */
        AmbientLightSystem(int period, AmbientLightSystemContext* context);
        ~AmbientLightSystem();

    private:
        AmbientLightSystemContext* const context;

        class ALOFF: public State {
            public:
                ALOFF(AmbientLightSystemContext* context);
                void run(Fsm* parentFsm);
            private:
                AmbientLightSystemContext* const context;
        };

        class ALON: public State {
            public:
                ALON(AmbientLightSystemContext* context, Luminosity lightIntensity);
                void run(Fsm* parentFsm);
            private:
                AmbientLightSystemContext* const context;
        };

};


#endif