#include <stdio.h>
#include <stdlib.h>

#include "utilities/errors.h"

void die (ErrorNo exitCode, char* message) {
  fprintf(stderr, "%s\n", message);
  exit(exitCode);
}
