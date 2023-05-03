/*
 * Copyright (c) 2023 Smart Operating Block
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#include "ORSurgicalLightSystem.h"
#include "../../../../utils/ArrayStream.h"

#define MAX_LUX 200000

ORSurgicalLightSystem::ORSurgicalLightSystem(const int period, ORSurgicalLightSystemContext* const context): AbstractFsm(period), context(context) {
    this->changeState(new SLOFF(context));
}

ORSurgicalLightSystem::~ORSurgicalLightSystem() {
    delete this->context;
}

/*
##############################################################################
------------------State of ORSurgicalLightSystem FSM ---------------
##############################################################################
*/

/*
    ----- SLOFF State -----
*/

ORSurgicalLightSystem::SLOFF::SLOFF(ORSurgicalLightSystemContext* const context): context(context) {
    this->context->surgicalLight->turnOff();
    this->context->eventList->add(new ActuatorStateEvent(this->context->surgicalLight, PowerStatus::OFF));
}

void ORSurgicalLightSystem::SLOFF::run(Fsm* const parentFsm) {
    if(*this->context->currentCommand != nullptr && (*this->context->currentCommand)->getCommandType() == CommandType::SURGICAL_LIGHT) {
        SurgicalLightCommand* command = static_cast<SurgicalLightCommand*>(*this->context->currentCommand);
        if(command->getRoom() == this->context->room && command->getIntensity().getLuminosityValue() != 0) {
            parentFsm->changeState(new SLON(this->context, command->getIntensity()));
        }
    }
}

/*
    ----- SLON State -----
*/

ORSurgicalLightSystem::SLON::SLON(ORSurgicalLightSystemContext* const context, Luminosity lightIntensity): context(context) {
    long constrainedLux = constrain(lightIntensity.getLuminosityValue(), 0, MAX_LUX); // Constrain the lux specified in the command within the handled range
    long mappedValue = map(constrainedLux, 0, MAX_LUX, 0, 255); // Map the lux value to pwm
    this->context->surgicalLight->turnOn(mappedValue);
    this->context->eventList->add(new ActuatorStateEvent(this->context->surgicalLight, PowerStatus::ON, constrainedLux));
}

void ORSurgicalLightSystem::SLON::run(Fsm* const parentFsm) {
    if(*this->context->currentCommand != nullptr && (*this->context->currentCommand)->getCommandType() == CommandType::SURGICAL_LIGHT) {
        SurgicalLightCommand* command = static_cast<SurgicalLightCommand*>(*this->context->currentCommand);
        if(command->getRoom() == this->context->room) {
            if(command->getIntensity().getLuminosityValue() == 0) {
                parentFsm->changeState(new SLOFF(this->context));
            } else {
                parentFsm->changeState(new SLON(this->context, command->getIntensity()));
            }
        }
    }
}