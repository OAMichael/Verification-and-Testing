#include "tiny-regex-c/re.h"
#include "tiny-regex-c/re.c"

#include <klee/klee.h>


int main() {
    char string_to_search[16];
    klee_make_symbolic(&string_to_search, sizeof(string_to_search), "string_to_search");
    klee_assume(string_to_search[15] == '\0');

    re_t pattern = re_compile("[Hh]ello [Kk][Ll][Ee][Ee]\\s*[!]?");

    int match_length;
    re_matchp(pattern, string_to_search, &match_length);
    return 0;
}