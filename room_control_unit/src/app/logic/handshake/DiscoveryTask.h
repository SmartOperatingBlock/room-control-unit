/*
 * Copyright (c) 2023 Smart Operating Block
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#ifndef __DISCOVERY_TASK
#define __DISCOVERY_TASK

#include "../../../system/task/AbstractTask.h"
#include "../../model/Actuator.h"
#include "../baseio/equipment/RoomEquipment.h"
#include "../../model/event/Event.h"
#include "../../model/Room.h"
#include "../../../utils/List.h"

struct DiscoveryTaskContext {
    List<Event*>* eventList;
    Room* const roomHandled;
    const int numberOfRoom;
    RoomEquipment<Actuator*>** const actuatorArray;
    const int actuatorArrayLenght;
};

class DiscoveryTask: public AbstractTask {
    public:
        /*
            Constructor.
            This isn't a periodic task. It's main responsibility is to perform a sort of handshake with the gateway
            in order to signal all rooms that this control unit handle and the actuators that are used in the system.
            The only thing that it has to do it is to signal them as event inside the infrastructure and then
            this event will be dispatched to the gateway by the task that consume internal events and communicate with it.

            @param taskContext the context of the task
        */
        DiscoveryTask(DiscoveryTaskContext* taskContext);
        ~DiscoveryTask();

        void tick();
        int getPeriod();
        bool updateAndCheck(int schedulerPeriod);
        
    private:
        DiscoveryTaskContext* taskContext;
};


#endif