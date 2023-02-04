/*
 * Copyright (c) 2023 Smart Operating Block
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#include "HvacSystem.h"
#include "../../../../utils/ArrayStream.h"

HvacSystem::HvacSystem(const int period, HvacSystemContext* const context): AbstractFsm(period), context(context) {
    this->changeState(new VON(context));
}

HvacSystem::~HvacSystem() {
    delete this->context;
}

/*
##############################################################################
------------------State of HvacSystem FSM ---------------
##############################################################################
*/

/*
    ----- VON State -----
*/

HvacSystem::VON::VON(HvacSystemContext* const context): context(context) {
    // act
    this->context->ventilationSystem->turn(PowerStatus::ON);
    this->context->heatingModule->turn(PowerStatus::OFF);
    this->context->coolingModule->turn(PowerStatus::OFF);
    // signal to gateway
    this->context->eventList->add(new ActuatorStateEvent(this->context->ventilationSystem,
        PowerStatus::ON,
        this->context->ventilationSystem->getSpeedPercentage()));
    this->context->eventList->add(new ActuatorStateEvent(this->context->heatingModule, PowerStatus::OFF));
    this->context->eventList->add(new ActuatorStateEvent(this->context->coolingModule, PowerStatus::OFF));
}

void HvacSystem::VON::run(Fsm* const parentFsm) {
    if(*this->context->currentCommand != nullptr) {
        switch((*this->context->currentCommand)->getCommandType()) {
            case CommandType::VENTILATION: {
                    VentilationCommand* command = static_cast<VentilationCommand*>(*this->context->currentCommand);
                    if(command->getRoom().getId() == this->context->room.getId()) {
                        Percentage intensityPercentage = command->getIntensityPercentage();
                        if(intensityPercentage.get() == 0) {
                            parentFsm->changeState(new VOFF(this->context));
                        } else {
                            this->context->ventilationSystem->setSpeedPercentage(intensityPercentage);
                            this->context->eventList->add(new ActuatorStateEvent(this->context->ventilationSystem,
                                PowerStatus::ON,
                                this->context->ventilationSystem->getSpeedPercentage()));
                        }
                    }
                } break;

            case CommandType::HEATING: {
                    HeatingCommand* command = static_cast<HeatingCommand*>(*this->context->currentCommand);
                    if(command->getRoom().getId() == this->context->room.getId()) {
                        parentFsm->changeState(new HON(this->context));
                    }
                } break;

            case CommandType::COOLING: {
                    CoolingCommand* command = static_cast<CoolingCommand*>(*this->context->currentCommand);
                    if(command->getRoom().getId() == this->context->room.getId()) {
                        parentFsm->changeState(new CON(this->context));
                    }
                } break;

            default:
                break;
        }
    }
}

/*
    ----- VOFF State -----
*/

HvacSystem::VOFF::VOFF(HvacSystemContext* const context): context(context) {
    this->context->ventilationSystem->turn(PowerStatus::OFF);
    this->context->eventList->add(new ActuatorStateEvent(
        this->context->ventilationSystem, PowerStatus::OFF, this->context->ventilationSystem->getSpeedPercentage()));
}

void HvacSystem::VOFF::run(Fsm* const parentFsm) {
    if(*this->context->currentCommand != nullptr) {
        switch((*this->context->currentCommand)->getCommandType()) {
            case CommandType::HEATING: {
                    HeatingCommand* command = static_cast<HeatingCommand*>(*this->context->currentCommand);
                    if(command->getRoom().getId() == this->context->room.getId()) {
                        parentFsm->changeState(new HON(this->context));
                    }
                } break;

            case CommandType::COOLING: {
                    CoolingCommand* command = static_cast<CoolingCommand*>(*this->context->currentCommand);
                    if(command->getRoom().getId() == this->context->room.getId()) {
                        parentFsm->changeState(new CON(this->context));
                    }
                } break;

            case CommandType::VENTILATION: {
                    VentilationCommand* command = static_cast<VentilationCommand*>(*this->context->currentCommand);
                    if(command->getRoom().getId() == this->context->room.getId()) {
                        Percentage intensityPercentage = command->getIntensityPercentage();
                        if(intensityPercentage.get() != 0) {
                            this->context->ventilationSystem->setSpeedPercentage(intensityPercentage);
                            parentFsm->changeState(new VON(this->context));
                        }
                    }
                } break;

            default:
                break;
        }
    }
}

/*
    ----- HON State -----
*/

HvacSystem::HON::HON(HvacSystemContext* const context): context(context) {
    if(this->context->ventilationSystem->getStatus() == PowerStatus::OFF) {
        this->context->ventilationSystem->turn(PowerStatus::ON);
        this->context->eventList->add(new ActuatorStateEvent(this->context->ventilationSystem,
            PowerStatus::ON,
            this->context->ventilationSystem->getSpeedPercentage()));
    }
    this->context->heatingModule->turn(PowerStatus::ON);
    this->context->eventList->add(new ActuatorStateEvent(this->context->heatingModule, PowerStatus::ON));
}

void HvacSystem::HON::run(Fsm* const parentFsm) {
    if(*this->context->currentCommand != nullptr) {
        switch((*this->context->currentCommand)->getCommandType()) {
            case CommandType::HEATING: {
                    HeatingCommand* heatingCommand = static_cast<HeatingCommand*>(*this->context->currentCommand);
                    if(heatingCommand->getRoom().getId() == this->context->room.getId() && heatingCommand->getStatus() == PowerStatus::OFF) {
                        parentFsm->changeState(new VON(this->context));
                    }
                } break;
            
            case CommandType::VENTILATION: {
                    VentilationCommand* ventilationCommand = static_cast<VentilationCommand*>(*this->context->currentCommand);
                    if(ventilationCommand->getRoom().getId() == this->context->room.getId()) {
                        Percentage intensityPercentage = ventilationCommand->getIntensityPercentage();
                        this->context->ventilationSystem->setSpeedPercentage(intensityPercentage);
                        this->context->eventList->add(new ActuatorStateEvent(this->context->ventilationSystem,
                            PowerStatus::ON,
                            this->context->ventilationSystem->getSpeedPercentage()));
                    }
                } break;
        }
    }
}

/*
    ----- CON State -----
*/

HvacSystem::CON::CON(HvacSystemContext* const context): context(context) {
    if(this->context->ventilationSystem->getStatus() == PowerStatus::OFF) {
        this->context->ventilationSystem->turn(PowerStatus::ON);
        this->context->eventList->add(new ActuatorStateEvent(this->context->ventilationSystem,
            PowerStatus::ON,
            this->context->ventilationSystem->getSpeedPercentage()));
    }
    this->context->coolingModule->turn(PowerStatus::ON);
    this->context->eventList->add(new ActuatorStateEvent(this->context->coolingModule, PowerStatus::ON));
}

void HvacSystem::CON::run(Fsm* const parentFsm) {
    if(*this->context->currentCommand != nullptr) {
        switch((*this->context->currentCommand)->getCommandType()) {
            case CommandType::COOLING: {
                    CoolingCommand* coolingCommand = static_cast<CoolingCommand*>(*this->context->currentCommand);
                    if(coolingCommand->getRoom().getId() == this->context->room.getId() && coolingCommand->getStatus() == PowerStatus::OFF) {
                        parentFsm->changeState(new VON(this->context));
                    }
                } break;
            
            case CommandType::VENTILATION: {
                    VentilationCommand* ventilationCommand = static_cast<VentilationCommand*>(*this->context->currentCommand);
                    if(ventilationCommand->getRoom().getId() == this->context->room.getId()) {
                        Percentage intensityPercentage = ventilationCommand->getIntensityPercentage();
                        this->context->ventilationSystem->setSpeedPercentage(intensityPercentage);
                        this->context->eventList->add(new ActuatorStateEvent(this->context->ventilationSystem,
                            PowerStatus::ON,
                            this->context->ventilationSystem->getSpeedPercentage()));
                    }
                } break;
        }
    }
}