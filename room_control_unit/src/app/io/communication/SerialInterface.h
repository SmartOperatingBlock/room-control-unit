/*
 * Copyright (c) 2023 Smart Operating Block
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#ifndef __SERIAL_INTERFACE__
#define __SERIAL_INTERFACE__

#include "../../logic/baseio/communication/DataProvider.h"
#include "../../logic/baseio/communication/ExternalGateway.h"

class SerialInterface: public DataProvider, public ExternalGateway {
    public:
        /*
            There is only one instance of the serial interface inside this system.
            With this method is possible to obtain it.

            @return the instance.
        */
        static SerialInterface* getInstance();

        /*
            Init the serial interface.
            
            @param bps the baud rate of the Serial expressed as Bit Per Second.
        */
        void init(unsigned long bps);

        bool isNewDataAvailable();
        String getData();
        void send(String rawData);

    private:
        SerialInterface();
        static SerialInterface* instance;

};

#endif