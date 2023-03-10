/*
 * Copyright (c) 2023 Smart Operating Block
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#include "Scheduler.h"
#include <TimerOne.h>
#include "../../utils/Math.h"
#include "../../utils/ArrayStream.h"

/*
    Variable used to specify if the scheduler has to tick.
    It is set by the ISR.
*/
static volatile bool schedulerTickEnabled = false;

/*
    Called by the ISR to allow the scheduler to execute its tasks.
*/
static void scheduleTickEnable() {
    schedulerTickEnabled = true;
}

Scheduler::Scheduler() {
    this->taskNumber = 0;
}

bool Scheduler::addTask(Task* const newTask) {
    if(this->taskNumber < MAX_TASKS) {
        this->tasks[this->taskNumber] = newTask;
        this->taskNumber++;
        this->setPeriod();
        return true;
    }
    return false;
}

bool Scheduler::deleteTask(Task* const task) {
    // Deleting a task with this code is a bit slow, but it's kept simple for educational purposes.
    for(int i = 0; i < this->taskNumber; i++) {
        //Check task
        if(this->tasks[i] == task) {
            // remove the task
            delete this->tasks[i];
            //Repositioning other tasks in order to not have gaps in the array
            for(int j = i; j < this->taskNumber - 1; j++) {
                this->tasks[j] = this->tasks[j+1];
            }
            this->taskNumber--;
            // Correct the scheduling period after the deletion.
            this->setPeriod();
            return true;
        }
    }
    return false;
}

void Scheduler::setPeriod() {
    //Get the period of all tasks
    int* tasksPeriod = ArrayStream<Task*>(this->tasks, this->taskNumber)
                            .map<int>([](Task* t) {return t->getPeriod();})
                            .toArray();

    //Get the GCD (Greatest commond divisor)
    this->schedulerPeriod = MathHelper::gcdOfArray(tasksPeriod, this->taskNumber);

    //clean memory
    delete[] tasksPeriod;
    
    noInterrupts();
    TCCR1A = 0;           //reset timer configs
    TCCR1B = 0;           //stop the timer and clear configs that will be set based on the period by the library
    TIFR1 = _BV(TOV1);    //Mode that interrupt occurs when TCNT1 reach zero, because TimerOne works with PWM (WGM13 mode).
    TCNT1 = 1;            //Reset TCNT1 that is the counter of the Timer. Don't cleared (=0) because otherwise it will fire the timer interrupt.
    interrupts();


    Timer1.initialize(this->schedulerPeriod*1000l);
    Timer1.attachInterrupt(scheduleTickEnable);
}

void Scheduler::schedule() {
    //Check if we are enabled to perform tasks.
    if(schedulerTickEnabled) {
        for(int i = 0; i < this->taskNumber; i++) {
            if(this->tasks[i] != nullptr && this->tasks[i]->updateAndCheck(this->schedulerPeriod)) {
                this->tasks[i]->tick();
            }
        }
        schedulerTickEnabled = false;
    }
}