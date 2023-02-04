/*
 * Copyright (c) 2023 Smart Operating Block
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#ifndef __PRESENCE_MONITORING__
#define __PRESENCE_MONITORING__

#include "../AbstractFsm.h"
#include "../../../model/event/Event.h"
#include "../../baseio/equipment/RoomEquipment.h"
#include "../../baseio/PresenceSensor.h"
#include "../../../../utils/List.h"

struct PresenceMonitoringContext {
    List<Event*>* const eventList;
    const int sensorCount;
    RoomEquipment<PresenceSensor*>** const presenceSensors;
};

/*
    Presence Monitoring task.
    Its main objective is to use the presence sensors inside the
    different room to obtain the associated data and signal it to the system firing a new event.
*/
class PresenceMonitoring: public AbstractFsm {
    public:
        /*
            Constructor.

            @param period the period of the fsm.
            @param context the local context of the fsm.
        */
        PresenceMonitoring(int period, PresenceMonitoringContext* context);
        ~PresenceMonitoring();
    
    private:
        PresenceMonitoringContext* const context;

        class M: public State {
            public:
                M(PresenceMonitoringContext* context);
                void run(Fsm* parentFsm);
            private:
                PresenceMonitoringContext* const context;
        };

};


#endif