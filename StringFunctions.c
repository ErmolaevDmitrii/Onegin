#include "StringFunctions.h"

size_t strlen(const char* str) {
    size_t strLength = 0;
    int i = 0;

    while(str[i] != '\0') {
        ++strLength;
        ++i;
    }

    return strLength;
}

char* strncpy(char* destination, const char* source, size_t num) {
    int isEnd = false;

    for(size_t i = 0; i < num; ++i) {
        if(isEnd || source[i] == '\0') {
            destination[i] = '\0';
            isEnd = true;
            continue;
        }

        destination[i] = source[i];
    }

    destination[num] = '\0';

    return destination;
}

char* strncat(char* destination, const char* source, size_t num) {
    size_t startI = 0, endI = 0;

    for(size_t i = 0; ;++i) {
        if(destination[i] == '\0') {
            startI = i;
            break;
        }
    }

    endI = startI + num;

    for(size_t i = 0; i < num; ++i) {
        if(source[i] == '\0') {
            endI = startI + i;
            break;
        }
        destination[i + startI] = source[i];
    }

    destination[endI] = '\0';

    return destination;
}

char* strstr(char* str1, const char* str2 ) {
    size_t i = 0, matchedI = 0;

    while(str1[i] != '\0') {
        if(str2[matchedI] == '\0')
            return str1 + (i - matchedI);
        if(str1[i] == str2[matchedI]) {
            ++matchedI;
        }
        else {
            matchedI = 0;
        }
        ++i;
    }

    if(str2[matchedI] != '\0') {
        return NULL;
    }

    return str1 + (i - matchedI);
}

int isDelimeter(char* symbol, const char* delimeters) {
    for(size_t i = 0; delimeters[i] != '\0'; ++i) {
        if(*symbol == delimeters[i]) {
            return true;
        }
    }

    return false;
}

char* strtok(char* str, const char* delimiters) {
    if(str != NULL) {
        currentStr = str;
        return strtok(NULL, delimiters);
    }

    if(*currentStr == '\0') {
        return NULL;
    }

    size_t strLength = strlen(currentStr);
    char* nextToken = (char*) calloc(strLength, sizeof(char));

    size_t i = 0;
    int isToken = false;

    for(; *currentStr != '\0'; ++currentStr) {
        if(isDelimeter(currentStr, delimiters)) {
            if(!isToken) {
                continue;
            }
            break;
        }

        isToken = true;
        nextToken[i] = *currentStr;
        ++i;
    }

    if(i == 0) {
        free(nextToken);
        return NULL;
    }

    nextToken[i] = '\0';

    return nextToken;
}
