#ifndef __MICRON_REQUESTS_PARSER__
#define __MICRON_REQUESTS_PARSER__

#include "requests/requests.h"

RequestMethod parseRequestMethod (char* method);
Request* parseRequest (char* request);

#endif
