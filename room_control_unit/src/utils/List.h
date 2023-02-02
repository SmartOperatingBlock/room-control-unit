/*
 * Copyright (c) 2023 Smart Operating Block
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#ifndef __LIST__
#define __LIST__

/*
    A simple implementation of a List.

    @tparam T the type of data inside the array.
*/
template<typename T>
class List {
    public:
        /*
            Constructor.
        */
        List() {
            this->head = nullptr;
        }

        /*
            Deconstructor.
        */
        ~List() {
            this->clear();
        }

        /*
            Clear the list.

            @param deepClean if it is set to true then also the elements will be deleted from memory.
        */
        void clear(bool deepClean = false) {
            while(head != nullptr) {
                Node* n = this->head->next;
                if(deepClean) {
                    deleteIfPointer(this->head->value);
                }
                delete this->head;
                this->head = n;
            }
        }

        /*
            Add an element to the list.

            @param elem the new element.
        */
        void add(const T elem) {
            Node* newElem = new Node;
            newElem->value = elem;
            newElem->next = this->head;
            this->head = newElem;
        }

        /*
            Compute the size of the List.

            @return the size of the list.
        */
        int size() {
            int result = 0;
            Node* iteratorHead = this->head;
            while(iteratorHead != nullptr) {
                result ++;
                iteratorHead = iteratorHead->next;
            }
            return result;
        }

        /*
            Transform the list in a right-sized array.

            @return the array.
        */
        T* toArray() {
            const int size = this->size();
            T* array = new T[size];
            int counter = 0;
            Node* iteratorHead = this->head;
            while(iteratorHead != nullptr) {
                array[counter] = iteratorHead->value;
                iteratorHead = iteratorHead->next;
                counter++;
            }
            return array;
        }

    private:
        template<typename X>
        void deleteIfPointer(X& item) {}  //do nothing: item is not pointer

        template<typename X>
        void deleteIfPointer(X* item) { delete item; } //delete: item is pointer

        struct Node {
            T value;
            Node* next;
        };

        Node* head;
};

#endif