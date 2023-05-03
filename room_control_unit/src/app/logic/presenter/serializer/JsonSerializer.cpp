/*
 * Copyright (c) 2023 Smart Operating Block
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#include "Arduino.h"
#include "ArduinoJson.h"
#include "JsonSerializer.h"

#define BASE_SIZE 64
#define LARGE_SIZE 128

String JsonSerializer::serialize(Serializable* const serializable) {
    return serializable->accept(this);
}

String JsonSerializer::serialize(TemperatureEvent* const temperatureEvent) {
    const char* temperatureUnitString[] = {"celsius"};
    String output;
    DynamicJsonDocument doc(BASE_SIZE);
    doc["type"] = static_cast<int>(temperatureEvent->getType());
    doc["room_id"] = temperatureEvent->getRoom().getId();
    doc["temperature_value"] = temperatureEvent->getTemperature().getTemperatureValue();
    doc["temperature_unit"] = temperatureUnitString[static_cast<int>(temperatureEvent->getTemperature().getTemperatureUnit())];
    serializeJson(doc, output);
    return output;
}

String JsonSerializer::serialize(HumidityEvent* const humidityEvent){
    String output;
    DynamicJsonDocument doc(BASE_SIZE);
    doc["type"] = static_cast<int>(humidityEvent->getType());
    doc["room_id"] = humidityEvent->getRoom().getId();
    doc["humidity_percentage"] = humidityEvent->getHumidity().getHumidityPercentage().get();
    serializeJson(doc, output);
    return output;
}
        
String JsonSerializer::serialize(LuminosityEvent* const luminosityEvent){
    const char* luminosityUnitString[] = {"lux"};
    String output;
    DynamicJsonDocument doc(LARGE_SIZE);
    doc["type"] = static_cast<int>(luminosityEvent->getType());
    doc["room_id"] = luminosityEvent->getRoom().getId();
    doc["luminosity_value"] = luminosityEvent->getLuminosity().getLuminosityValue();
    doc["luminosity_unit"] = luminosityUnitString[static_cast<int>(luminosityEvent->getLuminosity().getLuminosityUnit())];
    serializeJson(doc, output);
    return output;
}
        
String JsonSerializer::serialize(PresenceEvent* const presenceEvent){
    String output;
    DynamicJsonDocument doc(BASE_SIZE);
    doc["type"] = static_cast<int>(presenceEvent->getType());
    doc["room_id"] = presenceEvent->getRoom().getId();
    doc["persone_inside"] = presenceEvent->isSomeonePresent();
    serializeJson(doc, output);
    return output;
}
        
String JsonSerializer::serialize(ActuatorStateEvent* const actuatorStateEvent){
    const char* powerStatus[] = {"on", "off"};
    String output;
    DynamicJsonDocument doc(LARGE_SIZE);
    doc["type"] = static_cast<int>(actuatorStateEvent->getType());
    doc["actuator_id"] = actuatorStateEvent->getActuator()->getId();
    doc["state"] = powerStatus[static_cast<int>(actuatorStateEvent->getStatus())];
    doc["intensity"] = actuatorStateEvent->getIntensity();
    serializeJson(doc, output);
    return output;
}

String JsonSerializer::serialize(PersonTrackExit* const personTrackExit){
    const char* personRoleString[] = {"health_professional", "patient"};
    String output;
    DynamicJsonDocument doc(LARGE_SIZE);
    doc["type"] = static_cast<int>(personTrackExit->getType());
    doc["person_id"] = personTrackExit->getPerson().getId();
    doc["person_role"] = personRoleString[static_cast<int>(personTrackExit->getPerson().getRole())];
    doc["room_id"] =  nullptr;
    serializeJson(doc, output);
    return output;
}

String JsonSerializer::serialize(PersonTrack* const personTrack){
    const char* personRoleString[] = {"health_professional", "patient"};
    String output;
    DynamicJsonDocument doc(LARGE_SIZE);
    doc["type"] = static_cast<int>(personTrack->getType());
    doc["person_id"] = personTrack->getPerson().getId();
    doc["person_role"] = personRoleString[static_cast<int>(personTrack->getPerson().getRole())];
    doc["room_id"] = personTrack->getRoom().getId();
    serializeJson(doc, output);
    return output;
}

String JsonSerializer::serialize(ImplantableMedicalDeviceTrack* const implantableMedicalDeviceTrack){
    const char* deviceTypeString[] = {"pace_marker"};
    String output;
    DynamicJsonDocument doc(LARGE_SIZE);
    doc["type"] = static_cast<int>(implantableMedicalDeviceTrack->getType());
    doc["device_id"] = implantableMedicalDeviceTrack->getDevice().getId();
    doc["device_type"] = deviceTypeString[static_cast<int>(implantableMedicalDeviceTrack -> getDevice().getType())];
    doc["room_id"] = implantableMedicalDeviceTrack->getRoom().getId();
    serializeJson(doc, output);
    return output;
}

String JsonSerializer::serialize(PatientOnOperatingTable* const patientOnOperatingTable){
    String output;
    DynamicJsonDocument doc(BASE_SIZE);
    doc["type"] = static_cast<int>(patientOnOperatingTable->getType());
    doc["room_id"] = patientOnOperatingTable->getRoom().getId();
    serializeJson(doc, output);
    return output;
}

String JsonSerializer::serialize(NewActuator* const newActuator){
    String output;
    DynamicJsonDocument doc(LARGE_SIZE);
    doc["type"] = static_cast<int>(newActuator->getType());
    doc["actuator_id"] = newActuator->getActuator()->getId();
    doc["actuator_type"] = static_cast<int>(newActuator->getActuator()->getType());
    doc["room_id"] = newActuator->getRoom().getId();
    serializeJson(doc, output);
    return output;
}

String JsonSerializer::serialize(RoomEntry* const roomEntry){
    String output;
    DynamicJsonDocument doc(BASE_SIZE);
    doc["type"] = static_cast<int>(roomEntry->getType());
    doc["room_id"] = roomEntry->getRoom().getId();
    serializeJson(doc, output);
    return output;
};

