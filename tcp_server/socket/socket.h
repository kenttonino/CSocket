#ifndef SOCKET_H
#define SOCKET_H
#include "../utils/utils.h"
#include "./socket_creation.c"
#include "./socket_server_binding.c"

extern int socket_creation(void);
extern void socket_server_binding(int socket_file_descriptor, SocketAddressV4 server_address);

#endif
