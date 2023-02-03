/*
 * Copyright (c) 2023 Smart Operating Block
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#include "PresenceMonitoring.h"
#include "../../../../utils/ArrayStream.h"

PresenceMonitoring::PresenceMonitoring(const int period, PresenceMonitoringContext* const context): AbstractFsm(period) {
    this->changeState(new M(context));
}

/*
##############################################################################
------------------State of LuminosityMonitoring FSM ---------------
##############################################################################
*/

PresenceMonitoring::M::M(PresenceMonitoringContext* const context): context(context) {}

void PresenceMonitoring::M::run(Fsm* const parentFsm) {
    ArrayStream<RoomEquipment<PresenceSensor*>*>(this->context->presenceSensors, this->context->sensorCount)
        .foreach([this](RoomEquipment<PresenceSensor*>* equipment) {
             bool presence = equipment->getTool()->checkPresence();
             this->context->eventList->add(new PresenceEvent(equipment->getRoom(), presence));
        });
}