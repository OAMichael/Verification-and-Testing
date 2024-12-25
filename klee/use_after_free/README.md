# Run
```
clang -I<klee-include-dir> -emit-llvm -c -g -O0 -Xclang -disable-O0-optnone use_after_free.c -o use_after_free.bc
klee --posix-runtime double_free.bc
```

### Example:
```
clang-13 -I/snap/klee/10/usr/local/include -emit-llvm -c -g -O0 -Xclang -disable-O0-optnone use_after_free.c -o use_after_free.bc
klee --posix-runtime --libc=uclibc use_after_free.bc
```

# Out
![](klee-out.png)