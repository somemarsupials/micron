#ifndef __MICRON_UTILITIES_ERRORS__
#define __MICRON_UTILITIES_ERRORS__

typedef enum {
  OK,
  MEMORY_ERROR,
  UNRECOGNISED_OPTION,
  BAD_OPTION_VALUE,
} ErrorNo;

void die (ErrorNo exitCode, char* message);

#endif
