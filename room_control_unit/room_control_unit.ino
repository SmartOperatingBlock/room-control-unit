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
#include "src/utils/ArrayStream.h"

#define SERIAL_INTERFACE_BAUD_RATE 115200
#define TASK_NUMBER 13

void setup() {
    List<Event*>* const eventList = new List<Event*>();
    Command* startCommand = nullptr;
    Command** currentCommand = &startCommand;
    
    SerialInterface::getInstance()->init(SERIAL_INTERFACE_BAUD_RATE);
    System::getInstance()->init();
    
    Task* taskArray[TASK_NUMBER] = {
        new DiscoveryTask(getDiscoveryTaskContext(eventList)),
        new CommandListener(COMMAND_LISTENER_PERIOD, getCommandListenerContext(SerialInterface::getInstance(), currentCommand)),
        new TemperatureHumidityMonitoring(TEMPERATURE_HUMIDITY_PERIOD, getTemperatureHumidityMonitoringContext(eventList)),
        new LuminosityMonitoring(LUMINOSITY_PERIOD, getLuminosityMonitoringContext(eventList)),
        new PresenceMonitoring(PRESENCE_MONITORING_PERIOD, getPresenceMonitoringContext(eventList)),
        new PeopleTracking(PEOPLE_TRACKING_PERIOD, getPeopleTrackingContext(eventList)),
        new ORAdvancedMonitoring(OR_ADVANCE_MONITORING_PERIOD, getORAdvancedMonitoringContext(eventList)),
        new HvacSystem(HVAC_SYSTEM_PERIOD, getHvacSystemContextOperatingRoom(eventList, currentCommand)),
        new HvacSystem(HVAC_SYSTEM_PERIOD, getHvacSystemContextPreOperatingRoom(eventList, currentCommand)),
        new AmbientLightSystem(AMBIENT_LIGHT_PERIOD, getAmbientLightSystemContextOperatingRoom(eventList, currentCommand)),
        new AmbientLightSystem(AMBIENT_LIGHT_PERIOD, getAmbientLightSystemContextPreOperatingRoom(eventList, currentCommand)),
        new ORSurgicalLightSystem(OR_SURGICAL_LIGHT_PERIOD, getORSurgicalLightSystemContext(eventList, currentCommand)),
        new GatewayExporter(GATEWAY_EXPORTER_PERIOD, getGatewayExporterContext(eventList, SerialInterface::getInstance()))
    };
    
    ArrayStream<Task*>(taskArray, TASK_NUMBER)
        .foreach([](Task* const task) {System::getInstance()->addTask(task);});
}

void loop() {
    System::getInstance()->run();
}
