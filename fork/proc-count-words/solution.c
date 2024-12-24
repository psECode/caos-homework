#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>


int main(int argc, char const* argv[]) {
  char buffer[4096];
  int count = 0;
  int result = 0;
  int res;
  while (1) {
    pid_t process_id;
    if (-1 == (process_id = fork())) {
      break;
    } else if (0 == process_id) {
      if (scanf("%s", buffer) == 1) {
        res = 0;
      } else {
        res = 1;
      }
      return res;
    } else {
      wait(&result);
      if (result != 0) {
        break;
      } else {
        count++;
      }
    }
  }
  printf("%d\n", count);
  return 0;
}