/*
 * Copyright (c) 2023 Smart Operating Block
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#include "DiscoveryTask.h"
#include "../../../utils/ArrayStream.h"

#define WAIT_TIME_BEFORE_DISCOVERY 500

DiscoveryTask::DiscoveryTask(DiscoveryTaskContext* const taskContext): 
    AbstractTask(WAIT_TIME_BEFORE_DISCOVERY), taskContext(taskContext) {}

DiscoveryTask::~DiscoveryTask() {
    delete this->taskContext;
}

void DiscoveryTask::tick() {
    // Signal the actuators present
    ArrayStream<RoomEquipment<Actuator*>*>(this->taskContext->actuatorArray, this->taskContext->actuatorArrayLenght)
        .foreach([this](RoomEquipment<Actuator*>* const equipment) { this->taskContext->eventList->addFirst(new NewActuator(equipment->getTool(), equipment->getRoom())); });

    // Signal the room handled
    ArrayStream<Room>(this->taskContext->roomHandled, this->taskContext->numberOfRoom)
    .foreach([this](const Room room) { this->taskContext->eventList->addFirst(new RoomEntry(room)); });

    // The task now can terminate.
    this->terminate();
}

int DiscoveryTask::getPeriod() {
    return AbstractTask::getPeriod();
}

bool DiscoveryTask::updateAndCheck(const int schedulerPeriod) {
    return AbstractTask::updateAndCheck(schedulerPeriod);
}

