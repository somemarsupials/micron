#ifndef __MICRON_UTILITIES_ERRORS__
#define __MICRON_UTILITIES_ERRORS__

typedef enum {
  OK,
  MEMORY_ERROR,
  BAD_HTTP_METHOD,
} ErrorNo;

void die (ErrorNo exitCode, char* message);

#endif
