/*
 * Copyright (c) 2023 Smart Operating Block
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#ifndef __MATHHELPER__
#define __MATHHELPER__

#include <stdint.h>

/*
    Math Helper class.
*/
class MathHelper {
    public:
        /*
            Greatest Common Divisor on an integer array.
            
            @param array the array of numbers to which compute the gcd.
            @param size the size of the array.
            @return the gcd of the numbers inside the array.
        */
        static int gcdOfArray(int* const array, const int size) {
            int result = array[0];
            if(size > 0) {
                for(int i=0; i<size; i++) {
                    result = gcd(result, array[i]);
                }
            }
            return result;
        }
        
    private:
        static int gcd(int a, int b) {
            int temp;
            while(b > 0) {
                temp = b;
                b = a % b;
                a = temp;
            }
            return a;
        }
};

#endif