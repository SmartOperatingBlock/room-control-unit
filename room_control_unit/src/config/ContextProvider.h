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
#include "../app/io/environment/SurgicalLightImpl.h"
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
#include "../app/logic/fsm/orsurgicalightsystem/ORSurgicalLightSystem.h"
#include "../app/logic/handshake/DiscoveryTask.h"

#define ROOM_COUNT 2
#define ACTUATOR_COUNT 9

// Declare actuators
// Actuators can be shared by different tasks, so we could need them in different context.
static VentilationSystem* const  ventilationSystemOR = new VentilationSystem(VENTILATION_OR_ID, VENTILATION_OR_PIN);
static HeatingModule* const heatingModuleOR = new HeatingModule(HEATING_OR_ID, HEATING_OR_PIN);
static CoolingModule* const coolingModuleOR = new CoolingModule(COOLING_OR_ID, COOLING_OR_PIN);
static VentilationSystem* const ventilationSystemPRE = new VentilationSystem(VENTILATION_PRE_ID, VENTILATION_PRE_PIN);
static HeatingModule* const heatingModulePRE = new HeatingModule(HEATING_PRE_ID, HEATING_PRE_PIN);
static CoolingModule* const coolingModulePRE = new CoolingModule(COOLING_PRE_ID, COOLING_PRE_PIN);
static LightImpl* const ambientLightOR = new LightImpl(AMBIENT_LIGHT_OR_ID, AMBIENT_LIGHT_OR_PIN);
static LightImpl* const ambientLightPRE = new LightImpl(AMBIENT_LIGHT_PRE_ID, AMBIENT_LIGHT_PRE_PIN);
static SurgicalLightImpl* const surgicalLightOR = new SurgicalLightImpl(SURGICAL_LIGHT_ID, SURGICAL_LIGHT_PIN);


// Declaring different contexts.

TemperatureHumidityMonitoringContext* getTemperatureHumidityMonitoringContext(List<Event*>* const eventList) {
    TemperatureHumiditySensor* const thOR = new TemperatureHumiditySensor(TEMPERATURE_HUMIDITY_OR);
    TemperatureHumiditySensor* const thPRE = new TemperatureHumiditySensor(TEMPERATURE_HUMIDITY_PRE);

    RoomEquipment<TemperatureSensor*>** const temperatureSensors = new RoomEquipment<TemperatureSensor*>*[ROOM_COUNT] {
            new RoomEquipment<TemperatureSensor*>(thOR, Room(OPERATING_ROOM_ID)),
            new RoomEquipment<TemperatureSensor*>(thPRE, Room(PRE_OPERATING_ROOM_ID))
    };

    RoomEquipment<HumiditySensor*>** const humiditySensors = new RoomEquipment<HumiditySensor*>*[ROOM_COUNT] {
            new RoomEquipment<HumiditySensor*>(thOR, Room(OPERATING_ROOM_ID)),
            new RoomEquipment<HumiditySensor*>(thPRE, Room(PRE_OPERATING_ROOM_ID))
    };

    return new TemperatureHumidityMonitoringContext {
        eventList,
        ROOM_COUNT,
        temperatureSensors,
        humiditySensors
    };
}

GatewayExporterContext* getGatewayExporterContext(List<Event*>* const eventList, ExternalGateway* const gateway) {
    return new GatewayExporterContext {eventList, gateway};
}

LuminosityMonitoringContext* getLuminosityMonitoringContext(List<Event*>* const eventList) {
    LuminositySensor* const lOR = new EnvironmentLuminositySensor(LUMINOSITY_SENSOR_OR);
    LuminositySensor* const lPRE = new EnvironmentLuminositySensor(LUMINOSITY_SENSOR_PRE);

    RoomEquipment<LuminositySensor*>** const luminositySensors = new RoomEquipment<LuminositySensor*>*[ROOM_COUNT] {
            new RoomEquipment<LuminositySensor*>(lOR, Room(OPERATING_ROOM_ID)),
            new RoomEquipment<LuminositySensor*>(lPRE, Room(PRE_OPERATING_ROOM_ID))
    };

    return new LuminosityMonitoringContext {
        eventList,
        ROOM_COUNT,
        luminositySensors
    };
}

PresenceMonitoringContext* getPresenceMonitoringContext(List<Event*>* const eventList) {
    PresenceSensor* const pOR = new PeoplePresenceSensor(PRESENCE_SENSOR_OR);
    PresenceSensor* const pPRE = new PeoplePresenceSensor(PRESENCE_SENSOR_PRE);

    RoomEquipment<PresenceSensor*>** const presenceSensors = new RoomEquipment<PresenceSensor*>*[ROOM_COUNT] {
            new RoomEquipment<PresenceSensor*>(pOR, Room(OPERATING_ROOM_ID)),
            new RoomEquipment<PresenceSensor*>(pPRE, Room(PRE_OPERATING_ROOM_ID))
    };

    return new PresenceMonitoringContext {
        eventList,
        ROOM_COUNT,
        presenceSensors
    };
}

PeopleTrackingContext* getPeopleTrackingContext(List<Event*>* const eventList) {
    PersonTracker** const personTrackers = new PersonTracker*[ROOM_COUNT] {
        new PersonTrackerImpl(ENTRANCE_READER_OR, READER_RESET_PIN, new Room(PRE_OPERATING_ROOM_ID), new Room(OPERATING_ROOM_ID)),
        new PersonTrackerImpl(ENTRANCE_READER_PRE, READER_RESET_PIN, nullptr, new Room(PRE_OPERATING_ROOM_ID))
    };

    return new PeopleTrackingContext {
        eventList,
        ROOM_COUNT,
        personTrackers
    };
}

ORAdvancedMonitoringContext* getORAdvancedMonitoringContext(List<Event*>* const eventList) {
    return new ORAdvancedMonitoringContext {
        eventList,
        Room(OPERATING_ROOM_ID),
        new StretcherPressureSensor(OPERATING_TABLE_PRESSURE_SENSOR),
        new ImplantableMedicalDeviceTrackerImpl(IMPLANTABLE_MEDICAL_DEVICE_BIN, READER_RESET_PIN)
    };
}

CommandListenerContext* getCommandListenerContext(DataProvider* const dataProvider, Command** const currentCommand) {
    return new CommandListenerContext {
        dataProvider,
        currentCommand
    };
}

HvacSystemContext* getHvacSystemContextOperatingRoom(List<Event*>* const eventList, Command** const currentCommand) {
    return new HvacSystemContext {
        eventList,
        currentCommand,
        Room(OPERATING_ROOM_ID),
        ventilationSystemOR,
        heatingModuleOR,
        coolingModuleOR
    };
}

HvacSystemContext* getHvacSystemContextPreOperatingRoom(List<Event*>* const eventList, Command** const currentCommand) {
    return new HvacSystemContext {
        eventList,
        currentCommand,
        Room(PRE_OPERATING_ROOM_ID),
        ventilationSystemPRE,
        heatingModulePRE,
        coolingModulePRE
    };
}

AmbientLightSystemContext* getAmbientLightSystemContextOperatingRoom(List<Event*>* const eventList, Command** const currentCommand) {
    return new AmbientLightSystemContext {
        eventList,
        currentCommand,
        Room(OPERATING_ROOM_ID),
        ambientLightOR        
    };
}

AmbientLightSystemContext* getAmbientLightSystemContextPreOperatingRoom(List<Event*>* const eventList, Command** const currentCommand) {
    return new AmbientLightSystemContext {
        eventList,
        currentCommand,
        Room(PRE_OPERATING_ROOM_ID),
        ambientLightPRE
    };
}

ORSurgicalLightSystemContext* getORSurgicalLightSystemContext(List<Event*>* const eventList, Command** const currentCommand) {
    return new ORSurgicalLightSystemContext {
        eventList,
        currentCommand,
        Room(OPERATING_ROOM_ID),
        surgicalLightOR
    };
}

DiscoveryTaskContext* getDiscoveryTaskContext(List<Event*>* const eventList) {
    return new DiscoveryTaskContext {
        eventList,
        new Room[ROOM_COUNT] { Room(OPERATING_ROOM_ID), Room(PRE_OPERATING_ROOM_ID) },
        ROOM_COUNT,
        new RoomEquipment<Actuator*>*[ACTUATOR_COUNT] {
            new RoomEquipment<Actuator*>(ventilationSystemOR, Room(OPERATING_ROOM_ID)),
            new RoomEquipment<Actuator*>(heatingModuleOR, Room(OPERATING_ROOM_ID)),
            new RoomEquipment<Actuator*>(coolingModuleOR, Room(OPERATING_ROOM_ID)),
            new RoomEquipment<Actuator*>(ventilationSystemPRE, Room(PRE_OPERATING_ROOM_ID)),
            new RoomEquipment<Actuator*>(heatingModulePRE, Room(PRE_OPERATING_ROOM_ID)),
            new RoomEquipment<Actuator*>(coolingModulePRE, Room(PRE_OPERATING_ROOM_ID)),
            new RoomEquipment<Actuator*>(ambientLightOR, Room(OPERATING_ROOM_ID)),
            new RoomEquipment<Actuator*>(ambientLightPRE, Room(PRE_OPERATING_ROOM_ID)),
            new RoomEquipment<Actuator*>(surgicalLightOR, Room(OPERATING_ROOM_ID)),
        },
        ACTUATOR_COUNT
    };
}

#endif