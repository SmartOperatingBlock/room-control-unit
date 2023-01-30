/*
 * Copyright (c) 2023 Smart Operating Block
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#ifndef __BUTTON__
#define __BUTTON__

/*
* Interface for defining buttons-like io.
*/
class Button {
    public:
        /*
            @return true if the button is pressed, false otherwise.
        */
        virtual bool isPressed() = 0;
};

#endif