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

    Its implementation is simple without the intenction of being super efficient, not lazy.
*/
template<typename T>
class ArrayStream {
    public:
        /*
            Create an ArrayStream to perform stream operation on an array.

            @param array the array.
            @param size the size of the array.
        */
        ArrayStream(T* array, int size): size(size) {
            this->array = new T[size];
            // Copy the array in order to handle cleaning internally.
            for(int i = 0; i < size; i++) {
                this->array[i] = array[i];
            }
        }

        /*
            Deconstructor.
        */
        ~ArrayStream() {
            delete this->array;
        }

        /*
            Java-like Map of the content of the array.
            NOTE: After calling map, this instance of ArrayStream will be destroyed.

            @tparam X the new type to map.
            @param func the strategy of the mapping
            @return the mapped array.
        */
        template<typename X>
        ArrayStream<X> map(X (*func)(T)) {
            X newArray[this->size];
            for(int i = 0; i < this->size; i++) {
                newArray[i] = func(this->array[i]);
            }
            int newSize = this->size;
            delete this; // Clean memory
            return ArrayStream<X>(newArray, newSize);
        }

        /*
            Check if a value exist within the array.
            This function is terminator of the Stream.
            This terminator will also clean the memory used internally.

            @param func the strategy to find the element.
            @return true if a matching element exists, false instead.
        */
        bool exist(bool (*func)(T)) {
            for(int i = 0; i < this->size; i++) {
                if(func(this->array[i])) {
                    return true;
                }
            }
            delete this->array;
            return false;
        }

        /*
            Execute the sum of summable types.
            This terminator will also clean the memory used internally.

            @return the sum.
        */
        T sum() {
            T sum;
            for(int i = 0; i < this->size; i++) {
                sum += this->array[i];
            }
            delete this->array;
            return sum;
        }

        /*
            Obtain the computed array.
            Note that with this method it is your care to clean the dynamic allocated memory (or delete the ArrayStream obj).

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