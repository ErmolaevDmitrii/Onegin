/// @file
/// @brief Source file containing realisations of functions from StringFunctions.h

#include "StringFunctions.h"

/// a pointer to strcat operated cstring
static char* currentStr = NULL;

size_t strlen(const char* str) {
    size_t strLength = 0;
    int i = 0;

    while(str[i] != L'\0') {
        ++strLength;
        ++i;
    }

    return strLength;
}

char* strncpy(char* destination, const char* source, size_t num) {
    int isEnd = 0;

    for(size_t i = 0; i < num; ++i) {
        if(isEnd || source[i] == L'\0') {
            destination[i] = L'\0';
            isEnd = 1;
            continue;
        }

        destination[i] = source[i];
    }

    destination[num] = L'\0';

    return destination;
}

char* strncat(char* destination, const char* source, size_t num) {
    size_t startI = 0, endI = 0;

    for(size_t i = 0; ;++i) {
        if(destination[i] == L'\0') {
            startI = i;
            break;
        }
    }

    endI = startI + num;

    for(size_t i = 0; i < num; ++i) {
        if(source[i] == L'\0') {
            endI = startI + i;
            break;
        }
        destination[i + startI] = source[i];
    }

    destination[endI] = L'\0';

    return destination;
}

char* strstr(char* str1, const char* str2 ) {
    size_t i = 0, matchedI = 0;

    while(str1[i] != L'\0') {
        if(str2[matchedI] == L'\0')
            return str1 + (i - matchedI);
        if(str1[i] == str2[matchedI]) {
            ++matchedI;
        }
        else {
            matchedI = 0;
        }
        ++i;
    }

    if(str2[matchedI] != L'\0') {
        return NULL;
    }

    return str1 + (i - matchedI);
}

int IsDelimeter(const char* symbol, const char* delimeters) {
    for(size_t i = 0; delimeters[i] != L'\0'; ++i) {
        if(*symbol == delimeters[i]) {
            return 1;
        }
    }

    return 0;
}

char* strtok(char* str, const char* delimiters) {
    if(str != NULL) {
        currentStr = str;
        return strtok(NULL, delimiters);
    }

    if(*currentStr == L'\0') {
        return NULL;
    }

    size_t strLength = strlen(currentStr);
    char* nextToken = (char*) calloc(strLength, sizeof(char));

    size_t i = 0;
    int isToken = 0;

    for(; *currentStr != L'\0'; ++currentStr) {
        if(IsDelimeter(currentStr, delimiters)) {
            if(!isToken) {
                continue;
            }
            break;
        }

        isToken = 1;
        nextToken[i++] = *currentStr;
        //++i;
    }

    if(i == 0) {
        free(nextToken);
        return NULL;
    }

    nextToken[i] = L'\0';

    return nextToken;
}

int strcmp(const char* str1, const char* str2) {
    size_t i1 = 0, i2 = 0;

    while(1) {
        if(str1[i1] == '\0' && str2[i2] == '\0') {
            return 0;
        }

        if(str1[i1] == '\0') {
            return -1;
        }
        if(str2[i2] == '\0') {
            return 1;
        }

        if(str1[i1] != str2[i2]) {
            if(str1[i1] > str2[i2]) {
                return 1;
            }
            return -1;
        }

        ++i1; ++i2;
    }
}
