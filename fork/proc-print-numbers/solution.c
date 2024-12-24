#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

void rec_print(int k, int n) {
  if (k < 1) {
    return;
  }
  pid_t process_id = fork();
  if (process_id == 0) {
    rec_print(k - 1, n);
    exit(0);
  } else {
    int res;
    wait(&res);
    printf("%d", k);
    if (k == n) {
        printf("\n");
    } else {
        printf(" ");
    }
  }
}

int main(int argc, char const* argv[]) {
  int N;
  sscanf(argv[1], "%d", &N);
  rec_print(N, N);
  return 0;
}