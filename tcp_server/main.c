#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

// Custom variables.
#define PORT 8080
#define SOCK_ADDR struct sockaddr

int main() {
  int sockfd;
  int connfd;
  socklen_t len;
  struct sockaddr_in servaddr;
  struct sockaddr_in cli;

  // Socket creation.
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    printf("Socket not created. \n");
    exit(0);
  } else {
    printf("Socket created successfully. \n");
  }
  bzero(&servaddr, sizeof(servaddr));

  // Assign the IP & Port.
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
  servaddr.sin_port = htons(8080);

  // Binding created socket to IP.
  int bind_check = bind(sockfd, (SOCK_ADDR*)&servaddr, sizeof(servaddr));
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
  connfd = accept(sockfd, (SOCK_ADDR*)&cli, &len);
  if (connfd < 0) {
    printf("Server accept faild. \n");
    exit(0);
  } else {
    printf("Server accept successful.\n");
  }


  close(sockfd);

  return 0;
}
