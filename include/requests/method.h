#ifndef __MICRON_REQUESTS_METHOD__
#define __MICRON_REQUESTS_METHOD__

typedef enum {
  UNKNOWN_REQUEST_METHOD,
  DELETE,
  GET,
  HEAD,
  OPTIONS,
  PATCH,
  POST,
  PUT
} RequestMethod;

RequestMethod requestMethodStringToEnum (char* method);

#endif
