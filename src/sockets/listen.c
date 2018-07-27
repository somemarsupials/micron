#include <netinet/in.h>
#include <sys/socket.h>

#include "sockets/bind.h"
#include "sockets/listen.h"
#include "responses/generic.h"

int listenOnTCPSocket (int serverFD) {
  int clientFD;
  unsigned int clientAddressSize;
  struct sockaddr_in clientAddress;
  
  if (listen(serverFD, 5) != 0) {
    return -1;
  }

  struct sockaddr* castAddress = (struct sockaddr*) &clientAddress;
  while ((clientFD = accept(serverFD, castAddress, &clientAddressSize))) {
    if (clientFD == -1) {
      return -1;
    }

    sendGenericResponse(clientFD);
    closeTCPSocket(clientFD);
  };

  return clientFD;
}

void sendGenericResponse (int clientFD) {
  char buffer[1024];
  int incomingMessageSize;

  incomingMessageSize = recv(clientFD, buffer, 1024, 0);
  if (incomingMessageSize < 0) return;

  while (incomingMessageSize > 0) {
    if (send(clientFD, responseOK, incomingMessageSize, 0) != incomingMessageSize) return;
  }
}

