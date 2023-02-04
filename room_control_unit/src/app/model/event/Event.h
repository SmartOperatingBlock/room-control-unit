/*
 * Copyright (c) 2023 Smart Operating Block
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#ifndef __EVENT__
#define __EVENT__

#include "../Temperature.h"
#include "../Humidity.h"
#include "../Luminosity.h"
#include "../Person.h"
#include "../Room.h"
#include "../ImplantableMedicalDevice.h"
#include "../PowerStatus.h"
#include "../Actuator.h"
#include "../Percentage.h"
#include "../baseserialization/Serializer.h"
#include "../baseserialization/Serializable.h"


enum class EventType {
    ROOM,
    ACTUATOR_STATE,
    PERSON_TRACKING,
    IMPLANTABLE_MEDICAL_DEVICE_TRACKING,
    PATIENT_ON_OPERATING_TABLE,
    NEW_ACTUATOR,
    ROOM_ENTRY
};

/*
    Interface that models an Event of the system.
*/
class Event : public Serializable {
    public:
        /*
            Get the event type.

            @return the event type.
        */
        virtual EventType getType() = 0;
        virtual ~Event() {}
};

class AbstractEvent: public Event {
    public:
        /*
            Constructor.

            @param eventType the type of the event.
        */
        AbstractEvent(const EventType eventType): eventType(eventType) {}

        EventType getType() {
            return this->eventType;
        }
    private:
        const EventType eventType;
};

/*
    It represents an event in which the interested room is important.
*/
class RoomEvent: public AbstractEvent {
    public:
        /*
            Get the room of the event.

            @return the room.
        */
        Room getRoom() {
            return this->room;
        }
    
    protected:
        /*
            Constructor.
            This constructor set as default event type the EventType::ROOM one.

            @param room the room in which the event is occurred.
        */
        RoomEvent(const Room room): RoomEvent(room, EventType::ROOM) {}

        /*
            Constructor.

            @param room the room in which the event is occurred.
            @param eventType the type of the event occured in that room.
        */
        RoomEvent(const Room room, const EventType eventType): AbstractEvent(eventType), room(room) {}
        
    private:
        const Room room;
};


/*
    It represents a change in the temperature inside a room.
*/
class TemperatureEvent: public RoomEvent {
    public:
        /*
            Constructor.

            @param room the room in which the event is occurred.
            @param temperature the temperature of the room.
        */
        TemperatureEvent(const Room room, const Temperature temperature): RoomEvent(room), temperature(temperature) {}

        /*
            Get the temperature that is inside this event.

            @return the temperature.
        */
        Temperature getTemperature() {
            return this->temperature;
        }

        String accept(Serializer *serializer) {
            return serializer->serialize(this);
        }

    private:
        const Temperature temperature;
};

/*
    It represents a change in the humidity inside a room.
*/
class HumidityEvent: public RoomEvent {
    public:
        /*
            Constructor.

            @param room the room in which the event is occurred.
            @param humidity the humidity of the room.
        */
        HumidityEvent(const Room room, const Humidity humidity): RoomEvent(room), humidity(humidity) {}

        /*
            Get the humidity that is inside this event.

            @return the humidity.
        */
        Humidity getHumidity() {
            return this->humidity;
        }

        String accept(Serializer *serializer) {
            return serializer->serialize(this);
        }
    private:
        const Humidity humidity;
};

/*
    It represents a change in the luminosity inside a room.
*/
class LuminosityEvent: public RoomEvent {
    public:
        /*
            Constructor.

            @param room the room in which the event is occurred.
            @param luminosity the luminosity of the room.
        */
        LuminosityEvent(const Room room, const Luminosity luminosity): RoomEvent(room), luminosity(luminosity) {}

        /*
            Get the luminosity that is inside this event.

            @return the luminosity.
        */
        Luminosity getLuminosity() {
            return this->luminosity;
        }

        String accept(Serializer *serializer) {
            return serializer->serialize(this);
        }

    private:
        const Luminosity luminosity;
};

/*
    It represents an event in which a presence is detected inside a room.
*/
class PresenceEvent: public RoomEvent {
    public:
        /*
            Constructor.

            @param room the room in which the event is occurred.
        */
        PresenceEvent(const Room room, const bool isPresent): RoomEvent(room), isPresent(isPresent) {}

        /*
            Check is the event signal the presence of the absence in the room.

            @return true if someone is in the room, false otherwise.
        */
        bool isSomeonePresent() {
            return this->isPresent;
        }

        String accept(Serializer *serializer) {
            return serializer->serialize(this);
        }
    private:
        const bool isPresent;
};

/*
    It represents an event in which an actuator has update its state.
*/
class ActuatorStateEvent: public AbstractEvent {
    public:
        /*
            Constructor.

            @param actuator the interested actuator.
            @param status the status of the actuator.
            @param intensity the intensity of work of the actuator.
        */
        ActuatorStateEvent(Actuator* const actuator, const PowerStatus status, const Percentage intensityPercentage):
            AbstractEvent(EventType::ACTUATOR_STATE), actuator(actuator), status(status), intensityPercentage(intensityPercentage) {}
        
        ActuatorStateEvent(Actuator* const actuator, const PowerStatus status): 
            ActuatorStateEvent(actuator, status, status == PowerStatus::ON ? Percentage(100) : Percentage(0)) {}

        /*
            Get the actuator.

            @return the actuator.
        */
        Actuator* getActuator() {
            return this->actuator;
        }

        /*
            Get the status.

            @return the status.
        */
        PowerStatus getStatus() {
            return this->status;
        }

        /*
            Get the intensity.

            @return the insity.
        */
        Percentage getIntensity() {
            return this->intensityPercentage;
        }

        String accept(Serializer *serializer) {
            return serializer->serialize(this);
        }
    private:
        Actuator* const actuator;
        const PowerStatus status;
        const Percentage intensityPercentage;
};

/*
    It represents the event of a Person that leaves a room.
*/
class PersonTrackExit: public AbstractEvent {
    public:
        /*
            Constructor.

            @param person the person that has been tracked.
        */
        PersonTrackExit(const Person person): AbstractEvent(EventType::PERSON_TRACKING), person(person) {}

        /*
            Get the interested person.

            @return the person.
        */
        Person getPerson() {
            return this->person;
        }

        String accept(Serializer *serializer) {
            return serializer->serialize(this);
        }

    private:
        const Person person;
};

/*
    It represents the event of a Person that enters a room.
*/
class PersonTrack: public RoomEvent {
    public:
        /*
            Constructor.

            @param person the person that has been tracked.
            @param room the interested room.
        */
        PersonTrack(const Person person, const Room room): RoomEvent(room, EventType::PERSON_TRACKING), person(person) {}

        /*
            Get the interested person.

            @return the person.
        */
        Person getPerson() {
            return this->person;
        }

        String accept(Serializer *serializer) {
            return serializer->serialize(this);
        }
    private:
        const Person person;
};

/*
    It represents the tracking of implantable medical device usage inside an Operating Room.
*/
class ImplantableMedicalDeviceTrack: public RoomEvent {
    public:
        /*
            Constructor.

            @param device the device that has been tracked.
            @param room the room in which the device has been used.
        */
        ImplantableMedicalDeviceTrack(const ImplantableMedicalDevice device, const Room room):
            RoomEvent(room, EventType::IMPLANTABLE_MEDICAL_DEVICE_TRACKING), device(device) {}

        /*
            Get the interested device.

            @return the device.
        */
        ImplantableMedicalDevice getDevice() {
            return this->device;
        }

        String accept(Serializer *serializer) {
            return serializer->serialize(this);
        }
        
    private:
        const ImplantableMedicalDevice device;
};

/*
    It represents the fact that the patient has been moved on the Operating table.
*/
class PatientOnOperatingTable: public RoomEvent {
    public:
        /*
            Constructor.

            @param room the room of the operating table.
        */
        PatientOnOperatingTable(const Room room): RoomEvent(room, EventType::PATIENT_ON_OPERATING_TABLE) {}
    
        String accept(Serializer *serializer) {
            return serializer->serialize(this);
        }

};

/*
    It represents the event that signal the gateway the presence of a new type of actuator.
*/
class NewActuator: public RoomEvent {
    public:
        /*
            Constructor.

            @param actuator the new detected actuator.
            @param room the room in which the actuator is active.
        */
        NewActuator(Actuator* const actuator, const Room room): RoomEvent(room, EventType::NEW_ACTUATOR), actuator(actuator) {}

        /*
            Get the interested actuator.

            @return the actuator.
        */
        Actuator* getActuator() {
            return this->actuator;
        }
    
        String accept(Serializer *serializer) {
            return serializer->serialize(this);
        }

    private:
        Actuator* const actuator;
};

/*
    It represents the event that signal the gateway a room that this system is controlling.
*/
class RoomEntry: public RoomEvent {
    public:
        /*
            Constructor.

            @param room the room that is monitored by this device.
        */
        RoomEntry(const Room room): RoomEvent(room, EventType::ROOM_ENTRY) {}

        String accept(Serializer *serializer) {
            return serializer->serialize(this);
        }

};

#endif