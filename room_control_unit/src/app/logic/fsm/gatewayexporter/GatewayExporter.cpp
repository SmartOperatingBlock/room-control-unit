/*
 * Copyright (c) 2023 Smart Operating Block
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#include "GatewayExporter.h"
#include "../../../../utils/ArrayStream.h"
#include "../../presenter/serializer/JsonSerializer.h"

GatewayExporter::GatewayExporter(const int period, GatewayExporterContext* const context): AbstractFsm(period) {
    this->changeState(new E(context));
}

/*
##############################################################################
------------------State of GatewayExporter FSM ---------------
##############################################################################
*/

GatewayExporter::E::E(GatewayExporterContext* const context): context(context) {
    this->serializer = new JsonSerializer();
}

void GatewayExporter::E::run(Fsm* const parentFsm) {
    const int eventListSize = this->context->eventList->size();
    if(eventListSize != 0) {
        ArrayStream<Event*>(this->context->eventList->toArray(), eventListSize)
            .foreach([this](Event* ev) {this->context->externalGatewayInterface->send(this->serializer->serialize(ev));});
        this->context->eventList->clear(true);
    }
}