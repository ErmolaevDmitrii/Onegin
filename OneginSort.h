#ifndef ONEGIN_SORT_H
#define ONEGIN_SORT_H

#include <stdio.h>
#include <wchar.h>
#include <stdlib.h>
#include "StringFunctions.h"
#include "StringArray.h"

int isProperLine(wchar_t* line);

wchar_t* ReadOneLine(FILE* file);
struct StringArray* ReadLines(FILE* file);

void OneginSort(const char* inputFileName, const char* outputFileName);

#endif
