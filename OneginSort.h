#ifndef ONEGIN_SORT_H
#define ONEGIN_SORT_H

#include <stdio.h>
#include <stdlib.h>
#include "StringFunctions.h"
#include "StringArray.h"

/// Function to compare 2 strings from the beginning (for qsort function)
/// @param [in] a a const pointer to first cstring
/// @param [in] b a const pointer to second cstring
/// @return 0 if cstrings are equal, 1 if first string is greater than second, -1 if first string is less than second
int StringCompare(const void* a, const void* b);

/// Function to compare 2 strings from the ending (for qsort function)
/// @param [in] a a const pointer to first cstring
/// @param [in] b a const pointer to second cstring
/// @return 0 if cstrings are equal, 1 if first string is greater than second, -1 if first string is less than second
int StringCompareReverse(const void* a, const void* b);

int IsProperLine(const char* line);
char* ReadOneLine(FILE* file);
struct StringArray* ReadLines(FILE* file);
void WriteLines(FILE* file, const struct StringArray* lines);

void OneginSort(const char* inputFileName, const char* outputFileName);

#endif
