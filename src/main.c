#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "main.h"

static struct Options options;

void die(int errorNo, char* message) {
  fprintf(stderr, "%s\n", message); 
  exit(errorNo);
}

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
    die(1, "absent or unrecognised port number");
  }

  // run server

  printf("MICRON\n");
  printf("Port number: %d\n", options.port);
}
