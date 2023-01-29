/*
 * Copyright (c) 2023 Smart Operating Block
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#ifndef __ARRAY_STREAM__
#define __ARRAY_STREAM__


/*
    This class allow to perform stream's operation java-like with the
    constructs that are avaible for the c++ implementation on the AVR CPU.

    Its implementation is simple without the intenction of being super efficient.
*/
template<typename T>
class ArrayStream {
    public:
        /*
            Create a Stream from an array.

            @param array the array.
            @param size the size of the array.
        */
        ArrayStream(const T* array, const int size): array(array), size(size) {}

        /*
            Java-like Map of the content of the array.

            @tparam X the new type to map.
            @param func the strategy of the mapping
            @return the mapped array.
        */
        template<typename X>
        ArrayStream<X> map(X (*func)(T)) {
            X* newArray = new X[this->size];
            for(int i = 0; i < this->size; i++) {
                newArray[i] = func(this->array[i]);
            }
            return ArrayStream(newArray, this->size);
        }

        /*
            Check if a value exist within the array.
            This function is terminator of the Stream.

            @param func the strategy to find the element.
            @return true if a matching element exists, false instead.
        */
        bool exist(bool (*func)(T)) {
            for(int i = 0; i < this->size; i++) {
                if(func(this->array[i])) {
                    return true;
                }
            }
            return false;
        }

        /*
            Execute the sum of summable types.

            @return the sum.
        */
        T sum() {
            T sum;
            for(int i = 0; i < this->size; i++) {
                sum += this->array[i];
            }
            return sum;
        }

        /*
            Obtain the computed array.

            @return the array.
        */
        T* toArray() {
            return this->array;
        }

    private:
        T* array;
        const int size;
};


#endif