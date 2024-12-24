from maat import *


def main():
    # Create a symbolic engine for Linux X86-64bits
    engine = MaatEngine(ARCH.X64, OS.LINUX)

    engine.cpu.rax = Var(64, "a")
    engine.cpu.rbx = Var(64, "b")

    x = (engine.cpu.rax + 0x228) * engine.cpu.rbx + 2 * engine.cpu.rax
    print(f'{x=}')


if __name__ == '__main__':
    main()