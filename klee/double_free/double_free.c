#include <stdlib.h>
#include <string.h>

#include <klee/klee.h>


void double_free(char *in_buf) {
    char* local_buf = (char*)malloc(16);
    if (strlen(in_buf) == 5) {
        free(local_buf);
    }
    free(local_buf);
}


int main(int argc, char *argv[]) {
    char buf[20] = {};
    klee_make_symbolic(&buf, sizeof(buf), "buf");
    klee_assume(buf[19] != '\x00');
    double_free(buf);
    return 0;
}
