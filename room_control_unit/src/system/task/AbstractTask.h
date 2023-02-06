/*
 * Copyright (c) 2023 Smart Operating Block
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#ifndef __ABSTRACT_TASK__
#define __ABSTRACT_TASK__

#include "Task.h"
#include "../System.h"

/*
    Abstract implementation of a task.
    Concrete tasks can extend this class in order to specify only the tick and the clean (deconstructor) strategy.
*/
class AbstractTask: virtual public Task {
    public:
        virtual ~AbstractTask() {}
        
        int getPeriod() {
            return this->period;
        }

        bool updateAndCheck(const int schedulerPeriod) {
            this->timeElapsed+=schedulerPeriod;
            if(this->timeElapsed >= this->period) {
                this->timeElapsed = 0;
                return true;
            }
            return false;
        }
    protected:
        AbstractTask(const int period) : period(period) {
            this->timeElapsed = 0;
        }
        
        /*
            Allow the task to be executed immediately without wait the first period time.
        */
        void tickImmetiadly() {
            this->timeElapsed = this->period;
        }

        void terminate() {
            System::getInstance()->deleteTask(this);
        }
    private:
        int timeElapsed;
        const int period;
};

#endif