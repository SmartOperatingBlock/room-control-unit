/*
 * Copyright (c) 2023 Smart Operating Block
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#include "JsonCommandDeserializer.h"
#include "Arduino.h"
#include "ArduinoJson.h"

#define BASE_DESERIALIZATION_SIZE 64

JsonCommandDeserializer::JsonCommandDeserializer() {};

Command* JsonCommandDeserializer::deserialize(const String rawCommand) {
    DynamicJsonDocument doc(BASE_DESERIALIZATION_SIZE);
    const DeserializationError error = deserializeJson(doc, rawCommand);
    Command* result = nullptr;
    
    // Check if the deserialization has been successful.
    if(!error) {
        const int commandType = doc["command"];
        switch(commandType) {
            case static_cast<int>(CommandType::HEATING): {
                    const String roomId = doc["room_id"];
                    const PowerStatus statusToSet = statusFromString(doc["on"]);
                    result = new HeatingCommand(Room(roomId), statusToSet);
                break;
            }
            case static_cast<int>(CommandType::COOLING): {
                    const String roomId = doc["room_id"];
                    const PowerStatus statusToSet = statusFromString(doc["on"]);
                    result = new CoolingCommand(Room(roomId), statusToSet);
                break;
            }
            case static_cast<int>(CommandType::VENTILATION): {
                    const String roomId = doc["room_id"];
                    const int intensityPercentage = doc["intensity"];
                    result = new VentilationCommand(Room(roomId), Percentage(intensityPercentage));
                break;
            }
            case static_cast<int>(CommandType::AMBIENT_LIGHT): {
                    const String roomId = doc["room_id"];
                    const int intensityPercentage = doc["intensity"];
                    result = new AmbientLigthCommand(Room(roomId), Percentage(intensityPercentage));
                break;
            }
            case static_cast<int>(CommandType::SURGICAL_LIGHT): {
                    const String roomId = doc["room_id"];
                    const int intensityPercentage = doc["intensity"];
                    result = new SurgicalLightCommand(Room(roomId), Percentage(intensityPercentage));
                break;
            }
            default:
                break;
        }
    }

    return result;
}

PowerStatus JsonCommandDeserializer::statusFromString(const String rawStatus) {
    return rawStatus == "on" ? PowerStatus::ON : PowerStatus::OFF;
}
