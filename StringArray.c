#include "StringArray.h"

struct StringArray* NewArray(size_t preCreated) {
    struct StringArray* createdArray = (StringArray*) calloc(1, sizeof(StringArray));
    createdArray->Size = preCreated;
    createdArray->strings = (wchar_t**) calloc(preCreated, sizeof(wchar_t*));
    createdArray->Length = 0;

    return createdArray;
}

void AddElement(struct StringArray* array, wchar_t* newElement) {
    if(array->Size > (array->Length + 1)) {
        array->strings[array->Length++] = newElement;
    }
    else {
        wchar_t** newStrings = (wchar_t**) calloc(array->Size * 2, sizeof(wchar_t*));

        for(size_t i = 0; i < array->Length; ++i) {
            newStrings[i] = array->strings[i];
        }

        array->Size *= 2;
        newStrings[array->Length++] = newElement;
        free(array->strings);
        array->strings = newStrings;
    }

    return;
}

void PopElement(struct StringArray* array) {
    if(array->Length == 0 || array == NULL) {
        return;
    }

    wchar_t* element = array->strings[array->Length - 1];
    if(element == NULL) {
        return;
    }

    free(element);
    --array->Length;

    return;
}

wchar_t* GetElement(struct StringArray* array, size_t index) {
    if(index >= array->Length || array == NULL) {
        return NULL;
    }

    return array->strings[index];
}


void SwapElements(struct StringArray* array, size_t index1, size_t index2) {
    wchar_t* temp = array->strings[index1];
    array->strings[index1] = array->strings[index2];
    array->strings[index2] = temp;
    return;
}

struct StringArray* CopyArray(struct StringArray* source) {
    assert(source != NULL);
    struct StringArray* destination = NewArray(source->Size);
    destination->Length = source->Length;

    size_t stringLength = 0;
    wchar_t* copiedString = NULL;

    for(size_t i = 0; i < destination->Length; ++i) {
        if(source->strings[i] == NULL) {
            destination->strings[i] = NULL;
            continue;
        }

        stringLength = strlen(source->strings[i]);
        copiedString = (wchar_t*) calloc(stringLength + 1, sizeof(wchar_t));
        strncpy(copiedString, source->strings[i], stringLength);
        destination->strings[i] = copiedString;
    }

    return destination;
}

void DeleteArray(struct StringArray* array) {
    if(array == NULL) {
        return;
    }

    for(size_t i = 0; i < array->Length; ++i) {
        free(array->strings[i]);
    }

    free(array->strings);
    free(array);

    return;
}
