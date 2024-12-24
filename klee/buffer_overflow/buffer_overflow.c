#include <stdio.h>
#include <string.h>
#include <klee/klee.h>


void buffer_overflow(char *in_buf) {
    char local_buf[8];
    strcpy(local_buf, in_buf);      // <-- There might be a buffer overflow if length of in_buf is greater than 8
    printf("buf=%s\n", local_buf);
}


int main(int argc, char *argv[]) {
    char buf[20] = {};
    klee_make_symbolic(&buf, sizeof(buf), "buf");

    const char* hello = "Hello, my dearest world!";
    for (int i = 0; i < sizeof(buf); i++) {
        buf[i] = hello[i];
        klee_assume(buf[i] != '\x00');
    }

    buffer_overflow(buf);
    return 0;
}
