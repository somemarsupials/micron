#ifndef __MICRON_REQUESTS_REQUESTS__
#define __MICRON_REQUESTS_REQUESTS__

#include "requests/requestLine.h"

typedef struct _Request {
  RequestLine requestLine;
} Request;

#endif
