/*
 * Copyright (c) 2023 Smart Operating Block
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#ifndef __COMMAND__
#define __COMMAND__

#include "../Room.h"
#include "../PowerStatus.h"
#include "../Percentage.h"
#include "../Luminosity.h"

/*
    Enum of all the types of command.
*/
enum class CommandType {
    HEATING,
    COOLING,
    VENTILATION,
    AMBIENT_LIGHT,
    SURGICAL_LIGHT
};

/*
    Interface that models a command.
*/
class Command {
    public:
        /*
            Get the command type.

            @return the command type.
        */
        virtual CommandType getCommandType() = 0;

        /*
            Get the room.

            @return the destination room.
        */
        virtual Room getRoom() = 0;
};

/*
    Abstract implementation of command.
*/
class AbstractCommand: public Command {
    public:
        CommandType getCommandType() {
            return this->commandType;
        }

        Room getRoom() {
            return this->dstRoom;
        }

    protected:
        /*
            Constructor.

            @param commandType the type of the command.
            @param dstRoom the room to which the command is destinated.
        */
        AbstractCommand(const CommandType commandType, const Room dstRoom): commandType(commandType), dstRoom(dstRoom) {}

    private:
        const CommandType commandType;
        const Room dstRoom;

};

/*
    Heating Command.
*/
class HeatingCommand: public AbstractCommand {
    public:
        /*
            Constructor.

            @param dstRoom the room to which the command is destinated.
            @param powerStatus the status to set the heating.
        */
        HeatingCommand(const Room dstRoom, const PowerStatus powerStatus): AbstractCommand(CommandType::HEATING, dstRoom), powerStatus(powerStatus) {}

        /*
            Get the wanted status.

            @return the status.
        */
        PowerStatus getStatus() {
            return this->powerStatus;
        }
    private:
        const PowerStatus powerStatus;
};

/*
    Cooling Command.
*/
class CoolingCommand: public AbstractCommand {
    public:
        /*
            Constructor.

            @param dstRoom the room to which the command is destinated.
            @param powerStatus the status to set the cooling.
        */
        CoolingCommand(const Room dstRoom, const PowerStatus powerStatus): AbstractCommand(CommandType::COOLING, dstRoom), powerStatus(powerStatus) {}

        /*
            Get the wanted status.

            @return the status.
        */
        PowerStatus getStatus() {
            return this->powerStatus;
        }
    private:
        const PowerStatus powerStatus;
};

/*
    Ventilation Command.
*/
class VentilationCommand: public AbstractCommand {
    public:
        /*
            Constructor.

            @param dstRoom the room to which the command is destinated.
            @param intensityPercentage the intensity of the ventilation.
        */
        VentilationCommand(const Room dstRoom, const Percentage intensityPercentage): AbstractCommand(CommandType::VENTILATION, dstRoom), intensityPercentage(intensityPercentage) {}

        /*
            Get the wanted intensity.

            @return the intesity expressed as a percentage.
        */
        Percentage getIntensityPercentage() {
            return this->intensityPercentage;
        }
    private:
        const Percentage intensityPercentage;
};

/*
    AmbientLigth Command.
*/
class AmbientLigthCommand: public AbstractCommand {
    public:
        /*
            Constructor.

            @param dstRoom the room to which the command is destinated.
            @param intensity the intensity of the ambient light to set.
        */
        AmbientLigthCommand(const Room dstRoom, const Luminosity intensity): AbstractCommand(CommandType::AMBIENT_LIGHT, dstRoom), intensity(intensity) {}

        /*
            Get the wanted intensity.

            @return the intesity to set.
        */
        Luminosity getIntensity() {
            return this->intensity;
        }
    private:
        const Luminosity intensity;
};

/*
    SurgicalLight Command.
*/
class SurgicalLightCommand: public AbstractCommand {
    public:
        /*
            Constructor.

            @param dstRoom the room to which the command is destinated.
            @param intensity the intensity of the surgical light to set.
        */
        SurgicalLightCommand(const Room dstRoom, const Luminosity intensity): AbstractCommand(CommandType::SURGICAL_LIGHT, dstRoom), intensity(intensity) {}

        /*
            Get the wanted intensity.

            @return the intesity to set.
        */
        Luminosity getIntensity() {
            return this->intensity;
        }
    private:
        const Luminosity intensity;
};


#endif