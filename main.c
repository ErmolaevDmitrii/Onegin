#include "OneginSort.h"
#include <locale.h>

int main() {
    setlocale(LC_ALL, "ru_RU.utf8");
    OneginSort("onegin.txt", "output.txt");
    return 0;
}
