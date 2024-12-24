#define _XOPEN_SOURCE 700

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

volatile sig_atomic_t counter = 0;

void handle_sigint(int signo) { 
    counter++; 
}

void handle_sigterm(int signo) {
  printf("%d\n", counter);
  fflush(stdout);
  exit(0);
}

int main() {
  printf("%d\n", getpid());
  fflush(stdout);

  struct sigaction sigint;
  struct sigaction sigterm;

  sigint.sa_handler = handle_sigint;
  sigint.sa_flags = SA_RESTART;
  sigemptyset(&sigint.sa_mask);
  sigaction(SIGINT, &sigint, NULL);

  sigterm.sa_handler = handle_sigterm;
  sigterm.sa_flags = 0;
  sigemptyset(&sigterm.sa_mask);
  sigaction(SIGTERM, &sigterm, NULL);

  while (1) {
    pause();
  }

  return 0;
}