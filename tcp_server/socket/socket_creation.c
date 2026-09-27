#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>

int socket_creation(void) {
  int sockfd;

  // AF_INET = IPv4 Internet protocl.
  // Sequenced, reliable, connection-based byte streams.
  // 0 = No protocol is specified, choose automatically.
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    printf("Socket failed creation. \n");
    exit(0);
  } else {
    printf("Socket created succesfully. \n");
  }

  return sockfd;
}
