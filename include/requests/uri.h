#ifndef __MICRON_REQUESTS_URI__
#define __MICRON_REQUESTS_URI__

int isAnAsteriskURI (char* uri);
int isAnAbsoluteURI (char* uri);
int isAnAbsolutePathURI(char* uri);
int isAnAuthorityURI (char* uri);

int validateURI (char* uri);

#endif
