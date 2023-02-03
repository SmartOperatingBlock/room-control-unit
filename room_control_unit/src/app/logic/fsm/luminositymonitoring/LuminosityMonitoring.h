/*
 * Copyright (c) 2023 Smart Operating Block
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#ifndef __LUMINOSITY_MONITORING__
#define __LUMINOSITY_MONITORING__

#include "../AbstractFsm.h"
#include "../../../model/event/Event.h"
#include "../../baseio/equipment/RoomEquipment.h"
#include "../../baseio/LuminositySensor.h"
#include "../../../../utils/List.h"

struct LuminosityMonitoringContext {
    List<Event*>* const eventList;
    const int sensorCount;
    RoomEquipment<LuminositySensor*>** const luminositySensors;
};

/*
    Luminosity Monitoring task.
    Its main objective is to use the luminosity sensors inside the
    different room to obtain the associated data and signal it to the system firing a new event.
*/
class LuminosityMonitoring: public AbstractFsm {
    public:
        /*
            Constructor.

            @param period the period of the fsm.
            @param context the local context of the fsm.
        */
        LuminosityMonitoring(int period, LuminosityMonitoringContext* context);
    
    private:
        class M: public State {
            public:
                M(LuminosityMonitoringContext* context);
                void run(Fsm* parentFsm);
            private:
                LuminosityMonitoringContext* const context;
        };

};


#endif