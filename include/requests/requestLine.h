#ifndef __MICRON_REQUEST_REQUESTLINE__
#define __MICRON_REQUEST_REQUESTLINE__

#include "requests/method.h"
#include "requests/httpVersion.h"

typedef struct _RequestLine {
  RequestMethod method;
  char* URI;
  HTTPVersion version;
} RequestLine;

#endif
