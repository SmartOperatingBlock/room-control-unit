/*
 * Copyright (c) 2023 Smart Operating Block
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#include "PeopleTracking.h"
#include "../../../../utils/ArrayStream.h"

PeopleTracking::PeopleTracking(const int period, PeopleTrackingContext* const context): AbstractFsm(period) {
    this->changeState(new T(context));
}

/*
##############################################################################
------------------State of LuminosityMonitoring FSM ---------------
##############################################################################
*/

PeopleTracking::T::T(PeopleTrackingContext* const context): context(context) {}

void PeopleTracking::T::run(Fsm* const parentFsm) {
    ArrayStream<PersonTracker*>(this->context->personTrackers, this->context->readerCount)
        .foreach([this](PersonTracker* tracker) {
             if(tracker->checkNewPerson()) {
                Person newPerson = tracker->getLastPersonDetected();
                Room* nextRoom = tracker->getNextRoom();
                Room* previousRoom = tracker->getPreviousRoom();
                if(ArrayStream<Pair<String, String>>(this->trackInfo.toArray(), this->trackInfo.size())
                    .exist(Pair<String, String>(nextRoom->getId(), newPerson.getId()))) {
                        this->trackInfo.deleteElement(Pair<String, String>(nextRoom->getId(), newPerson.getId()), true);
                        if(previousRoom == nullptr) {
                            this->context->eventList->add(new PersonTrackExit(newPerson));
                        } else {
                            this->trackInfo.add(Pair<String, String>(previousRoom->getId(), newPerson.getId()));
                            this->context->eventList->add(new PersonTrack(newPerson, *previousRoom));
                        }
                    } else {
                        if(previousRoom != nullptr) {
                            this->trackInfo.deleteElement(Pair<String, String>(previousRoom->getId(), newPerson.getId()), true);
                        }
                        this->trackInfo.add(Pair<String, String>(nextRoom->getId(), newPerson.getId()));
                        this->context->eventList->add(new PersonTrack(newPerson, *nextRoom));
                    }
             }
        });
}