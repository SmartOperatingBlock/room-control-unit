/*
 * Copyright (c) 2023 Smart Operating Block
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#ifndef __PEOPLE_TRACKING__
#define __PEOPLE_TRACKING__

#include "../AbstractFsm.h"
#include "../../../model/event/Event.h"
#include "../../baseio/equipment/RoomEquipment.h"
#include "../../baseio/PersonTracker.h"
#include "../../../../utils/List.h"
#include "../../../../utils/Pair.h"
#include "Arduino.h"

struct PeopleTrackingContext {
    List<Event*>* const eventList;
    const int readerCount;
    PersonTracker** const personTrackers;
};

/*
    People tracking task.
    Its main objective is to use the readers inside the
    different rooms to track person signalling movements to the system firing new events.
*/
class PeopleTracking: public AbstractFsm {
    public:
        /*
            Constructor.

            @param period the period of the fsm.
            @param context the local context of the fsm.
        */
        PeopleTracking(int period, PeopleTrackingContext* context);
    
    private:
        class T: public State {
            public:
                T(PeopleTrackingContext* context);
                void run(Fsm* parentFsm);
            private:
                PeopleTrackingContext* const context;
                List<Pair<String, String>> trackInfo;
        };

};


#endif