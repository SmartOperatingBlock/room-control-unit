/*
 * Copyright (c) 2023 Smart Operating Block
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#ifndef __SYSTEM__
#define __SYSTEM__

#include "task/Task.h"
#include "scheduler/Scheduler.h"

/*
    System interface.
    There is a single instance of System, available everywhere.
    This has the aim to create a simple level of abstraction for all the System-related requests.
    In this way, in the future it will be possible to add priviledges checks for each call.
*/
class System {
public:
    /*
        Obtain the current instance of the System.
        @return the system.
    */
    static System* getInstance();

    /*
        Add a task in the System Scheduler
        @param task it is the task to add.
    */
    bool addTask(Task* task);

    /*
        Init the system.
    */
    void init();
    
    /*
        Perform a single run-cycle of the System.
        This method must be called inside a loop in order to perform the system functionalities continuosly.
    */
    void run();

private:
    System();
    static System* instance;
    Scheduler* scheduler;

    /*
        Put the System in sleep mode in order to save energy.
    */
    void sleep();
};

#endif