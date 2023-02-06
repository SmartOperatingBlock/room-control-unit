/*
 * Copyright (c) 2023 Smart Operating Block
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#ifndef __JSON_SERIALIZER__
#define __JSON_SERIALIZER__

#include "Arduino.h"
#include "../../../model/event/Event.h"
#include "../../../model/baseserialization/Serializer.h"
#include "../../../model/baseserialization/Serializable.h"

/**
 * Implementation of a JSON serializer for events serialization.
*/
class JsonSerializer : public Serializer {

    public:

        String serialize(Serializable *serializable);
        
        String serialize(TemperatureEvent *temperatureEvent);

        String serialize(HumidityEvent *humidityEvent);
        
        String serialize(LuminosityEvent *luminosityEvent);
        
        String serialize(PresenceEvent *presenceEvent);
        
        String serialize(ActuatorStateEvent *actuatorStateEvent);

        String serialize(PersonTrackExit *personTrackExit);

        String serialize(PersonTrack *personTrack);

        String serialize(ImplantableMedicalDeviceTrack *implantableMedicalDeviceTrack);

        String serialize(PatientOnOperatingTable *patientOnOperatingTable);

        String serialize(NewActuator *newActuator);

        String serialize(RoomEntry *roomEntry);

};

#endif