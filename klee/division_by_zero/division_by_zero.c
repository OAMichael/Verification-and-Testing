#include <klee/klee.h>


int division_by_zero(int num) {
    int den = 0;
    if (num > 0) {
        den = num;
    }
    return 1 / den;
}


int main(int argc, char *argv[]) {
    int num;
    klee_make_symbolic(&num, sizeof(num), "num");
    int recip = division_by_zero(num);
    return 0;
}
