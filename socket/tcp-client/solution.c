#include <arpa/inet.h>
#include <errno.h>
#include <memory.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdbool.h>

void print_error(const char* msg) {
  perror(msg);
  exit(1);
}

bool haram_connection(int status) {
    return -1 == status && ECONNRESET == errno || 0 == status;
}

int main(int argc, char const* argv[]) {
  uint16_t port = 0;
  sscanf(argv[2], "%hd", &port);

  struct sockaddr_in addr = {.sin_family = AF_INET, .sin_port = htons(port)};
  inet_pton(AF_INET, argv[1], &addr.sin_addr);

  int sock = socket(AF_INET, SOCK_STREAM, 0);

  connect(sock, (struct sockaddr*)&addr, sizeof(addr));

  int number = 0;
  while (EOF != scanf("%d", &number)) {
    int sended = send(sock, &number, sizeof(number), 0);
    if (haram_connection(sended)) {
      shutdown(sock, SHUT_RDWR);
      close(sock);
      return 0;
    } else if ( sended == -1) {
      shutdown(sock, SHUT_RDWR);
      close(sock);
      print_error("Failed to send data");
    }
    int received = recv(sock, &number, sizeof(number), 0);
    if (haram_connection(received)) {
      shutdown(sock, SHUT_RDWR);
      close(sock);
      return 0;
    } else if ( received==-1) {
      shutdown(sock, SHUT_RDWR);
      close(sock);
      print_error("Failed to send data");
    }
    printf("%d ", number);
  }

  shutdown(sock, SHUT_RDWR);
  close(sock);

  return 0;
}