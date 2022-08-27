#ifndef STRING_FUNCS_H
#define STRING_FUNCS_H

#include <stddef.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

static char* currentStr = NULL;

int isDelimeter(char* symbol, const char* delimeters);

size_t strlen(const char* str);
char* strncpy(char* destination, const char* source, size_t num);
char* strncat(char* destination, const char* source, size_t num);
char* strstr(char* str1, const char* str2);
char* strtok(char* str, const char* delimiters);

#endif
