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
#include "../app/logic/baseio/equipment/RoomEquipment.h"
#include "../app/logic/baseio/TemperatureSensor.h"
#include "../app/io/environment/TemperatureHumiditySensor.h"
#include "../app/logic/baseio/HumiditySensor.h"
#include "../app/model/event/Event.h"
#include "../app/logic/fsm/thmonitoring/TemperatureHumidityMonitoring.h"



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

    return new TemperatureHumidityMonitoringContext{
        eventList,
        2,
        temperatureSensors,
        humiditySensors
    };
}


#endif