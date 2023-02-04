/*
 * Copyright (c) 2023 Smart Operating Block
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#include "AmbientLightSystem.h"
#include "../../../../utils/ArrayStream.h"

AmbientLightSystem::AmbientLightSystem(const int period, AmbientLightSystemContext* const context): AbstractFsm(period), context(context) {
    this->changeState(new ALOFF(context));
}

AmbientLightSystem::~AmbientLightSystem() {
    delete this->context;
}

/*
##############################################################################
------------------State of AmbientLightSystem FSM ---------------
##############################################################################
*/

/*
    ----- ALOFF State -----
*/

AmbientLightSystem::ALOFF::ALOFF(AmbientLightSystemContext* const context): context(context) {
    this->context->ambientLight->turnOff();
    this->context->eventList->add(new ActuatorStateEvent(this->context->ambientLight, PowerStatus::OFF));
}

void AmbientLightSystem::ALOFF::run(Fsm* const parentFsm) {
    if(*this->context->currentCommand != nullptr && (*this->context->currentCommand)->getCommandType() == CommandType::AMBIENT_LIGHT) {
        AmbientLigthCommand* command = static_cast<AmbientLigthCommand*>(*this->context->currentCommand);
        if(command->getRoom() == this->context->room && command->getIntensityPercentage().get() != 0) {
            parentFsm->changeState(new ALON(this->context, command->getIntensityPercentage()));
        }
    }
}

/*
    ----- ALON State -----
*/

AmbientLightSystem::ALON::ALON(AmbientLightSystemContext* const context, const Percentage lightPercentage): context(context) {
    this->context->ambientLight->turnOn(lightPercentage);
    this->context->eventList->add(new ActuatorStateEvent(this->context->ambientLight, PowerStatus::ON, lightPercentage));
}

void AmbientLightSystem::ALON::run(Fsm* const parentFsm) {
    if(*this->context->currentCommand != nullptr && (*this->context->currentCommand)->getCommandType() == CommandType::AMBIENT_LIGHT) {
        AmbientLigthCommand* command = static_cast<AmbientLigthCommand*>(*this->context->currentCommand);
        if(command->getRoom() == this->context->room) {
            if(command->getIntensityPercentage().get() == 0) {
                parentFsm->changeState(new ALOFF(this->context));
            } else {
                parentFsm->changeState(new ALON(this->context, command->getIntensityPercentage()));
            }
        }
    }
}