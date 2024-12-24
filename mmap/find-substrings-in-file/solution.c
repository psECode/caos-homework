#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char const* argv[]) {
  int fd = open(argv[1], O_RDONLY);
  const char* strin = argv[2];
  struct stat st;
  fstat(fd, &st);
  size_t f_size = st.st_size;
  char* content = (char*)mmap(NULL, f_size, PROT_READ, MAP_PRIVATE, fd, 0);
  size_t substring_len = strlen(strin);
  if (strin != 0 || f_size >= substring_len) {
    for (size_t i = 0; i <= f_size - substring_len; i++) {
      if (strncmp(content + i, strin, substring_len) == 0) {
        printf("%ld ", i);
      }
    } 
  }
  munmap(content, f_size);
  close(fd);
  return 0;
}