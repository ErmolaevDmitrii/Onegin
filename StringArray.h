#ifndef STRING_ARRAY_H
#define STRING_ARRAY_H

#include <stddef.h>
#include <stdlib.h>
#include <assert.h>
#include "StringFunctions.h"

struct StringArray {
    char** strings;
    size_t Size;
    size_t Length;
};

struct StringArray* NewArray(size_t preCreated);
void AddElement(struct StringArray* array, char* newElement);
void PopElement(struct StringArray* array);
char* GetElement(struct StringArray* array, size_t index);
void SwapElements(struct StringArray* array, size_t index1, size_t index2);
struct StringArray* CopyArray(struct StringArray* source);
void DeleteArray(struct StringArray* array);

#endif
