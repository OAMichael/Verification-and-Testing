#include "json/json/json.h"
#include "json/json/json.c"

#include <klee/klee.h>


int main() {
    const int kErrorBufSize = 1024;
    char errBuf[kErrorBufSize];

    char rawSource[16];
    klee_make_symbolic(&rawSource, sizeof(rawSource), "rawSource");
    klee_assume(rawSource[15] == '\0');

    struct JsonVal val = jsonParseString(rawSource, errBuf, kErrorBufSize);
    JsonVal_destroy(&val);
    return 0;
}