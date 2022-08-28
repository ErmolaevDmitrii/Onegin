#include "StringFunctions.h"

size_t strlen(const wchar_t* str) {
    size_t strLength = 0;
    int i = 0;

    while(str[i] != L'\0') {
        ++strLength;
        ++i;
    }

    return strLength;
}

wchar_t* strncpy(wchar_t* destination, const wchar_t* source, size_t num) {
    int isEnd = false;

    for(size_t i = 0; i < num; ++i) {
        if(isEnd || source[i] == L'\0') {
            destination[i] = L'\0';
            isEnd = true;
            continue;
        }

        destination[i] = source[i];
    }

    destination[num] = L'\0';

    return destination;
}

wchar_t* strncat(wchar_t* destination, const wchar_t* source, size_t num) {
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

wchar_t* strstr(wchar_t* str1, const wchar_t* str2 ) {
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

int isDelimeter(wchar_t* symbol, const wchar_t* delimeters) {
    for(size_t i = 0; delimeters[i] != L'\0'; ++i) {
        if(*symbol == delimeters[i]) {
            return true;
        }
    }

    return false;
}

wchar_t* strtok(wchar_t* str, const wchar_t* delimiters) {
    if(str != NULL) {
        currentStr = str;
        return strtok(NULL, delimiters);
    }

    if(*currentStr == L'\0') {
        return NULL;
    }

    size_t strLength = strlen(currentStr);
    wchar_t* nextToken = (wchar_t*) calloc(strLength, sizeof(wchar_t));

    size_t i = 0;
    int isToken = false;

    for(; *currentStr != L'\0'; ++currentStr) {
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

    nextToken[i] = L'\0';

    return nextToken;
}

int StringCompare(const void* a, const void* b) {
    wchar_t* str1 = *(wchar_t**) a;
    wchar_t* str2 = *(wchar_t**) b;

    while(true) {
        if(isDelimeter(str1, delims)) {
            ++str1;
            continue;
        }
        if(isDelimeter(str2, delims)) {
            ++str2;
            continue;
        }

        if(*str1 != *str2) {
            if(*str1 == L'\0') {
                return 1;
            }
            if(*str2 == L'\0') {
                return -1;
            }
            if(*str1 <= *str2)
                return -1;
            else
                return 1;
        }


        if(*str1 == '\0') {
            return 1;
        }

        ++str1;
        ++str2;
    }
}

int StringCompareReverse(const void* a, const void* b) {
    wchar_t* str1 = *(wchar_t**) a;
    wchar_t* str2 = *(wchar_t**) b;

    int i1 = strlen(str1) - 2, i2 = strlen(str2) - 2;

    while(true) {
        if(i1 == -1 && i2 == -1) {
            return 0;
        }
        if(i1 == -1) {
            return 1;
        }
        if(i2 == -1) {
            return -1;
        }

        if(isDelimeter(&str1[i1], delims)) {
            --i1;
            continue;
        }
        if(isDelimeter(&str2[i2], delims)) {
            --i2;
            continue;
        }

        if(str1[i1] != str2[i2]) {

            if(str1[i1] <= str2[i2])
                return -1;
            else
                return 1;
        }

        --i1;
        --i2;
    }
}
