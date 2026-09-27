#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <strings.h>
#include <sys/socket.h>
#include "../utils/utils.h"

void socket_server_binding(int socket_file_descriptor, SocketAddressV4 server_address) {
  bzero(&server_address, sizeof(server_address));

  // Assign the IP, Port, and family type (IPv4).
  server_address.sin_family = AF_INET;
  server_address.sin_addr.s_addr = htonl(INADDR_ANY);
  server_address.sin_port = htons(PORT);

  // Bind created socket to the IP.
  int bind_check = bind(
      socket_file_descriptor,
      (SocketAddress*)&server_address,
      sizeof(server_address)
  );
  if (bind_check != 0) {
    printf("Socket binding failed. \n");
    exit(0);
  } else {
    printf("Socket binding sucess. \n");
  }
}
