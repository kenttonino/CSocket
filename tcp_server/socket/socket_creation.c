#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>

int socket_creation(void) {
  int socket_file_descriptor;

  // AF_INET = IPv4 Internet protocl.
  // Sequenced, reliable, connection-based byte streams.
  // 0 = No protocol is specified, choose automatically.
  socket_file_descriptor = socket(AF_INET, SOCK_STREAM, 0);
  if (socket_file_descriptor == -1) {
    printf("Socket failed creation. \n");
    exit(0);
  } else {
    printf("Socket created succesfully. \n");
  }

  return socket_file_descriptor;
}
