#define _XOPEN_SOURCE 500

#include <fcntl.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>


struct Item {
    int value;
    uint32_t next_pointer;
};

int main(int argc, char const *argv[]) {
    int fd = open(argv[1], 0);
    size_t item_size = sizeof(struct Item);
    struct Item buff;
    int pread_amount = pread(fd, &buff, item_size, buff.next_pointer);
    if (pread_amount != 0) {
        uint32_t next = buff.next_pointer;
        printf("%d ", buff.value);
        while (next != 0) {
            pread_amount = pread(fd, &buff, item_size, buff.next_pointer);
            printf("%d ", buff.value);
            next = buff.next_pointer;
    }
    }
    close(fd);
    return 0;
}