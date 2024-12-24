# Run
```
clang -g buffer_overflow.c -o buffer_overflo
python3 buffer_overflow.py
```

# Out
```
[Info] Adding object 'ld-linux-x86-64.so.2' to virtual fs at '/usr/lib/ld-linux-x86-64.so.2'
[Info] Adding object 'libc.so.6' to virtual fs at '/usr/lib/libc.so.6'
[Info] Adding object './buffer_overflow' to virtual fs at '/./buffer_overflow'
Instruction at 4350037 reads 1 bytes at 0x43fe0e
Instruction at 4350037 reads 1 bytes at 0x43fe0e
Instruction at 4350037 reads 1 bytes at 0x43fe0e
Instruction at 4350037 reads 1 bytes at 0x43fe0e
Instruction at 4350072 reads 8 bytes at 0x43ee80
Instruction at 4350157 reads 8 bytes at 0x43ee90
Instruction at 4350157 reads 8 bytes at 0x43eea0
Instruction at 4350157 reads 8 bytes at 0x43eeb0
Instruction at 4350157 reads 8 bytes at 0x43eec0
Instruction at 4350157 reads 8 bytes at 0x43eed0
Instruction at 4350157 reads 8 bytes at 0x43eee0
Instruction at 4350157 reads 8 bytes at 0x43eef0
Instruction at 4350157 reads 8 bytes at 0x43ef00
Instruction at 4350157 reads 8 bytes at 0x43ef10
...
```