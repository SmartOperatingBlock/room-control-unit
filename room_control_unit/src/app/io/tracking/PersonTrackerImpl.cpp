/*
 * Copyright (c) 2023 Smart Operating Block
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#include "PersonTrackerImpl.h"
#include "rfid/RfidTagReader.h"

#define PERSON_BLOCK 16
#define SPLIT_CHAR "#"

PersonTrackerImpl::PersonTrackerImpl(const int readerPin, const int resetPin, Room* const previousRoom, Room* const nextRoom): previousRoom(previousRoom), nextRoom(nextRoom) {
    this->tagReader = new RfidTagReader(readerPin, resetPin);
    this->lastPersonDetected = nullptr;
}

PersonTrackerImpl::~PersonTrackerImpl() {
    delete this->lastPersonDetected;
    delete this->tagReader;
    delete this->previousRoom;
    delete this->nextRoom;
}

bool PersonTrackerImpl::checkNewPerson() {
    if(this->tagReader->isTagAvailable()) {
        const String data = this->tagReader->readBlock(PERSON_BLOCK);
        const int splitIndex = data.indexOf(SPLIT_CHAR);
        const String personID = data.substring(0, splitIndex);
        const String rawPersonType = data.substring(splitIndex + 1);

        if(personID != "" && rawPersonType != "") {
            const PersonRole personRole = PersonRole(rawPersonType.toInt());
            delete this->lastPersonDetected; // clean memory
            this->lastPersonDetected = new Person(personID, personRole);
            return true;
        }
    }
    return false;
}

Person PersonTrackerImpl::getLastPersonDetected() {
    // return a new stack instance so it will not be deleted by the class.
    return Person(this->lastPersonDetected->getId(), this->lastPersonDetected->getRole());
}

Room* PersonTrackerImpl::getPreviousRoom() {
    return this->previousRoom;
}

Room* PersonTrackerImpl::getNextRoom() {
    return this->nextRoom;
}