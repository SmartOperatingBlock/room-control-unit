/*
 * Copyright (c) 2023 Smart Operating Block
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#include "SerialInterface.h"
#include "Arduino.h"

static bool isDataAvailable;
static String content;

SerialInterface* SerialInterface::instance = nullptr;

SerialInterface* SerialInterface::getInstance() {
    if(instance == nullptr) {
        instance = new SerialInterface();
    }
    return instance;
}

SerialInterface::SerialInterface() {
    isDataAvailable = false;
    content = "";
}

void SerialInterface::init(const unsigned long bps) {
    Serial.begin(bps);
}

bool SerialInterface::isNewDataAvailable() {
    return isDataAvailable;
}

String SerialInterface::getData() {
    String result = content;
    isDataAvailable = false;
    content = "";
    return result;
}

void SerialInterface::send(const String rawData) {
    Serial.println(rawData);
}

/*
    This function is automatically called by the Arduino/Wiring super-loop each iteration when
    there is data on the serial.
*/
void serialEvent() {
  // reading the content
  while (!isDataAvailable && Serial.available()) { // Until the data isn't consumed then don't record anything else.
    char ch = (char) Serial.read();
    if(ch == '\n') {      
        isDataAvailable = true;
    } else {
        content += ch;
    }
  }
}