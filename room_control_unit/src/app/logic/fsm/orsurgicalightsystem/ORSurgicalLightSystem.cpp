/*
 * Copyright (c) 2023 Smart Operating Block
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#include "ORSurgicalLightSystem.h"
#include "../../../../utils/ArrayStream.h"

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
        if(command->getRoom() == this->context->room && command->getIntensityPercentage().get() != 0) {
            parentFsm->changeState(new SLON(this->context, command->getIntensityPercentage()));
        }
    }
}

/*
    ----- SLON State -----
*/

ORSurgicalLightSystem::SLON::SLON(ORSurgicalLightSystemContext* const context, const Percentage lightPercentage): context(context) {
    this->context->surgicalLight->turnOn(lightPercentage);
    this->context->eventList->add(new ActuatorStateEvent(this->context->surgicalLight, PowerStatus::ON, lightPercentage));
}

void ORSurgicalLightSystem::SLON::run(Fsm* const parentFsm) {
    if(*this->context->currentCommand != nullptr && (*this->context->currentCommand)->getCommandType() == CommandType::SURGICAL_LIGHT) {
        SurgicalLightCommand* command = static_cast<SurgicalLightCommand*>(*this->context->currentCommand);
        if(command->getRoom() == this->context->room) {
            if(command->getIntensityPercentage().get() == 0) {
                parentFsm->changeState(new SLOFF(this->context));
            } else {
                parentFsm->changeState(new SLON(this->context, command->getIntensityPercentage()));
            }
        }
    }
}