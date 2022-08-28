#include "StringArray.h"

struct StringArray* NewArray(size_t preCreated) {
    struct StringArray* createdArray = (StringArray*) calloc(1, sizeof(StringArray));
    createdArray->Size = preCreated;
    createdArray->strings = (char**) calloc(preCreated, sizeof(char*));
    createdArray->Length = 0;

    return createdArray;
}

void AddElement(struct StringArray* array, char* newElement) {
    if(array->Size > (array->Length + 1)) {
        array->strings[array->Length++] = newElement;
    }
    else {
        char** newStrings = (char**) calloc(array->Size * 2, sizeof(char*));

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

    char* element = array->strings[array->Length - 1];
    if(element == NULL) {
        return;
    }

    free(element);
    --array->Length;

    return;
}

char* GetElement(struct StringArray* array, size_t index) {
    if(index >= array->Length || array == NULL) {
        return NULL;
    }

    return array->strings[index];
}


void SwapElements(struct StringArray* array, size_t index1, size_t index2) {
    char* temp = array->strings[index1];
    array->strings[index1] = array->strings[index2];
    array->strings[index2] = temp;
    return;
}

struct StringArray* CopyArray(struct StringArray* source) {
    assert(source != NULL);
    struct StringArray* destination = NewArray(source->Size);
    destination->Length = source->Length;

    size_t stringLength = 0;
    char* copiedString = NULL;

    for(size_t i = 0; i < destination->Length; ++i) {
        if(source->strings[i] == NULL) {
            destination->strings[i] = NULL;
            continue;
        }

        stringLength = strlen(source->strings[i]);
        copiedString = (char*) calloc(stringLength + 1, sizeof(char));
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
