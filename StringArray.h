/// @file
/// @brief Header file containing structs and functions for dynamic array of cstrings

#ifndef STRING_ARRAY_H
#define STRING_ARRAY_H

#include <stddef.h>
#include <stdlib.h>
#include <assert.h>
#include "StringFunctions.h"

/// struct containing cstring with its size
struct StringArrayElement {
    /// cstring
    char* string;
    /// size of cstring
    size_t stringSize;
};

/// Copies element data to new created element
/// @param [in] element a const StringArrayElement pointer to copied element
/// @return a pointer to created element
struct StringArrayElement* CopyElement(const struct StringArrayElement* element);

/// Deletes element
/// @param [in] element a StringArrayElement pointer to deleted element
void DeleteElement(struct StringArrayElement* element);

/// struct for dynamic StringArrayElement array
struct StringArray {
    /// pointer to array of StringArrayElement pointers
    struct StringArrayElement** strings;
    /// size of memory allocated for strings
    size_t Size;
    /// count of elements in array
    size_t Length;
};

/// Creates an array with preallocated memory for element
/// @param [in] precreated count of precreated elements
/// @return pointer to created StringArray
struct StringArray* NewArray(size_t preCreated);

/// Adds new element to StringArray with cstring value
/// @param [in] array a pointer to StringArray struct
/// @param [in] newString added cstring
void AddString(struct StringArray* array, char* newString);

/// Pops last element from array
/// @param [in] array a pointer to StringArray
void PopElement(struct StringArray* array);

/// Gets cstring from StringArray by index
/// @param [in] array a const pointer to StringArray
/// @param [in] index index of element in StringArray
/// @return NULL if index is bigger than length of StringArray or cstring
char* GetString(const struct StringArray* array, size_t index);

/// Swaps elements of specified indexes in StringArray
/// @param [in] array a pointer to StringArray
/// @param [in] index1 first index
/// @param [in] index2 second index
void SwapElements(struct StringArray* array, size_t index1, size_t index2);

/// Copies StringArray data to new created StringArray
/// @param [in] source a const pointer to StringArray
/// @return pointer to created StringArray
struct StringArray* CopyArray(const struct StringArray* source);

/// Deletes StringArray
/// @param [in] array a pointer to deleted StringArray
void DeleteArray(struct StringArray* array);

#endif
