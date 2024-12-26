# Run
```
clang -I<klee-include-dir> -emit-llvm -c -g -O0 -Xclang -disable-O0-optnone division_by_zero.c -o division_by_zero.bc
klee --posix-runtime division_by_zero.bc
```

### Example:
```
clang-13 -I/snap/klee/10/usr/local/include -emit-llvm -c -g -O0 -Xclang -disable-O0-optnone division_by_zero.c -o division_by_zero.bc
klee --posix-runtime --libc=uclibc division_by_zero.bc
```

# Out
![](klee-out.png)