/*
 * Copyright (c) 2023 Smart Operating Block
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#ifndef __SERIALIZER__
#define __SERIALIZER__

#include "Arduino.h"
#include "../event/Event.h"
#include "Serializable.h"

class Serializable;
class TemperatureEvent;
class HumidityEvent;
class LuminosityEvent;
class PresenceEvent;
class ActuatorStateEvent;
class PersonTrackExit;
class PersonTrack;
class ImplantableMedicalDeviceTrack;
class PatientOnOperatingTable;
class NewActuator;
class RoomEntry;


/**
 * Interface that model a visitor for events.
*/
class Serializer {

    public:

        /*
          The dispatching function.

          @return a String with the serialized event.
        */
        virtual String serialize(Serializable *serializable) = 0;

        /*
          Serialize this specific event.

          @return a String with the serialized event.
        */
        virtual String serialize(TemperatureEvent *temperatureEvent) = 0;

        /*
          Serialize this specific event.

          @return a String with the serialized event.
        */
        virtual String serialize(HumidityEvent *humidityEvent) = 0;

        /*
          Serialize this specific event.

          @return a String with the serialized event.
        */
        virtual String serialize(LuminosityEvent *luminosityEvent) = 0;

        /*
          Serialize this specific event.

          @return a String with the serialized event.
        */
        virtual String serialize(PresenceEvent *presenceEvent) = 0;

        /*
          Serialize this specific event.

          @return a String with the serialized event.
        */
        virtual String serialize(ActuatorStateEvent *actuatorStateEvent) = 0;

        /*
          Serialize this specific event.

          @return a String with the serialized event.
        */
        virtual String serialize(PersonTrackExit *personTrackExit) = 0;

        /*
          Serialize this specific event.

          @return a String with the serialized event.
        */
        virtual String serialize(PersonTrack *personTrack) = 0;

        /*
          Serialize this specific event.

          @return a String with the serialized event.
        */
        virtual String serialize(ImplantableMedicalDeviceTrack *implantableMedicalDeviceTrack) = 0;

        /*
          Serialize this specific event.

          @return a String with the serialized event.
        */
        virtual String serialize(PatientOnOperatingTable *patientOnOperatingTable) = 0;

        /*
          Serialize this specific event.

          @return a String with the serialized event.
        */
        virtual String serialize(NewActuator *newActuator) = 0;

        /*
          Serialize this specific event.

          @return a String with the serialized event.
        */
        virtual String serialize(RoomEntry *roomEntry) = 0;

};

#endif