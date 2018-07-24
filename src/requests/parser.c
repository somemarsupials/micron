#include <string.h>

#include "requests/requests.h"
#include "requests/parser.h"

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
