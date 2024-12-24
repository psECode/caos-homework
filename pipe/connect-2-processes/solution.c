#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int pipefd[2];
  pid_t pid1, pid2;

  pid1 = fork();

  if (pid1 == 0) {
    close(pipefd[0]);
    dup2(pipefd[1], 1);
    close(pipefd[1]);
    execlp(argv[1], argv[1], (char *)NULL);
  }

  pid2 = fork();

  if (pid2 == 0) {
    close(pipefd[1]);
    dup2(pipefd[0], 0);
    close(pipefd[0]);
    execlp(argv[2], argv[2], (char *)NULL);
  }
  close(pipefd[0]);
  close(pipefd[1]);
  return 0;
}