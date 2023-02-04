/*
 * Copyright (c) 2023 Smart Operating Block
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#ifndef __PAIR__
#define __PAIR__

/*
    A simple class that implements a generic Pair.

    @tparam X
    @tparam Y
*/
template<typename X, typename Y>
class Pair {
    public:
        Pair() {}
        /*
            Constructor.

            @param x the first element.
            @param y the second element.
        */
        Pair(X x, Y y): x(x), y(y) {}

        ~Pair() {}

        /*
            Get the first element.

            @return the first element.
        */
        X getX() {
            return this->x;
        }

        /*
            Get the second element.

            @return the second element.
        */
        Y getY() {
            return this->y;
        }

        bool operator==(Pair<X, Y>& pair1) {
            return pair1.getX() == this->getX() && pair1.getY() == this->getY();
        }
    private:
        X x;
        Y y;
};

#endif