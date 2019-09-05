//
// Created by 徐东阳 on 2019-09-01.
//

#ifndef XPYVM_BUFFEREDINPUTSTREAM_HPP
#define XPYVM_BUFFEREDINPUTSTREAM_HPP

#include "stdio.h"

#define BUFFERED_LENGTH 256

class BufferedInputStream {
private:
    FILE *fp;
    char szBuffer[BUFFERED_LENGTH];
    unsigned short index;
public:
    BufferedInputStream(char const *filename) {
        fp = fopen(filename, "rb");
        index = 0;
        fread(szBuffer, BUFFERED_LENGTH * sizeof(char), 1, fp);
    }

    BufferedInputStream() {
        close();
    }

    char read() {
        if (index < BUFFERED_LENGTH) {
            char ret = szBuffer[index];
            index += 1;
            return ret;
        } else {
            index = 0;
            fread(szBuffer, BUFFERED_LENGTH * sizeof(char), 1, fp);
            return read();
        }
    }

    int read_int() {
        // big endian
        int b1 = read() & 0xff;
        int b2 = read() & 0xff;
        int b3 = read() & 0xff;
        int b4 = read() & 0xff;

        return b4 << 24 | b3 << 16 | b2 << 8 | b1;
    }

    void unread() {
        index--;

    }

    void close() {
        if (fp != NULL) {
            fclose(fp);
            fp = NULL;
        }
    }
};

#endif //XPYVM_BUFFEREDINPUTSTREAM_HPP
