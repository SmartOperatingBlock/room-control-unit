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
    @tparam T the type stored in the array.
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
            delete[] this->array;
        }

        /*
            Java-like Map of the content of the array.

            @tparam X the new type to map.
            @param func the strategy of the mapping.
            @param deepMap if it is true then the previous elements will be deleted from memory.
            @return the mapped stream.
        */
        template<typename X>
        ArrayStream<X> map(X (*func)(T), bool deepMap = false) {
            X newArray[this->size];
            for(int i = 0; i < this->size; i++) {
                newArray[i] = func(this->array[i]);
            }
            this->cleanup(deepMap);
            return ArrayStream<X>(newArray, this->size);
        }

        /*
            Check if a value exist within the array.
            This function is a terminator of the Stream.
            This terminator will also clean the memory used internally (see deepClean parameter).

            @param func the strategy to find the element.
            @param deepClean if it is true then the previous elements inside the array will be deleted from memory.
            @return true if a matching element exists, false instead.
        */
        bool exist(bool (*func)(T), bool deepClean = false) {
            for(int i = 0; i < this->size; i++) {
                if(func(this->array[i])) {
                    return true;
                }
            }
            this->cleanup(deepClean);
            return false;
        }

        /*
            Execute the sum of summable types.
            This terminator will also clean the memory used internally.
            
            @param deepClean if it is true then the previous elements inside the array will be deleted from memory.
            @return the sum.
        */
        T sum(bool deepClean = false) {
            T sum;
            for(int i = 0; i < this->size; i++) {
                sum += this->array[i];
            }
            this->cleanup(deepClean);
            return sum;
        }

        /*
            Obtain the computed array.
            Note that with this method it is your care to clean the dynamic allocated memory returned.

            @param deepClean if it is true then the previous elements inside the array (of the ArrayStream) will be deleted from memory.
            @return the array.
        */
        T* toArray(bool deepClean = false) {
            T* returnedArray = new T[this->size];
            for(int i = 0; i < this->size; i++) {
                returnedArray[i] = this->array[i];
            }
            this->cleanup(deepClean);
            return returnedArray;
        }

    private:
        T* array;
        const int size;

        void cleanup(bool deep) {
            if(deep) {
                for(int i = 0; i < this->size; i++) {
                    deleteIfPointer(this->array[i]);
                }
            }

            delete[] this->array;
            this->array = NULL;
        }

        template<typename X>
        void deleteIfPointer(X & item) {}  //do nothing: item is not pointer

        template<typename X>
        void deleteIfPointer(X* item) { delete item; } //delete: item is pointer
};


#endif