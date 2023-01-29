/*
 * Copyright (c) 2023 Smart Operating Block
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#ifndef __TASK__
#define __TASK__

/*
    This interface models a task that can be executed by the Scheduler.
*/
class Task {
    public:
        /*
            Called by the scheduler to execute the code of the task.
            N.B. This code will be executed outside ISR.
        */
        virtual void tick() = 0;
        /*
            It is possibile to get the period of the task.
            @return the period of the task.
        */
        virtual int getPeriod() = 0;
        /*
            Update the internal time and decide if the task has to be executed.
            @return true if the task must be executed, false instead.
        */
        virtual bool updateAndCheck(int schedulerPeriod) = 0;
        /*
            Tasks must also specify their destructor in order to clean the memory.
        */
        virtual ~Task() {}
};


#endif