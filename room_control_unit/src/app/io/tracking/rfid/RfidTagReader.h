/*
 * Copyright (c) 2023 Smart Operating Block
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#ifndef __RFID_TAG_READER__
#define __RFID_TAG_READER__

#include "Arduino.h"
#include "TagReader.h"
#include <MFRC522.h>

/*
    A tag reader that use rfid technology.
*/
class RfidTagReader: public TagReader {
    public:
        /*
            Constructor.

            @param readerPin the SDA pin of the reader.
            @param resetPin reset pin of the reader.
        */
        RfidTagReader(int readerPin, int resetPin);
        bool isTagAvailable();
        String readBlock(int blockNumber);

    private:
        MFRC522 rfidReader;
        MFRC522::MIFARE_Key key;
        // Needed for performance and technical reason
        // It is not possible to double check the card presence in short amount of time.
        bool cardAvailable;
};

#endif