#include <netinet/in.h>
#include <sys/socket.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

#include "sockets/bind.h"

int bindTCPSocket (int port) {
  int socketFD;
  struct sockaddr_in address;

  /* get file descriptor for socket */
  if ((socketFD = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    return -1;
  }

  /* reset all fields in the address */
  memset(&address, 0, sizeof(address));

  /* configure as network socket, assign port and indicate no IP address */
  address.sin_family = AF_INET;
  address.sin_port = htons(port);
  address.sin_addr.s_addr = htonl(INADDR_ANY);

  /* bind accepts a socketaddr, not socketaddr_in */
  struct sockaddr* castAddress = (struct sockaddr*) &address;
  return bind(socketFD, castAddress, sizeof(address)) == 0 ? socketFD : -1;
}

void closeTCPSocket (int fileDescriptor) {
  int errorNo = close(fileDescriptor);
}
