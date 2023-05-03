/*
 * Copyright (c) 2023 Smart Operating Block
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#include "AmbientLightSystem.h"
#include "../../../../utils/ArrayStream.h"

#define MAX_LUX 5000

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
        if(command->getRoom() == this->context->room && command->getIntensity().getLuminosityValue() != 0) {
            parentFsm->changeState(new ALON(this->context, command->getIntensity()));
        }
    }
}

/*
    ----- ALON State -----
*/

AmbientLightSystem::ALON::ALON(AmbientLightSystemContext* const context, Luminosity lightIntensity): context(context) {
    long constrainedLux = constrain(lightIntensity.getLuminosityValue(), 0, MAX_LUX); // Constrain the lux specified in the command within the handled range
    long mappedValue = map(constrainedLux, 0, MAX_LUX, 0, 255); // Map the lux value to pwm
    this->context->ambientLight->turnOn(mappedValue);
    this->context->eventList->add(new ActuatorStateEvent(this->context->ambientLight, PowerStatus::ON, constrainedLux));
}

void AmbientLightSystem::ALON::run(Fsm* const parentFsm) {
    if(*this->context->currentCommand != nullptr && (*this->context->currentCommand)->getCommandType() == CommandType::AMBIENT_LIGHT) {
        AmbientLigthCommand* command = static_cast<AmbientLigthCommand*>(*this->context->currentCommand);
        if(command->getRoom() == this->context->room) {
            if(command->getIntensity().getLuminosityValue() == 0) {
                parentFsm->changeState(new ALOFF(this->context));
            } else {
                parentFsm->changeState(new ALON(this->context, command->getIntensity()));
            }
        }
    }
}