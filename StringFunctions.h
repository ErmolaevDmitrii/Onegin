#ifndef STRING_FUNCS_H
#define STRING_FUNCS_H

#include <stddef.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <wchar.h>

static wchar_t* currentStr = NULL;
const wchar_t delims[] = L" .,!@#$%^&*()_+\"№;%:?1234567890";

int isDelimeter(wchar_t* symbol, const wchar_t* delimeters);

size_t strlen(const wchar_t* str);
wchar_t* strncpy(wchar_t* destination, const wchar_t* source, size_t num);
wchar_t* strncat(wchar_t* destination, const wchar_t* source, size_t num);
wchar_t* strstr(wchar_t* str1, const wchar_t* str2);
wchar_t* strtok(wchar_t* str, const wchar_t* delimiters);

int StringCompare(const void* a, const void* b);
int StringCompareReverse(const void* a, const void* b);

#endif
