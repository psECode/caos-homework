#include <fcntl.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>

struct Item {
  int value;
  uint32_t next_pointer;
};

int main(int argc, char *argv[]) {
  int fd = open(argv[1], O_RDONLY);
  struct stat st;
  fstat(fd, &st);
  size_t f_size = st.st_size;
  int *content = (int *)mmap(NULL, f_size, PROT_READ, MAP_PRIVATE, fd, 0);
  for (size_t cur = 0; cur < f_size;) {
    struct Item *item = (struct Item*)((char *)content + cur);
    printf("%d ", item->value);
    if (item->next_pointer == 0) {
        break;
    }
    cur = item->next_pointer;
  }
  munmap(content, f_size);
  close(fd);
  return 0;
}