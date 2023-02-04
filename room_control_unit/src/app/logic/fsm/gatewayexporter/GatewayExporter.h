/*
 * Copyright (c) 2023 Smart Operating Block
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#ifndef __GATEWAY_EXPORTER__
#define __GATEWAY_EXPORTER__

#include "../AbstractFsm.h"
#include "../../../model/event/Event.h"
#include "../../baseio/communication/ExternalGateway.h"
#include "../../../../utils/List.h"

struct GatewayExporterContext {
    List<Event*>* const eventList;
    ExternalGateway* const externalGatewayInterface;
};

/*
    Gateway Exporter task.
    Its main objective is to send data (associated to the internal event) to the system gateway.
*/
class GatewayExporter: public AbstractFsm {
    public:
        /*
            Constructor.

            @param period the period of the fsm.
            @param context the local context of the fsm.
        */
        GatewayExporter(int period, GatewayExporterContext* context);
        ~GatewayExporter();
    
    private:
        GatewayExporterContext* const context;

        class E: public State {
            public:
                E(GatewayExporterContext* context);
                ~E();
                void run(Fsm* parentFsm);
            private:
                GatewayExporterContext* const context;
                Serializer* serializer;
        };

};


#endif