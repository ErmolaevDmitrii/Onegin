/// @file
/// @brief Header file with functions for operating cstrings

#ifndef STRING_FUNCS_H
#define STRING_FUNCS_H

#include <stddef.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

/// Function for identification if char is a delimeter
/// @param [in] symbol a const pointer to a symbol
/// @param [in] delimeters a const pointer to cstring with delimeters
/// @return 1 or 0 if char is a delimeter or not
int IsDelimeter(const char* symbol, const char* delimeters);

/// Function to get size of cstring
/// @param [in] str a const pointer to cstring
/// @return size of cstring
size_t strlen(const char* str);

/// Function to copy specified count of chars from source to destination
/// @param [in] destination a pointer to cstring where to copy chars
/// @param [in] source a const pointer to cstring from where copy chars
/// @param [in] num count of chars to copy
/// @return destination pointer
char* strncpy(char* destination, const char* source, size_t num);

/// Function to concatinate specified count of chars from source to destination
/// @param [in] destination a pointer to cstring where to concatinate chars
/// @param [in] source a const pointer to cstring from where concatinate chars
/// @param [in] num count of chars to concatinate
/// @return destination pointer
char* strncat(char* destination, const char* source, size_t num);

/// Function to get a pointer to the first appearence of str2 in str1
/// @param [in] str1 a const pointer to str1
/// @param [in] str2 a const pointer to str2
/// @return NULL if there are no appearence of str2 in str1 or a pointer to cstring
char* strstr(char* str1, const char* str2);

/// Function to split cstring to tokens, which were separated by delimeters
/// @param [in] str a pointer to cstring which to split
/// @param [in] delimeters a const pointer to cstring with delimeters
/// @return a pointer to token or NULL if it's an end of cstring
char* strtok(char* str, const char* delimiters);

/// Function to compare 2 strings from the beginning
/// @param [in] a a const pointer to first cstring
/// @param [in] b a const pointer to second cstring
/// @return 0 if cstrings are equal, 1 if first string is greater than second, -1 if first string is less than second
int strcmp(const char* a, const char* b);

#endif
