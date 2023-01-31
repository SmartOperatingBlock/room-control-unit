/*
 * Copyright (c) 2023 Smart Operating Block
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#include "PersonTrackerImpl.h"
#include "rfid/RfidTagReader.h"

#define PERSON_ID_BLOCK 2
#define PERSON_TYPE_BLOCK 3

PersonTrackerImpl::PersonTrackerImpl(const int readerPin, const int resetPin) {
    this->tagReader = new RfidTagReader(readerPin, resetPin);
    this->lastPersonDetected = nullptr;
}

PersonTrackerImpl::~PersonTrackerImpl() {
    delete this->lastPersonDetected;
    delete this->tagReader;
}

bool PersonTrackerImpl::checkNewPerson() {
    if(this->tagReader->isTagAvailable()) {
        String personID = this->tagReader->readBlock(PERSON_ID_BLOCK);
        String rawPersonType = this->tagReader->readBlock(PERSON_TYPE_BLOCK);

        if(personID != "" && rawPersonType != "") {
            PersonRole personRole = rawPersonType == "health" ? PersonRole::HEALTH_PROFESSIONAL : PersonRole::PATIENT;
            delete this->lastPersonDetected; // clean memory
            this->lastPersonDetected = new Person(personID, personRole);
            return true;
        }
    }
    return false;
}

Person PersonTrackerImpl::getLastPersonDetected() {
    // return a new stack instance so it will not be deleted by the class.
    return Person(this->lastPersonDetected->getId(), this->lastPersonDetected->getRole())
}