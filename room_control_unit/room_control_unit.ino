/*
 * Copyright (c) 2023 Smart Operating Block
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#include "src/system/System.h"
#include "src/utils/List.h"
#include "src/config/FsmPeriod.h"
#include "src/app/model/event/Event.h"
#include "src/config/ContextProvider.h"
#include "src/app/io/communication/SerialInterface.h"
#include "src/app/logic/fsm/thmonitoring/TemperatureHumidityMonitoring.h"
#include "src/app/logic/fsm/gatewayexporter/GatewayExporter.h"

void setup() {
    System::getInstance()->init();
    List<Event*>* const eventList = new List<Event*>();
    SerialInterface::getInstance()->init(115200);
    
    System::getInstance()->addTask(new TemperatureHumidityMonitoring(TEMPERATURE_HUMIDITY_PERIOD, getTemperatureHumidityMonitoringContext(eventList)));
    System::getInstance()->addTask(new GatewayExporter(GATEWAY_EXPORTER_PERIOD, getGatewayExporterContext(eventList, SerialInterface::getInstance())));
}

void loop() {
    System::getInstance()->run();
}
