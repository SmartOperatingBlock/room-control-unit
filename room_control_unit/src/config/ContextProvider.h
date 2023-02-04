/*
 * Copyright (c) 2023 Smart Operating Block
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#ifndef __CONTEXT_PROVIDER__
#define __CONTEXT_PROVIDER__

#include "PinList.h"
#include "RoomId.h"
#include "../utils/List.h"
#include "../config/ActuatorId.h"
#include "../app/logic/baseio/equipment/RoomEquipment.h"
#include "../app/logic/baseio/TemperatureSensor.h"
#include "../app/io/environment/TemperatureHumiditySensor.h"
#include "../app/io/environment/EnvironmentLuminositySensor.h"
#include "../app/io/environment/PeoplePresenceSensor.h"
#include "../app/io/tracking/PersonTrackerImpl.h"
#include "../app/io/tracking/ImplantableMedicalDeviceTrackerImpl.h"
#include "../app/io/stretcher/StretcherPressureSensor.h"
#include "../app/io/environment/CoolingModule.h"
#include "../app/io/environment/HeatingModule.h"
#include "../app/io/environment/VentilationSystem.h"
#include "../app/io/environment/LightImpl.h"
#include "../app/logic/baseio/HumiditySensor.h"
#include "../app/logic/baseio/PresenceSensor.h"
#include "../app/model/event/Event.h"
#include "../app/logic/fsm/thmonitoring/TemperatureHumidityMonitoring.h"
#include "../app/logic/fsm/gatewayexporter/GatewayExporter.h"
#include "../app/logic/fsm/luminositymonitoring/LuminosityMonitoring.h"
#include "../app/logic/fsm/presencemonitoring/PresenceMonitoring.h"
#include "../app/logic/fsm/peopletracking/PeopleTracking.h"
#include "../app/logic/fsm/oradvancedmonitoring/ORAdvancedMonitoring.h"
#include "../app/logic/fsm/commandlistener/CommandListener.h"
#include "../app/logic/fsm/hvacsystem/HvacSystem.h"
#include "../app/logic/fsm/ambientlightsystem/AmbientLightSystem.h"



TemperatureHumidityMonitoringContext* getTemperatureHumidityMonitoringContext(List<Event*>* eventList) {
    TemperatureHumiditySensor* thOR = new TemperatureHumiditySensor(TEMPERATURE_HUMIDITY_OR);
    TemperatureHumiditySensor* thPRE = new TemperatureHumiditySensor(TEMPERATURE_HUMIDITY_PRE);

    RoomEquipment<TemperatureSensor*>** temperatureSensors = new RoomEquipment<TemperatureSensor*>*[2] {
            new RoomEquipment<TemperatureSensor*>(thOR, Room(OPERATING_ROOM_ID)),
            new RoomEquipment<TemperatureSensor*>(thPRE, Room(PRE_OPERATING_ROOM_ID))
    };

    RoomEquipment<HumiditySensor*>** humiditySensors = new RoomEquipment<HumiditySensor*>*[2] {
            new RoomEquipment<HumiditySensor*>(thOR, Room(OPERATING_ROOM_ID)),
            new RoomEquipment<HumiditySensor*>(thPRE, Room(PRE_OPERATING_ROOM_ID))
    };

    return new TemperatureHumidityMonitoringContext {
        eventList,
        2,
        temperatureSensors,
        humiditySensors
    };
}

GatewayExporterContext* getGatewayExporterContext(List<Event*>* eventList, ExternalGateway* gateway) {
    return new GatewayExporterContext {eventList, gateway};
}

LuminosityMonitoringContext* getLuminosityMonitoringContext(List<Event*>* eventList) {
    LuminositySensor* lOR = new EnvironmentLuminositySensor(LUMINOSITY_SENSOR_OR);
    LuminositySensor* lPRE = new EnvironmentLuminositySensor(LUMINOSITY_SENSOR_PRE);

    RoomEquipment<LuminositySensor*>** luminositySensors = new RoomEquipment<LuminositySensor*>*[2] {
            new RoomEquipment<LuminositySensor*>(lOR, Room(OPERATING_ROOM_ID)),
            new RoomEquipment<LuminositySensor*>(lPRE, Room(PRE_OPERATING_ROOM_ID))
    };

    return new LuminosityMonitoringContext {
        eventList,
        2,
        luminositySensors
    };
}

PresenceMonitoringContext* getPresenceMonitoringContext(List<Event*>* eventList) {
    PresenceSensor* pOR = new PeoplePresenceSensor(PRESENCE_SENSOR_OR);
    PresenceSensor* pPRE = new PeoplePresenceSensor(PRESENCE_SENSOR_PRE);

    RoomEquipment<PresenceSensor*>** presenceSensors = new RoomEquipment<PresenceSensor*>*[2] {
            new RoomEquipment<PresenceSensor*>(pOR, Room(OPERATING_ROOM_ID)),
            new RoomEquipment<PresenceSensor*>(pPRE, Room(PRE_OPERATING_ROOM_ID))
    };

    return new PresenceMonitoringContext {
        eventList,
        2,
        presenceSensors
    };
}

PeopleTrackingContext* getPeopleTrackingContext(List<Event*>* eventList) {
    PersonTracker** personTrackers = new PersonTracker*[2] {
        new PersonTrackerImpl(ENTRANCE_READER_OR, READER_RESET_PIN, new Room(PRE_OPERATING_ROOM_ID), new Room(OPERATING_ROOM_ID)),
        new PersonTrackerImpl(ENTRANCE_READER_PRE, READER_RESET_PIN, nullptr, new Room(PRE_OPERATING_ROOM_ID))
    };

    return new PeopleTrackingContext {
        eventList,
        2,
        personTrackers
    };
}

ORAdvancedMonitoringContext* getORAdvancedMonitoringContext(List<Event*>* eventList) {
    return new ORAdvancedMonitoringContext {
        eventList,
        Room(OPERATING_ROOM_ID),
        new StretcherPressureSensor(OPERATING_TABLE_PRESSURE_SENSOR),
        new ImplantableMedicalDeviceTrackerImpl(IMPLANTABLE_MEDICAL_DEVICE_BIN, READER_RESET_PIN)
    };
}

CommandListenerContext* getCommandListenerContext(DataProvider* dataProvider, Command** currentCommand) {
    return new CommandListenerContext {
        dataProvider,
        currentCommand
    };
}

HvacSystemContext* getHvacSystemContextOperatingRoom(List<Event*>* eventList, Command** currentCommand) {
    return new HvacSystemContext {
        eventList,
        currentCommand,
        Room(OPERATING_ROOM_ID),
        new VentilationSystem(VENTILATION_OR_ID, VENTILATION_OR_PIN),
        new HeatingModule(HEATING_OR_ID, HEATING_OR_PIN),
        new CoolingModule(COOLING_OR_ID, COOLING_OR_PIN)
    };
}

HvacSystemContext* getHvacSystemContextPreOperatingRoom(List<Event*>* eventList, Command** currentCommand) {
    return new HvacSystemContext {
        eventList,
        currentCommand,
        Room(PRE_OPERATING_ROOM_ID),
        new VentilationSystem(VENTILATION_PRE_ID, VENTILATION_PRE_PIN),
        new HeatingModule(HEATING_PRE_ID, HEATING_PRE_PIN),
        new CoolingModule(COOLING_PRE_ID, COOLING_PRE_PIN)
    };
}

AmbientLightSystemContext* getAmbientLightContextOperatingRoom(List<Event*>* eventList, Command** currentCommand) {
    return new AmbientLightSystemContext {
        eventList,
        currentCommand,
        Room(OPERATING_ROOM_ID),
        new LightImpl(AMBIENT_LIGHT_OR_ID, AMBIENT_LIGHT_OR_PIN)
    };
}

AmbientLightSystemContext* getAmbientLightContextPreOperatingRoom(List<Event*>* eventList, Command** currentCommand) {
    return new AmbientLightSystemContext {
        eventList,
        currentCommand,
        Room(PRE_OPERATING_ROOM_ID),
        new LightImpl(AMBIENT_LIGHT_PRE_ID, AMBIENT_LIGHT_PRE_PIN)
    };
}

#endif