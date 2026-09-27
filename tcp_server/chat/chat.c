#include <stdio.h>
#include <strings.h>
#include <string.h>
#include <unistd.h>
#include "../utils/utils.h"

void chat(int socket_file_descriptor) {
  char max_buffer[MAX_BUFFER];
  int num_char;

  for (;;) {
    bzero(max_buffer, sizeof(max_buffer));
    printf("Enter the string: ");
    num_char = 0;

    // Read each character in stdin and stop when its a newline.
    while ((max_buffer[num_char++] = getchar()) != '\n');

    write(socket_file_descriptor, max_buffer, sizeof(max_buffer));
    bzero(max_buffer, sizeof(max_buffer));
    read(socket_file_descriptor, max_buffer, sizeof(max_buffer));
    printf("From Server: %s", max_buffer);

    if ((strncmp(max_buffer, "exit", 4)) == 0) {
      printf("Client Exit. \n");
      break;
    }
  }
}
