/*
 * Copyright (c) 2023 Smart Operating Block
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#include "RfidTagReader.h"

#define BLOCK_RESPONSE_SIZE 18
#define BLOCK_SIZE 16
#define KEY_SIZE 6

RfidTagReader::RfidTagReader(const int readerPin, const int resetPin) {
    this->rfidReader.PCD_Init(readerPin, resetPin);
}

bool RfidTagReader::isTagAvailable() {
    // Needed for performance and technical reason
    // It is not possible to double check the card presence in short amount of time.
    this->cardAvailable = this->rfidReader.PICC_IsNewCardPresent();
    return this->cardAvailable;
}

String RfidTagReader::readBlock(const int blockNumber) {
    String result = "";

    if(this->cardAvailable || this->isTagAvailable()) {
        this->rfidReader.PICC_ReadCardSerial();
        byte bufferLen = BLOCK_RESPONSE_SIZE;
        byte readBlockData[BLOCK_RESPONSE_SIZE];

        // Prepare the key for authentication (default key)
        for (byte i = 0; i < KEY_SIZE; i++)
        {
            this->key.keyByte[i] = 0xFF;
        }

        MFRC522::StatusCode status = this->rfidReader.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, blockNumber, &this->key, &(this->rfidReader.uid));
        if (status == MFRC522::STATUS_OK)
        {
            // Reading data from the block
            status = this->rfidReader.MIFARE_Read(blockNumber, readBlockData, &bufferLen);
            if (status == MFRC522::STATUS_OK)
            {
                // Convert byte in String - add terminator
                readBlockData[BLOCK_SIZE] = '\0';
                result = String((char*) readBlockData);
            }
        }

        // Halt PICC
        this->rfidReader.PICC_HaltA();
        // Stop encryption on PCD
        this->rfidReader.PCD_StopCrypto1();
        this->cardAvailable = false;
    }

    return result;
}

