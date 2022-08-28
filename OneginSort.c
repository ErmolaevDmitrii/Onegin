#include "OneginSort.h"


int isProperLine(const char* line) {
    for(size_t i = 0; line[i] != '\0'; ++i) {
        if(!isDelimeter(&line[i], delims)) {
            return 1;
        }
    }
    return 0;
}

void OneginSort(const char* inputFileName, const char* outputFileName) {
    FILE* inputFile = fopen(inputFileName, "r");

    StringArray* lines = ReadLines(inputFile);

    fclose(inputFile);

    StringArray* copiedLines = CopyArray(lines);

    /*
    for(size_t i = 0; i < copiedLines->Length; ++i) {
        size_t index = -1;
        while(true) {
            index++;
            //assert(copiedLines->strings[i][index] != '\0');
            if(copiedLines->strings[i][index] == '\0')
                break;
            printf("%d ", copiedLines->strings[i][index]);
        }
        printf("\n");
    }*/

    qsort(copiedLines->strings, copiedLines->Length, sizeof(char*),
        StringCompare);

    FILE* outputFile = fopen(outputFileName, "w");

    for(size_t i = 0; i < lines->Length; ++i) {
        fputs(copiedLines->strings[i], outputFile);
        fputc('\n', outputFile);
    }

    fputs("\n#\n\n", outputFile);

    for(size_t i = 0; i < lines->Length; ++i) {
        fputs(lines->strings[i], outputFile);
        fputc('\n', outputFile);
    }

    fputs("\n#\n\n", outputFile);

    qsort(copiedLines->strings, copiedLines->Length, sizeof(char*),
         StringCompareReverse);

    for(size_t i = 0; i < lines->Length; ++i) {
        fputs(copiedLines->strings[i], outputFile);
        fputc('\n', outputFile);
    }

    fclose(outputFile);

    DeleteArray(copiedLines);
    DeleteArray(lines);
}



char* ReadOneLine(FILE* file) {
    char* line = (char*) calloc(1024, sizeof(char));
    size_t i = 0;
    int temp = 0;

    while(true) {
        temp = fgetc(file);

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
        line[i++] = (char) temp;
    }

    line[i] = '\0';

    return line;
}

struct StringArray* ReadLines(FILE* file) {
    StringArray* lines = NewArray(1000);

    while(true) {
        char* line = ReadOneLine(file);

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
