#include <string.h>
#include <stdlib.h>

#include "requests/requests.h"
#include "requests/parser.h"
#include "utilities/errors.h"

struct RequestMethodConversion {
  RequestMethod value;
  const char* string;
};

const static struct RequestMethodConversion CONVERSIONS[] = {
  { DELETE,   "DELETE"  },
  { GET,      "GET"     },
  { HEAD,     "HEAD"    },
  { OPTIONS,  "OPTIONS" },
  { PATCH,    "PATCH"   },
  { POST,     "POST"    },
  { PUT,      "PUT"     }
};

RequestMethod parseRequestMethod (char* method) {
  int items = sizeof(CONVERSIONS) / sizeof(struct RequestMethodConversion);

  for (int i = 0; i < items; i++) {
    struct RequestMethodConversion conversion = CONVERSIONS[i];
    if (!strcmp(method, conversion.string)) {
      return conversion.value;
    };
  };
  return -1;
}

Request* parseRequest (char* raw) {
  Request* request = malloc(sizeof(Request));
  if (!request) {
    die(MEMORY_ERROR, "could not allocate request object");
  };

  return request;
}
