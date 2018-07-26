#include <string.h>
#include <stdlib.h>

#include "requests/method.h"
#include "utilities/errors.h"

struct RequestMethodConversion {
  RequestMethod value;
  const char* string;
};

const static struct RequestMethodConversion requestMethodConversions[] = {
  { DELETE,   "DELETE"  },
  { GET,      "GET"     },
  { HEAD,     "HEAD"    },
  { OPTIONS,  "OPTIONS" },
  { PATCH,    "PATCH"   },
  { POST,     "POST"    },
  { PUT,      "PUT"     },
};

RequestMethod requestMethodStringToEnum (char* method) {
  int length = sizeof(requestMethodConversions) / 
    sizeof(requestMethodConversions[0]);
  struct RequestMethodConversion conversion;

  for (int i = 0; i < length; i++) {
    conversion = requestMethodConversions[i];
    if (!strcmp(method, conversion.string)) {
      return conversion.value;
    };
  };

  return UNKNOWN_REQUEST_METHOD;
}
