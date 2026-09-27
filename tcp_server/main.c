#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include "./socket/socket.h"
#include "./utils/utils.h"

int main() {
  int socket_file_descriptor;
  int connection_file_descriptor;
  socklen_t socket_length;
  SocketAddressV4 server_address;
  SocketAddressV4 cli;

  // Socket creation.
  socket_file_descriptor = socket_creation();

  // Assign the IP & Port.
  socket_server_binding(socket_file_descriptor, server_address);

  // Server ready to listen.
  int listen_check = listen(socket_file_descriptor, 5);
  if (listen_check != 0) {
    printf("Server listen failed. \n");
    exit(0);
  } else {
    printf("Server listening. \n");
  }

  // Accept data packet from clients.
  socket_length = sizeof(cli);
  connection_file_descriptor = accept(socket_file_descriptor, (SocketAddress*)&cli, &socket_length);
  if (connection_file_descriptor < 0) {
    printf("Server accept failed. \n");
    exit(0);
  } else {
    printf("Server accept successful.\n");
  }

  close(socket_file_descriptor);

  return 0;
}
