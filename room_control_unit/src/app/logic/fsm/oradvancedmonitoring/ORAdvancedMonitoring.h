/*
 * Copyright (c) 2023 Smart Operating Block
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#ifndef __OR_ADVANCED_MONITORING__
#define __OR_ADVANCED_MONITORING__

#include "../AbstractFsm.h"
#include "../../../model/event/Event.h"
#include "../../../../utils/List.h"
#include "../../baseio/PressureSensor.h"
#include "../../baseio/ImplantableMedicalDeviceTracker.h"

struct ORAdvancedMonitoringContext {
    List<Event*>* const eventList;
    Room operatingRoom;
    PressureSensor* operatingTablePressureSensor;
    ImplantableMedicalDeviceTracker* implantableMedicalDeviceTracker;
};

/*
    Operating Room Advanced Monitoring task.
    Its main objective is to monitor the key events inside the operating room firing events
    to the system when interesting things happen. This task will collect data about
    the patient on the operating table and all the implantable medical device used.
*/
class ORAdvancedMonitoring: public AbstractFsm {
    public:
        /*
            Constructor.

            @param period the period of the fsm.
            @param context the local context of the fsm.
        */
        ORAdvancedMonitoring(int period, ORAdvancedMonitoringContext* context);
        ~ORAdvancedMonitoring();
    
    private:
        ORAdvancedMonitoringContext* const context;

        /*
            State in which the patient is not on Operating table.
        */
        class PN: public State {
            public:
                /*
                    Constructor.
                    @param context the local contest of the task.
                */
                PN(ORAdvancedMonitoringContext* context);
                void run(Fsm* parentFsm);
            private:
                ORAdvancedMonitoringContext* const context;
        };

        /*
            State in which the patient is on the operating table.
        */
        class PON: public State {
            public:
                /*
                    Constructor.
                    @param context the local contest of the task.
                */
                PON(ORAdvancedMonitoringContext* context);
                void run(Fsm* parentFsm);
            private:
                ORAdvancedMonitoringContext* const context;
        };

};


#endif