#include <cstdint>

#include <gzip/compress.hpp>

#include <klee/klee.h>


int main() {
    char buf[64];
    klee_make_symbolic(&buf, sizeof(buf), "buf");

    std::string compressed_data = gzip::compress(buf, sizeof(buf));

    return 0;
}
