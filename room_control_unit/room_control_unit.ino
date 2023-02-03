/*
 * Copyright (c) 2023 Smart Operating Block
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#include "src/system/System.h"
#include "src/utils/List.h"
#include "src/app/model/event/Event.h"
#include "src/app/logic/fsm/thmonitoring/TemperatureHumidityMonitoring.h"
#include "src/config/ContextProvider.h"

void setup() {
    Serial.begin(9600);
    System::getInstance()->init();
    List<Event*>* const eventList = new List<Event*>();
    
    
    System::getInstance()->addTask(new TemperatureHumidityMonitoring(5000, getTemperatureHumidityMonitoringContext(eventList)));
    
}

void loop() {
    System::getInstance()->run();
}
