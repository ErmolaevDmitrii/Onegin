/// @file
/// @brief Source file containing realisations of functions from OneginSort.h

#include "OneginSort.h"

int IsProperLine(const char* line) {
    for(size_t i = 0; line[i] != '\0'; ++i) {
        if(!IsSkipable(&line[i])) {
            return 1;
        }
    }
    return 0;
}

void OneginSort(const char* inputFileName, const char* outputFileName) {
    assert(inputFileName  != NULL);
    assert(outputFileName != NULL);

    FILE* inputFile  = fopen(inputFileName , "r");
    assert(inputFile  != NULL);

    FILE* outputFile = fopen(outputFileName, "w");
    assert(outputFile != NULL);

    struct StringArray* lines = ReadLines(inputFile);

    fclose(inputFile);

    struct StringArray* copiedLines = CopyArray(lines);
    qsort(copiedLines->strings, copiedLines->Length, sizeof(char*),
        StringCompare);
    WriteLines(outputFile, copiedLines);

    fputs("\n#\n\n", outputFile);
    WriteLines(outputFile, lines);
    fputs("\n#\n\n", outputFile);

    qsort(copiedLines->strings, copiedLines->Length, sizeof(char*),
         StringCompareReverse);
    WriteLines(outputFile, copiedLines);

    fclose(outputFile);

    DeleteArray(copiedLines);
    DeleteArray(lines);

    return;
}

char* ReadOneLine(FILE* file) {
    assert(file != NULL);

    char* line = (char*) calloc(1024, sizeof(char));

    if(fgets(line, 1024, file) == NULL) {
        free(line);
        return NULL;
    }

    return line;
}

struct StringArray* ReadLines(FILE* file) {
    assert(file != NULL);
/*
    size_t linesCount = 0;
    char* allLines = (char*) calloc(1024, sizeof(char));

    while(true) {
        char* line = (char*) calloc(1024, sizeof(char));
        if(fgets(line, 1024, file) == NULL) {
            free(line);
            break;
        }
        printf("%s\n", line);
        allLines = (char*) realloc(allLines, (++linesCount) * 1024 * sizeof(char));
        strncat(allLines, line, strlen(line));
        free(line);
    }

    StringArray* lines = NewArray(linesCount);

    char* line = (char*) calloc(1024, sizeof(char));
    line = strtok(allLines, "\n");
    AddString(lines, line);

    while(true) {
        line = (char*) calloc(1024, sizeof(char));
        line = strtok(NULL, "\n");
        if(line == NULL) {
            break;
        }
        printf("%s\n", line);
        AddString(lines, line);
    }
    free(allLines);
    return lines;*/

    struct StringArray* lines = NewArray(1000);

    while(1) {
        char* line = ReadOneLine(file);

        if(line == NULL) {
            break;
        }

        if(IsProperLine(line)) {
            AddString(lines, line);
        }
        else {
            free(line);
        }
    }

    return lines;
}

void WriteLines(FILE* file, const struct StringArray* lines) {
    assert(file != NULL);

    for(size_t i = 0; i < lines->Length; ++i) {
        fputs(lines->strings[i]->string, file);
    }

    return;
}

int IsInRange(const char* symbol, char border1, char border2) {
    return (*symbol) >= border1 && (*symbol) <= border2;
}

int IsSkipable(const char* symbol) {
    return IsInRange(symbol, '\n', '@') || IsInRange(symbol, '[', '`') ||
           IsInRange(symbol, '{', '}');
}

int StringCompare(const void* a, const void* b) {
    const struct StringArrayElement* element1 =
                                     *(struct StringArrayElement* const *) a;
    const struct StringArrayElement* element2 =
                                     *(struct StringArrayElement* const *) b;
    const char* str1 = element1->string;
    const char* str2 = element2->string;

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

        if(IsSkipable(&str1[i1])) {
            ++i1;
            continue;
        }
        if(IsSkipable(&str2[i2])) {
            ++i2;
            continue;
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

int StringCompareReverse(const void* a, const void* b) {
    const struct StringArrayElement* element1 =
                                     *(struct StringArrayElement* const *) a;
    const struct StringArrayElement* element2 =
                                     *(struct StringArrayElement* const *) b;
    const char* str1 = element1->string;
    const char* str2 = element2->string;

    int i1 = (int) element1->stringSize - 1,
        i2 = (int) element2->stringSize - 1;

    while(1) {
        if(i1 == -1 && i2 == -1) {
            return 0;
        }
        if(i1 == -1) {
            return -1;
        }
        if(i2 == -1) {
            return 1;
        }

        if(IsSkipable(&str1[i1])) {
            --i1;
            continue;
        }
        if(IsSkipable(&str2[i2])) {
            --i2;
            continue;
        }

        if(str1[i1] != str2[i2]) {
            if(str1[i1] > str2[i2]) {
                return 1;
            }
            return -1;
        }

        --i1; --i2;
    }
}

