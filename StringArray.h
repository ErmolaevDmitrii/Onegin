#ifndef STRING_ARRAY_H
#define STRING_ARRAY_H

#include <stddef.h>
#include <stdlib.h>
#include <assert.h>
#include "StringFunctions.h"

struct StringArrayElement {
    char* string;
    size_t stringSize;
};

struct StringArrayElement* CopyElement(const struct StringArrayElement* element);
void DeleteElement(struct StringArrayElement* element);

struct StringArray {
    StringArrayElement** strings;
    size_t Size;
    size_t Length;
};

struct StringArray* NewArray(size_t preCreated);
void AddString(struct StringArray* array, char* newElement);
void PopElement(struct StringArray* array);
char* GetString(const struct StringArray* array, size_t index);
void SwapElements(struct StringArray* array, size_t index1, size_t index2);
struct StringArray* CopyArray(const struct StringArray* source);
void DeleteArray(struct StringArray* array);

#endif
