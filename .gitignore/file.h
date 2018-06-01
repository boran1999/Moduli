#ifndef _file_h
#define _file_h

#include "geometry.h"

int count(const char* filename);
bool rp(const char* filename, point* arr, int maxpointnum);
bool writetreug(const char* filename, const treug* arr1, int trnum);

#endif
