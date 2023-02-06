/*
 * Copyright (c) 2023 Smart Operating Block
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#include "System.h"
#include <SPI.h>
#include <avr/sleep.h>

System* System::instance = nullptr;

System* System::getInstance() {
    if(instance == nullptr) {
        instance = new System();
    }
    return instance;
}

System::System() {
    this->scheduler = new Scheduler();
}

bool System::addTask(Task* const newTask) {
    return this->scheduler->addTask(newTask);
}

bool System::deleteTask(Task* const newTask) {
    return this->scheduler->deleteTask(newTask);
}

void System::init() {
    SPI.begin();
}

void System::run() {
    this->scheduler->schedule();
    // Put the Arduino (avr cpu) in sleep mode to save energy.
    this->sleep();
}

void System::sleep() {
    set_sleep_mode(SLEEP_MODE_IDLE);  
    sleep_enable();
    sleep_mode();  
    /** The program will continue from here. **/  
    /* First thing to do is disable sleep. */  
    sleep_disable();
}