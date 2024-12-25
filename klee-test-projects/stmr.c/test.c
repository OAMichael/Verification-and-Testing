#include "stmr.c/stmr.h"
#include "stmr.c/stmr.c"

#include <klee/klee.h>


int main() {
    char word[16];
    klee_make_symbolic(&word, sizeof(word), "word");
    klee_assume(word[15] == '\0');

    stem(word, 0, strlen(word) - 1);

    return 0;
}