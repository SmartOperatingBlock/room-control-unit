/*
 * Copyright (c) 2023 Smart Operating Block
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#include "src/system/System.h"
#include "src/system/task/AbstractTask.h"

class MyTask: public AbstractTask {
    public:
        MyTask(int period, String name) : AbstractTask(period), name(name) {}
        void tick() {
            Serial.println("[" + name + "@" + String(millis()) + "]computing...");
        }

    private:
        String name;
};

void setup() {
    Serial.begin(9600);
    System::getInstance()->addTask(new MyTask(1000, "Task-1"));
    System::getInstance()->addTask(new MyTask(500, "Task-2"));
    System::getInstance()->addTask(new MyTask(300, "Task-3"));
}

void loop() {
    System::getInstance()->run();
}
