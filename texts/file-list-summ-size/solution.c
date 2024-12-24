#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {
  char buffer[4096];
  struct stat st;
  int size_summ = 0;
  while (fgets(buffer, 4096, stdin) != NULL) {
    buffer[strcpn(buffer, "\n")] = '\0';
    if (stat(buffer, &st) == -1) {
        continue;
    }
    if (S_ISREG(st.st_mode)) {
      size_summ += st.st_size;
    }
  }
  print("%d\n", size_summ);
  return 0;
}