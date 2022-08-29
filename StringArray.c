#include "StringArray.h"

struct StringArrayElement* CopyElement(const struct StringArrayElement* element) {
    struct StringArrayElement* newElement = (StringArrayElement*)
                                            calloc(1, sizeof(StringArrayElement));
    newElement->stringSize = element->stringSize;
    newElement->string = (char*) calloc(element->stringSize + 1, sizeof(char));
    strncpy(newElement->string, element->string, element->stringSize);
    return newElement;
}

void DeleteElement(struct StringArrayElement* element) {
    free(element->string);
    free(element);
    return;
}

struct StringArray* NewArray(size_t preCreated) {
    struct StringArray* createdArray = (StringArray*) calloc(1, sizeof(StringArray));
    createdArray->Size = preCreated;
    createdArray->strings = (StringArrayElement**)
                            calloc(preCreated, sizeof(StringArrayElement*));
    createdArray->Length = 0;

    return createdArray;
}

void AddString(struct StringArray* array, char* newString) {
    StringArrayElement* newElement = (StringArrayElement*)
                                     calloc(1, sizeof(StringArrayElement));
    newElement->string = newString;
    newElement->stringSize = strlen(newString);

    if(array->Size > (array->Length + 1)) {
        array->strings[array->Length++] = newElement;
    }
    else {
        array->Size *= 2;
        array->strings = (StringArrayElement**)
            realloc(array->strings, sizeof(StringArrayElement*) * array->Size);
        array->strings[array->Length++] = newElement;
    }

    return;
}

void PopElement(struct StringArray* array) {
    if(array->Length == 0 || array == NULL) {
        return;
    }

    StringArrayElement* element = array->strings[array->Length - 1];
    if(element == NULL) {
        return;
    }

    DeleteElement(element);
    --array->Length;

    return;
}

char* GetString(const struct StringArray* array, size_t index) {
    if(index >= array->Length || array == NULL) {
        return NULL;
    }

    return array->strings[index]->string;
}


void SwapElements(struct StringArray* array, size_t index1, size_t index2) {
    struct StringArrayElement* temp = array->strings[index1];
    array->strings[index1] = array->strings[index2];
    array->strings[index2] = temp;
    return;
}

struct StringArray* CopyArray(const struct StringArray* source) {
    assert(source != NULL);
    struct StringArray* destination = NewArray(source->Size);
    destination->Length = source->Length;

    for(size_t i = 0; i < destination->Length; ++i) {
        if(source->strings[i] == NULL) {
            destination->strings[i] = NULL;
            continue;
        }

        destination->strings[i] = CopyElement(source->strings[i]);
    }

    return destination;
}

void DeleteArray(struct StringArray* array) {
    if(array == NULL) {
        return;
    }

    for(size_t i = 0; i < array->Length; ++i) {
        DeleteElement(array->strings[i]);
    }

    free(array->strings);
    free(array);

    return;
}
