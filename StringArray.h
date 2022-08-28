#ifndef STRING_ARRAY_H
#define STRING_ARRAY_H

#include <stddef.h>
#include <stdlib.h>
#include <assert.h>
#include <wchar.h>
#include "StringFunctions.h"

struct StringArray {
    wchar_t** strings;
    size_t Size;
    size_t Length;
};

struct StringArray* NewArray(size_t preCreated);
void AddElement(struct StringArray* array, wchar_t* newElement);
void PopElement(struct StringArray* array);
wchar_t* GetElement(struct StringArray* array, size_t index);
void SwapElements(struct StringArray* array, size_t index1, size_t index2);
struct StringArray* CopyArray(struct StringArray* source);
void DeleteArray(struct StringArray* array);

#endif
