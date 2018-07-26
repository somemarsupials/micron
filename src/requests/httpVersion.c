#include <string.h>

#include "requests/httpVersion.h"

struct HTTPVersionConversion {
  HTTPVersion value;
  const char* string;
};

const static struct HTTPVersionConversion HTTPVersionConversions[] = {
  { HTTP_1_0, "HTTP/1.0" },
  { HTTP_1_1, "HTTP/1.1" },
};

HTTPVersion HTTPVersionStringToEnum (char* version) {
  int length = sizeof(HTTPVersionConversions) / 
    sizeof(HTTPVersionConversions[0]);
  struct HTTPVersionConversion conversion;

  for (int i = 0; i < length; i++) {
    conversion = HTTPVersionConversions[i];
    if (!strcmp(version, conversion.string)) {
      return conversion.value;
    };
  };

  return UNKNOWN_HTTP_VERSION;
}
