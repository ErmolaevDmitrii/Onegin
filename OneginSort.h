#ifndef ONEGIN_SORT_H
#define ONEGIN_SORT_H

#include <stdio.h>
#include <stdlib.h>
#include "StringFunctions.h"
#include "StringArray.h"

int isProperLine(const char* line);

char* ReadOneLine(FILE* file);
struct StringArray* ReadLines(FILE* file);

void OneginSort(const char* inputFileName, const char* outputFileName);

#endif
