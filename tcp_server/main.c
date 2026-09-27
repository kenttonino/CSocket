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

// Custom variables.
int main() {
  int sockfd;
  int connfd;
  socklen_t len;
  SocketAddressV4 servaddr;
  SocketAddressV4 cli;

  // Socket creation.
  sockfd = socket_creation();
  bzero(&servaddr, sizeof(servaddr));

  // Assign the IP & Port.
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
  servaddr.sin_port = htons(8080);

  // Binding created socket to IP.
  int bind_check = bind(sockfd, (SockAddr*)&servaddr, sizeof(servaddr));
  if (bind_check != 0) {
    printf("Socket bind failed. \n");
    exit(0);
  }

  // Server ready to listen.
  int listen_check = listen(sockfd, 5);
  if (listen_check != 0) {
    printf("Server listen failed. \n");
    exit(0);
  } else {
    printf("Server listening. \n");
  }

  // Accept data packet from clients.
  len = sizeof(cli);
  connfd = accept(sockfd, (SockAddr*)&cli, &len);
  if (connfd < 0) {
    printf("Server accept faild. \n");
    exit(0);
  } else {
    printf("Server accept successful.\n");
  }


  close(sockfd);

  return 0;
}
