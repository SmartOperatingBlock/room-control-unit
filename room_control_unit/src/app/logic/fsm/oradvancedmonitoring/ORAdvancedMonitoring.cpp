/*
 * Copyright (c) 2023 Smart Operating Block
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#include "ORAdvancedMonitoring.h"
#include "../../../../utils/ArrayStream.h"

ORAdvancedMonitoring::ORAdvancedMonitoring(const int period, ORAdvancedMonitoringContext* const context): AbstractFsm(period), context(context) {
    this->changeState(new PN(context));
}

ORAdvancedMonitoring::~ORAdvancedMonitoring() {
    delete this->context;
}

/*
##############################################################################
------------------State of LuminosityMonitoring FSM ---------------
##############################################################################
*/

/*
    ----- PN State -----
*/

ORAdvancedMonitoring::PN::PN(ORAdvancedMonitoringContext* const context): context(context) {}

void ORAdvancedMonitoring::PN::run(Fsm* const parentFsm) {
    if(this->context->operatingTablePressureSensor->isPressed()) {
        this->context->eventList->add(new PatientOnOperatingTable(this->context->operatingRoom));
        parentFsm->changeState(new PON(this->context));
    }
}

/*
    ----- PON State -----
*/

ORAdvancedMonitoring::PON::PON(ORAdvancedMonitoringContext* const context): context(context) {}

void ORAdvancedMonitoring::PON::run(Fsm* const parentFsm) {
    if(!this->context->operatingTablePressureSensor->isPressed()) {
        parentFsm->changeState(new PN(this->context));
    } else {
        if(this->context->implantableMedicalDeviceTracker->checkNewDevice()) {
            ImplantableMedicalDevice device = this->context->implantableMedicalDeviceTracker->getLastDeviceDetected();
            this->context->eventList->add(new ImplantableMedicalDeviceTrack(device, this->context->operatingRoom));
        }
    }
}