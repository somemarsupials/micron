#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "micron.h"
#include "requests/package.h"
#include "utilities/errors.h"
#include "sockets/bind.h"
#include "sockets/listen.h"

static struct Options options;

int main(int argc, char** argv) {
  // initialise options with default values
  options.port = 5000;

  // parse options
  char option;

  while ((option = getopt(argc, argv, "p:")) != -1) {
    switch (option) {
      case 'p':
        options.port = atoi(optarg);
        break;
    }
  }

  // check for invalid or missing arguments

  if (!options.port) {
    die(BAD_OPTION_VALUE, "non-numeric port number");
  }

  // if unrecognised options do something

  // run server

  printf("MICRON\n");
  printf("Port number: %d\n", options.port);
  int server = bindTCPSocket(options.port);
  listenOnTCPSocket(server);

  return 0;
}
