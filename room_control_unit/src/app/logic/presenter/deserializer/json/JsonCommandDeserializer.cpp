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

#define BASE_DESERIALIZATION_SIZE 256

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
                    const String rawStatus = doc["status"];
                    const PowerStatus statusToSet = statusFromString(rawStatus);
                    result = new HeatingCommand(Room(roomId), statusToSet);
                break;
            }
            case static_cast<int>(CommandType::COOLING): {
                    const String roomId = doc["room_id"];
                    const String rawStatus = doc["status"];
                    const PowerStatus statusToSet = statusFromString(rawStatus);
                    result = new CoolingCommand(Room(roomId), statusToSet);
                break;
            }
            case static_cast<int>(CommandType::VENTILATION): {
                    const String roomId = doc["room_id"];
                    const int intensityPercentage = doc["status"];
                    result = new VentilationCommand(Room(roomId), Percentage(intensityPercentage));
                break;
            }
            case static_cast<int>(CommandType::AMBIENT_LIGHT): {
                    const String roomId = doc["room_id"];
                    const long intensity = doc["status"];
                    result = new AmbientLigthCommand(Room(roomId), Luminosity(intensity, LuminosityUnit::LUX));
                break;
            }
            case static_cast<int>(CommandType::SURGICAL_LIGHT): {
                    const String roomId = doc["room_id"];
                    const long intensity = doc["status"];
                    result = new SurgicalLightCommand(Room(roomId), Luminosity(intensity, LuminosityUnit::LUX));
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
