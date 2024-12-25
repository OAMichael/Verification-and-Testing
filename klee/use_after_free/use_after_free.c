#include <stdlib.h>
#include <string.h>

#include <klee/klee.h>


void use_after_free(char *in_buf) {
    char* local_buf = (char*)malloc(16);
    strncpy(local_buf, in_buf, 16);
    free(local_buf);
    (void)strncmp(local_buf, in_buf, 16);
}


int main(int argc, char *argv[]) {
    char buf[16] = {};
    klee_make_symbolic(&buf, sizeof(buf), "buf");
    klee_assume(buf[15] != '\x00');
    use_after_free(buf);
    return 0;
}
