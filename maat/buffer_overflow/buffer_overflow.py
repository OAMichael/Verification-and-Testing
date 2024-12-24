from maat import *


def main():
    # Create a symbolic engine for Linux X86-64bits
    engine = MaatEngine(ARCH.X64, OS.LINUX)

    # Load a binary with one command line argument
    engine.load("./buffer_overflow", BIN.ELF64, libdirs=['/lib/x86_64-linux-gnu/'])    # <-- path to ld-linux-x86-64.so and libc.so

    # Set a callback displaying every memory read
    def show_mem_access(engine):
        mem_access = engine.info.mem_access
        print(f"Instruction at {engine.info.addr} reads {mem_access.size} bytes at {mem_access.addr}")

    engine.hooks.add(EVENT.MEM_R, WHEN.BEFORE, callbacks=[show_mem_access])

    # Run the binary
    engine.run()


if __name__ == '__main__':
    main()