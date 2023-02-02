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
#include "../../model/event/Event.h"

#define stringify( name ) #name

String JsonSerializer::serialize(Serializable *serializable) {
    return serializable->accept(this);
}

String JsonSerializer::serialize(TemperatureEvent *temperatureEvent) {

    String output;
    DynamicJsonDocument doc(JSON_OBJECT_SIZE(4));
    doc["type"] = static_cast<int>(temperatureEvent->getType());
    doc["room_id"] = temperatureEvent->getRoom().getId();
    doc["temperature_value"] = temperatureEvent->getTemperature().getTemperatureValue();
    doc["temperature_unit"] = stringify(temperatureEvent->getTemperature().getTemperatureUnit());
    serializeJson(doc, output);
    return output;

}

String JsonSerializer::serialize(HumidityEvent *humidityEvent){
    
    String output;
    DynamicJsonDocument doc(JSON_OBJECT_SIZE(3));
    doc["type"] = static_cast<int>(humidityEvent->getType());
    doc["room_id"] = humidityEvent->getRoom().getId();
    doc["humidity_percentage"] = humidityEvent->getHumidity().getHumidityPercentage().get();
    serializeJson(doc, output);
    return output;
}
        
String JsonSerializer::serialize(LuminosityEvent *luminosityEvent){

    String output;
    DynamicJsonDocument doc(JSON_OBJECT_SIZE(4));
    doc["type"] = static_cast<int>(luminosityEvent->getType());
    doc["room_id"] = luminosityEvent->getRoom().getId();
    doc["luminosity_value"] = luminosityEvent->getLuminosity().getLuminosityValue();
    doc["luminosity_unit"] = stringify(luminosityEvent->getLuminosity().getLuminosityUnit());
    serializeJson(doc, output);
    return output;
}
        
String JsonSerializer::serialize(PresenceEvent *presenceEvent){
    
    String output;
    DynamicJsonDocument doc(JSON_OBJECT_SIZE(3));
    doc["type"] = static_cast<int>(presenceEvent->getType());
    doc["room_id"] = presenceEvent->getRoom().getId();
    doc["persone_inside"] = presenceEvent->isSomeonePresent();
    serializeJson(doc, output);
    return output;
}
        
String JsonSerializer::serialize(ActuatorStateEvent *actuatorStateEvent){
    
    String output;
    DynamicJsonDocument doc(JSON_OBJECT_SIZE(4));
    doc["type"] = static_cast<int>(actuatorStateEvent->getType());
    doc["actuator_id"] = actuatorStateEvent->getActuator()->getId();
    doc["state"] = stringify(actuatorStateEvent->getStatus());
    doc["intensity_percentage"] = actuatorStateEvent->getIntensity().get();
    serializeJson(doc, output);
    return output;
}

String JsonSerializer::serialize(PersonTrackExit *personTrackExit){

    String output;
    DynamicJsonDocument doc(JSON_OBJECT_SIZE(4));
    doc["person_id"] = personTrackExit->getPerson().getId();
    doc["type"] = static_cast<int>(personTrackExit->getType());
    doc["person_role"] = stringify(personTrackExit->getPerson().getRole());
    doc["room_id"] =  NULL;
    serializeJson(doc, output);
    return output;
}

String JsonSerializer::serialize(PersonTrack *personTrack){
    String output;
    DynamicJsonDocument doc(JSON_OBJECT_SIZE(4));
    doc["person_id"] = personTrack->getPerson().getId();
    doc["type"] = static_cast<int>(personTrack->getType());
    doc["person_role"] = stringify(personTrack->getPerson().getRole());
    doc["room_id"] =  personTrack->getRoom().getId();
    serializeJson(doc, output);
    return output;
}

String JsonSerializer::serialize(ImplantableMedicalDeviceTrack *implantableMedicalDeviceTrack){

    String output;
    DynamicJsonDocument doc(JSON_OBJECT_SIZE(4));
    doc["type"] = static_cast<int>(implantableMedicalDeviceTrack->getType());
    doc["device_id"] = implantableMedicalDeviceTrack->getDevice().getId();
    doc["device_type"] = stringify(implantableMedicalDeviceTrack -> getDevice().getType());
    doc["room_id"] =  implantableMedicalDeviceTrack->getRoom().getId();
    serializeJson(doc, output);
    return output;
}

String JsonSerializer::serialize(PatientOnOperatingTable *patientOnOperatingTable){
    String output;
    DynamicJsonDocument doc(JSON_OBJECT_SIZE(2));
    doc["type"] = static_cast<int>(patientOnOperatingTable->getType());
    doc["patient_id"] = patientOnOperatingTable->getPatient().getId();
    serializeJson(doc, output);
    return output;
}

String JsonSerializer::serialize(NewActuator *newActuator){
    String output;
    DynamicJsonDocument doc(JSON_OBJECT_SIZE(4));
    doc["type"] = static_cast<int>(newActuator->getType());
    doc["actuator_id"] = newActuator->getActuator()->getId();
    doc["actuator_type"] = stringify(newActuator->getActuator()->getType());
    doc["room_id"] = newActuator->getRoom().getId();
    serializeJson(doc, output);
    return output;
}

String JsonSerializer::serialize(RoomEntry *roomEntry){
    String output;
    DynamicJsonDocument doc(JSON_OBJECT_SIZE(2));
    doc["type"] = static_cast<int>(roomEntry->getType());
    doc["room_id"] = roomEntry->getRoom().getId();
    serializeJson(doc, output);
    return output;
};

