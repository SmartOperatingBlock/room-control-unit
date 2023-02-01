/*
 * Copyright (c) 2023 Smart Operating Block
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#ifndef __PERCENTAGE__
#define __PERCENTAGE__

#define MAX_PERCENTAGE 100
#define MIN_PERCENTAGE 0

class Percentage {
    public:
        /*
            Constructor. It will check and correct the value if a incorrect value is passed.

            @param percentage the percentage expressed with a value in the range 0-100.
        */
        Percentage(const int percentage) {
            if(percentage > MAX_PERCENTAGE) {
                this->percentage = MAX_PERCENTAGE;
            } else if(percentage < MIN_PERCENTAGE) {
                this->percentage = MIN_PERCENTAGE;
            } else {
                this->percentage = percentage;
            }
        }

        /*
            Get the percentage.
            
            @return a percentage in the range 0-100.
        */
        int get() {
            return this->percentage;
        }

    private:
        int percentage;
};

#endif