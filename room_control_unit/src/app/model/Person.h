/*
 * Copyright (c) 2023 Smart Operating Block
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#ifndef __PERSON__
#define __PERSON__

#include "Arduino.h"

/*
    This enum models the role of a Person.
*/
enum class PersonRole {
    /*
        Health Professional inside the hospital.
    */
    HEALTH_PROFESSIONAL,

    /*
        Patient.
    */
    PATIENT
};

/*
    This class model the necessary information about a Person.
*/
class Person {
    public:
        /*
            Constructor of a Person.

            @param id the person id.
            @param role the person role.
        */
        Person(const String id, const PersonRole role): id(id), role(role) {}

        ~Person() {}
        
        /*
            Get the Person's ID.

            @return the id.
        */
        String getId() {
            return this->id;
        }

        /*
            Get the Person's Role.

            @return the role.
        */
        PersonRole getRole() {
            return this->role;
        }

    private:
        const String id;
        const PersonRole role;
};

#endif