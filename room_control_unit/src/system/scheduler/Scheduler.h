/*
 * Copyright (c) 2023 Smart Operating Block
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */


#ifndef __SCHEDULER__
#define __SCHEDULER__

#include "../task/Task.h"
#include <stdint.h>
#define MAX_TASKS 10

/*
    This class models the scheduler of the system.
    Its main objective is to schedule the various tasks that the system is composed of.

    This is a Cooperative Scheduler.
    The scheduler has an array of tasks. The task are executed periodically with the
    specified period.
    Each task has its own period, and when they are added to the scheduler, the scheduler will
    compute the greatest common divisor in order to select its own right period.

    The scheduler tick is obtained by a timer interrupt.
    In the Timer ISR, the scheduler will be only enabled (in order have the thinnest ISR possible).
    In fact all the tasks will be executed outside the ISR, in order to permit the timer not to block 
    on the execution of a specific task being able to generate interrupts within the desired period.

    All the features are implemented in the simpler way possible sufficient to reach the objective.
*/
class Scheduler {
    public:
        /* 
            Constructor of the Scheduler.
        */
        Scheduler();

        /*
            This is needed to execute a single schedule of the system.
            For this reason, in order to execute the task continuosly it must be
            inserted inside the loop of the system.
            This code is executed outside any ISR.
        */
        void schedule();

        /*
            Add task to be scheduled.
            The scheduling period will automatically adjust itself in order to be able to schedule
            each task correctly.
            
            @param task the task to add
            @return true if there is enough space, false instead.
        */
        bool addTask(Task* task);

    private:
        Task* tasks[MAX_TASKS]; // The list of task to be scheduled
        int taskNumber; // The current number of tasks
        int schedulerPeriod; // The automatically computed period of the Scheduler
    
        void setPeriod(); // It allows to compute and set the scheduler period.
};

#endif