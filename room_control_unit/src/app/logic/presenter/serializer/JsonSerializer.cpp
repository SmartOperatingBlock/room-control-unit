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
#include "../../../model/event/Event.h"

#define stringify( name ) #name
#define BASE_SIZE 64
#define LARGE_SIZE 128

String JsonSerializer::serialize(Serializable *serializable) {
    return serializable->accept(this);
}

String JsonSerializer::serialize(TemperatureEvent *temperatureEvent) {
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

String JsonSerializer::serialize(HumidityEvent *humidityEvent){
    String output;
    DynamicJsonDocument doc(BASE_SIZE);
    doc["type"] = static_cast<int>(humidityEvent->getType());
    doc["room_id"] = humidityEvent->getRoom().getId();
    doc["humidity_percentage"] = humidityEvent->getHumidity().getHumidityPercentage().get();
    serializeJson(doc, output);
    return output;
}
        
String JsonSerializer::serialize(LuminosityEvent *luminosityEvent){
    const char* luminosityUnitString[] = {"lumen"};
    String output;
    DynamicJsonDocument doc(LARGE_SIZE);
    doc["type"] = static_cast<int>(luminosityEvent->getType());
    doc["room_id"] = luminosityEvent->getRoom().getId();
    doc["luminosity_value"] = luminosityEvent->getLuminosity().getLuminosityValue();
    doc["luminosity_unit"] = luminosityUnitString[static_cast<int>(luminosityEvent->getLuminosity().getLuminosityUnit())];
    serializeJson(doc, output);
    return output;
}
        
String JsonSerializer::serialize(PresenceEvent *presenceEvent){
    String output;
    DynamicJsonDocument doc(BASE_SIZE);
    doc["type"] = static_cast<int>(presenceEvent->getType());
    doc["room_id"] = presenceEvent->getRoom().getId();
    doc["persone_inside"] = presenceEvent->isSomeonePresent();
    serializeJson(doc, output);
    return output;
}
        
String JsonSerializer::serialize(ActuatorStateEvent *actuatorStateEvent){
    const char* powerStatus[] = {"on", "off"};
    String output;
    DynamicJsonDocument doc(LARGE_SIZE);
    doc["type"] = static_cast<int>(actuatorStateEvent->getType());
    doc["actuator_id"] = actuatorStateEvent->getActuator()->getId();
    doc["state"] = powerStatus[static_cast<int>(actuatorStateEvent->getStatus())];
    doc["intensity_percentage"] = actuatorStateEvent->getIntensity().get();
    serializeJson(doc, output);
    return output;
}

String JsonSerializer::serialize(PersonTrackExit *personTrackExit){
    const char* personRoleString[] = {"health_professional", "patient"};
    String output;
    DynamicJsonDocument doc(LARGE_SIZE);
    doc["person_id"] = personTrackExit->getPerson().getId();
    doc["type"] = static_cast<int>(personTrackExit->getType());
    doc["person_role"] = personRoleString[static_cast<int>(personTrackExit->getPerson().getRole())];
    doc["room_id"] =  NULL;
    serializeJson(doc, output);
    return output;
}

String JsonSerializer::serialize(PersonTrack *personTrack){
    const char* personRoleString[] = {"health_professional", "patient"};
    String output;
    DynamicJsonDocument doc(LARGE_SIZE);
    doc["person_id"] = personTrack->getPerson().getId();
    doc["type"] = static_cast<int>(personTrack->getType());
    doc["person_role"] = personRoleString[static_cast<int>(personTrack->getPerson().getRole())];
    doc["room_id"] =  personTrack->getRoom().getId();
    serializeJson(doc, output);
    return output;
}

String JsonSerializer::serialize(ImplantableMedicalDeviceTrack *implantableMedicalDeviceTrack){
    const char* deviceTypeString[] = {"pace_marker"};
    String output;
    DynamicJsonDocument doc(LARGE_SIZE);
    doc["type"] = static_cast<int>(implantableMedicalDeviceTrack->getType());
    doc["device_id"] = implantableMedicalDeviceTrack->getDevice().getId();
    doc["device_type"] = deviceTypeString[static_cast<int>(implantableMedicalDeviceTrack -> getDevice().getType())];
    doc["room_id"] =  implantableMedicalDeviceTrack->getRoom().getId();
    serializeJson(doc, output);
    return output;
}

String JsonSerializer::serialize(PatientOnOperatingTable *patientOnOperatingTable){
    String output;
    DynamicJsonDocument doc(BASE_SIZE);
    doc["type"] = static_cast<int>(patientOnOperatingTable->getType());
    doc["patient_id"] = patientOnOperatingTable->getPatient().getId();
    serializeJson(doc, output);
    return output;
}

String JsonSerializer::serialize(NewActuator *newActuator){
    const char* actuatorTypeString[] = {"ventilation", "heating", "cooling", "ambient_light", "surgical_light"};
    String output;
    DynamicJsonDocument doc(LARGE_SIZE);
    doc["type"] = static_cast<int>(newActuator->getType());
    doc["actuator_id"] = newActuator->getActuator()->getId();
    doc["actuator_type"] = actuatorTypeString[static_cast<int>(newActuator->getActuator()->getType())];
    doc["room_id"] = newActuator->getRoom().getId();
    serializeJson(doc, output);
    return output;
}

String JsonSerializer::serialize(RoomEntry *roomEntry){
    String output;
    DynamicJsonDocument doc(BASE_SIZE);
    doc["type"] = static_cast<int>(roomEntry->getType());
    doc["room_id"] = roomEntry->getRoom().getId();
    serializeJson(doc, output);
    return output;
};

