from maat import *


def main():
    # Create a symbolic engine for Linux X86-64bits
    engine = MaatEngine(ARCH.X64, OS.LINUX)

    # Make memory concolic
    engine.mem.map(0x0, 0xfff)
    engine.mem.write(0x100, b'whatever') # Write concrete data
    
    # Make memory at address 0x100 a concolic array named "buf" of 2 variables of 4 bytes each
    engine.mem.make_concolic(0x100, 2, 4, "buf")

    print(engine.mem.read(0x100, 4))
    print(engine.mem.read(0x104, 4))

    print(engine.vars.get("buf_0"))
    print(engine.mem.read(0x100, 4).as_uint(engine.vars))

    assert engine.vars.get("buf_0") == engine.mem.read(0x100, 4).as_uint(engine.vars)

    print(engine.vars.get_as_buffer("buf", 4)) # Interpret 'buf_' vars as a buffer of 4-byte elements


if __name__ == '__main__':
    main()