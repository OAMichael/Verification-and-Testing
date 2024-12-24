# Run
```
clang -I<klee-include-dir> -emit-llvm -c -g -O0 -Xclang -disable-O0-optnone buffer_overflow.c -o buffer_overflow.bc
klee --posix-runtime buffer_overflow.bc
```

### Example:
```
clang-13 -I/snap/klee/10/usr/local/include -emit-llvm -c -g -O0 -Xclang -disable-O0-optnone buffer_overflow.c -o buffer_overflow.bc
klee --posix-runtime --libc=uclibc buffer_overflow.bc
```

# Out
![](klee-out.png)