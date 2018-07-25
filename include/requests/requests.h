#ifndef __MICRON_REQUESTS_REQUESTS__
#define __MICRON_REQUESTS_REQUESTS__

typedef enum {
  DELETE,
  GET,
  HEAD,
  OPTIONS,
  PATCH,
  POST,
  PUT,
  UNKNOWN
} RequestMethod;

typedef struct _Request {
  RequestMethod method;
} Request;

#endif
