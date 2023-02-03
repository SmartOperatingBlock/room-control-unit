/*
 * Copyright (c) 2023 Smart Operating Block
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#include "LuminosityMonitoring.h"
#include "../../../../utils/ArrayStream.h"

LuminosityMonitoring::LuminosityMonitoring(const int period, LuminosityMonitoringContext* const context): AbstractFsm(period) {
    this->changeState(new M(context));
}

/*
##############################################################################
------------------State of LuminosityMonitoring FSM ---------------
##############################################################################
*/

LuminosityMonitoring::M::M(LuminosityMonitoringContext* const context): context(context) {}

void LuminosityMonitoring::M::run(Fsm* const parentFsm) {
    ArrayStream<RoomEquipment<LuminositySensor*>*>(this->context->luminositySensors, this->context->sensorCount)
        .foreach([this](RoomEquipment<LuminositySensor*>* equipment) {
             Luminosity luminosity = equipment->getTool()->getLuminosity();
             this->context->eventList->add(new LuminosityEvent(equipment->getRoom(), luminosity));
        });
}