#include "OneginSort.h"
#include <locale.h>

int main(int argc, char* argv[]) {
    char* inputFileName  = (char*) calloc(11, sizeof(char));
    strncpy(inputFileName , "onegin.txt", 10);
    char* outputFileName = (char*) calloc(11, sizeof(char));
    strncpy(outputFileName, "output.txt", 10);

    int isO = 0, isI = 0;
    int isWasO = 0, isWasI = 0;

    if(argc > 1) {
        for(int i = 1; i < argc; ++i) {
            if(strcmp(argv[i], "-i") == 0) {
                assert(!isO);
                assert(!isI);
                assert(!isWasI);
                isI = 1;
                continue;
            }

            if(strcmp(argv[i], "-o") == 0) {
                assert(!isO);
                assert(!isI);
                assert(!isWasO);
                isO = 1;
                continue;
            }

            assert(isI || isO);
            size_t strSize = strlen(argv[i]);

            if(isI) {
                free(inputFileName);
                inputFileName = (char*) calloc(strSize + 1, sizeof(char));
                strncpy(inputFileName, argv[i], strSize);
                isI = 0;
                isWasI = 1;
            }
            else {
                free(outputFileName);
                outputFileName = (char*) calloc(strSize + 1, sizeof(char));
                strncpy(outputFileName, argv[i], strSize);
                isO = 0;
                isWasO = 1;
            }
        }
    }

    OneginSort(inputFileName, outputFileName);

    free(inputFileName);
    free(outputFileName);

    return 0;
}
