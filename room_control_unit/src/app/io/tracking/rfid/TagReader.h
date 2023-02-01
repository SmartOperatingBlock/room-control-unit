/*
 * Copyright (c) 2023 Smart Operating Block
 *
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#ifndef __TAG_READER__
#define __TAG_READER__

/*
    Interface that model a rfid tag reader.
*/
class TagReader {
    public:
        /*
            Check if a tag is in front of the reader.

            @return true if a tag is available to be read, false otherwise.
        */
        virtual bool isTagAvailable() = 0;

        /*
            Read data from internal Rfid Tag memory block.

            @param blockNumber the number of the block where to read.
            @return the read string.
        */
        virtual String readBlock(int blockNumber) = 0;

        /*
            Deconstructor.
        */
        virtual ~TagReader() {};
};

#endif