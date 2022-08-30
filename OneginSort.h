/// @file
/// @brief Header file containing functions for working with texts

#ifndef ONEGIN_SORT_H
#define ONEGIN_SORT_H

#include <stdio.h>
#include <stdlib.h>
#include "StringArray.h"

/// Checks if symbol is in specified range
/// @param [in] symbol a const pointer to checked symbol
/// @param [in] border1 start of range
/// @param [in] border2 end of range
/// @return 1 or 0 if symbol is in range or not
int IsInRange(const char* symbol, const char border1, const char border2);

/// Checks if symbol can be skipped in string comparison
/// @param [in] symbol a const pointer to checked symbol
/// @return 1 or 0 if symbol can be skipped or not
int IsSkipable(const char* symbol);

/// Compare 2 strings from the beginning (for qsort function)
/// @param [in] a a const pointer to first cstring
/// @param [in] b a const pointer to second cstring
/// @return 0 if cstrings are equal, 1 if first string is greater than second, -1 if first string is less than second
int StringCompare(const void* a, const void* b);

/// Compare 2 strings from the ending (for qsort function)
/// @param [in] a a const pointer to first cstring
/// @param [in] b a const pointer to second cstring
/// @return 0 if cstrings are equal, 1 if first string is greater than second, -1 if first string is less than second
int StringCompareReverse(const void* a, const void* b);

/// Checks if cstring is proper for sorting
/// @param [in] line a const pointer to checked cstring
/// @return 1 or 0 if cstring is proper for sorting or not
int IsProperLine(const char* line);

/// Reads 1 line from file
/// @param [in] file a pointer to FILE struct
/// @return a pointer to read line
char* ReadOneLine(FILE* file);

/// Reads all lines from file
/// @param [in] file a pointer to FILE struct
/// @return a point to StringArray
struct StringArray* ReadLines(FILE* file);

/// Writes lines from StringArray to file
/// @param [in] file a pointer to FILE struct
/// @param [in] lines a const pointer to StringArray struct
void WriteLines(FILE* file, const struct StringArray* lines);

/// Reads lines from file, sorts them in different way and write these result in another file
/// @param [in] inputFileName a const pointer to cstring with input file name
/// @param [in] outputFileName a const pointer to cstring with output file name
void OneginSort(const char* inputFileName, const char* outputFileName);

#endif
