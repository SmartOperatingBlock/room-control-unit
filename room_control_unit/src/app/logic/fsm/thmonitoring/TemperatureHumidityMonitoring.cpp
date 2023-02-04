/*
 * Copyright (c) 2023 Smart Operating Block
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#include "TemperatureHumidityMonitoring.h"
#include "../../../../utils/ArrayStream.h"
#include "../../../model/event/Event.h"

TemperatureHumidityMonitoring::TemperatureHumidityMonitoring(const int period, TemperatureHumidityMonitoringContext* const context): AbstractFsm(period), context(context) {
    this->changeState(new M(context));
}

TemperatureHumidityMonitoring::~TemperatureHumidityMonitoring() {
    delete this->context;
}

/*
##############################################################################
------------------State of TemperatureHumidityMonitoring FSM ---------------
##############################################################################
*/

TemperatureHumidityMonitoring::M::M(TemperatureHumidityMonitoringContext* const context): context(context) {}

void TemperatureHumidityMonitoring::M::run(Fsm* const parentFsm) {
    ArrayStream<RoomEquipment<TemperatureSensor*>*>(this->context->temperatureSensors, this->context->sensorCount)
        .foreach([this](RoomEquipment<TemperatureSensor*>* equipment) {
             Temperature temperature = equipment->getTool()->getTemperature();
             this->context->eventList->add(new TemperatureEvent(equipment->getRoom(), temperature));
        });

    ArrayStream<RoomEquipment<HumiditySensor*>*>(this->context->humiditySensors, this->context->sensorCount)
        .foreach([this](RoomEquipment<HumiditySensor*>* equipment) {
             Humidity humidity = equipment->getTool()->getHumidity();
             this->context->eventList->add(new HumidityEvent(equipment->getRoom(), humidity));
        });
}