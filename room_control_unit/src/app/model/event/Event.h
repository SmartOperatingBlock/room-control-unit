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

enum class EventType {
    ROOM,
    ACTUATOR_STATE,
    HEALTH_PROFESSIONAL_TRACKING,
    PATIENT_TRACKING,
    IMPLANTABLE_MEDICAL_DEVICE_TRACKING,
    PATIENT_ON_OPERATING_TABLE,
    NEW_ACTUATOR
};

/*
    Interface that models an Event of the system.
*/
class Event {
    public:
        /*
            Get the event type.

            @return the event type.
        */
        virtual EventType getType() = 0;
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
            Constructor.

            @param room the room in which the event is occurred.
        */
        RoomEvent(const Room room): AbstractEvent(EventType::ROOM), room(room) {}

        /*
            Get the room of the event.

            @return the room.
        */
        Room getRoom() {
            return this->room;
        }
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
        PresenceEvent(const Room room): RoomEvent(room) {}
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
        ActuatorStateEvent(const Actuator actuator, const PowerStatus status, const int intensity):
            AbstractEvent(EventType::ACTUATOR_STATE), actuator(actuator), status(status), intensity(intensity) {}
        
        /*
            Get the actuator.

            @return the actuator.
        */
        Actuator getActuator() {
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
        int getIntensity() {
            return this->intensity;
        }
    private:
        const Actuator actuator;
        const PowerStatus status;
        const int intensity;
};


#endif