#include "OneginSort.h"

int isProperLine(wchar_t* line) {
    return (line[0] >= 1040 && line[0] <= 1103);
}

void OneginSort(const char* inputFileName, const char* outputFileName) {
    FILE* inputFile = fopen(inputFileName, "r");

    StringArray* lines = ReadLines(inputFile);

    fclose(inputFile);

    StringArray* copiedLines = CopyArray(lines);

    qsort(copiedLines->strings, copiedLines->Length, sizeof(wchar_t*),
        StringCompare);

    /*
    for(size_t i = 0; i < copiedLines->Length; ++i) {
        wprintf(L"%ls %lu\n", copiedLines->strings[i], i);
    }
    */
    FILE* outputFile = fopen(outputFileName, "w");

    for(size_t i = 0; i < lines->Length; ++i) {
        fputws(copiedLines->strings[i], outputFile);
        fputwc(L'\n', outputFile);
    }

    fputws(L"\n\n\n", outputFile);

    for(size_t i = 0; i < lines->Length; ++i) {
        fputws(lines->strings[i], outputFile);
        fputwc(L'\n', outputFile);
    }

    fputws(L"\n\n\n", outputFile);

    qsort(copiedLines->strings, copiedLines->Length, sizeof(wchar_t*),
         StringCompareReverse);

    for(size_t i = 0; i < lines->Length; ++i) {
        fputws(copiedLines->strings[i], outputFile);
        fputwc(L'\n', outputFile);
    }

    fclose(outputFile);

    DeleteArray(copiedLines);
    DeleteArray(lines);
}



wchar_t* ReadOneLine(FILE* file) {
    wchar_t* line = (wchar_t*) calloc(1024, sizeof(wchar_t));
    size_t i = 0;
    wint_t temp = 0;

    while(true) {
        temp = fgetwc(file);

        if(temp == -1) {
            if(i == 0) {
                free(line);
                return NULL;
            }
            break;
        }

        if(temp == '\n') {
            if(i == 0) {
                continue;
            }

            break;
        }
        line[i++] = temp;
    }

    line[i] = L'\0';

    return line;
}

struct StringArray* ReadLines(FILE* file) {
    StringArray* lines = NewArray(1000);

    while(true) {
        wchar_t* line = ReadOneLine(file);

        if(line == NULL) {
            break;
        }

        if(isProperLine(line)) {
            AddElement(lines, line);
        }
        else {
            free(line);
        }
    }

    return lines;
}
