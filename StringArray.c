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
