/*
 * Copyright (c) 2023 Smart Operating Block
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#ifndef __PERSON_TRACKER_IMPL__
#define __PERSON_TRACKER_IMPL__

#include "../../logic/baseio/PersonTracker.h"
#include "rfid/TagReader.h"

/*
    Implementation of a Person Tracker inside the Operating Block.
*/
class PersonTrackerImpl: public PersonTracker {
    public:
        /*
            Constructor.

            @param readerPin the tag reader pin.
            @param resetPin the pin to reset the tag reader.
        */
        PersonTrackerImpl(int readerPin, int resetPin);

        /*
            Deconstructor to clean memory.
        */
        ~PersonTrackerImpl();
        bool checkNewPerson();
        Person getLastPersonDetected();
    private:
        TagReader* tagReader;
        Person* lastPersonDetected;
};

#endif