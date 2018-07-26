#ifndef __MICRON_REQUEST_HTTPVERSION__
#define __MICRON_REQUEST_HTTPVERSION__

typedef enum {
  UNKNOWN_HTTP_VERSION,
  HTTP_1_0,
  HTTP_1_1,
} HTTPVersion;

HTTPVersion HTTPVersionStringToEnum (char* version);

#endif
