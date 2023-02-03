/*
 * Copyright (c) 2023 Smart Operating Block
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#ifndef __TEMPERATURE_HUMIDITY_MONITORING__
#define __TEMPERATURE_HUMIDITY_MONITORING__

#include "../AbstractFsm.h"
#include "../../../model/event/Event.h"
#include "../../../../utils/List.h"
#include "../../baseio/equipment/RoomEquipment.h"
#include "../../baseio/TemperatureSensor.h"
#include "../../baseio/HumiditySensor.h"

struct TemperatureHumidityMonitoringContext {
    List<Event*>* const eventList;
    int sensorCount;
    RoomEquipment<TemperatureSensor*>** temperatureSensors;
    RoomEquipment<HumiditySensor*>** humiditySensors;
};

/*
    Temperature and Humidity Monitoring task.
    Its main objective is to use the temperature and humidity sensors inside the
    different room to obtain the associated data and signal it to the system firing a new event.
*/
class TemperatureHumidityMonitoring: public AbstractFsm {
    public:
        /*
            Constructor.

            @param period the period of the fsm.
            @param context the local context of the fsm.
        */
        TemperatureHumidityMonitoring(const int period, TemperatureHumidityMonitoringContext* context);

    private:
        class M: public State {
            public:
                M(TemperatureHumidityMonitoringContext* context);
                void run(Fsm* parentFsm);
            private:
                TemperatureHumidityMonitoringContext* const context;
        };

};

#endif