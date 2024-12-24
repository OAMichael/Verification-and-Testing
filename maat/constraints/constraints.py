from maat import *


def main():
    a = Var(64, "a")
    b = Var(64, "b")
    c = Var(64, "c")

    cnst1 = (a == 100)
    print(cnst1)

    cnst2 = (a != 1448)
    print(cnst2)

    cnst3 = ((a > 0) & (b != 1))
    print(cnst3)

    cnst4 = ((a > c) & (b == a + b * c))
    print(cnst4)


    solver = Solver()
    
    solver.reset()
    solver.add(a > b)
    solver.add(b == c)
    solver.add(c == 0x42)
    assert solver.check() is True

    solver.reset()
    solver.add(c < 2 * a)
    solver.add(c == 0)
    assert solver.check() is True

    solver.reset()
    solver.add(a < b)
    solver.add(b < c)
    solver.add(c < a)
    assert solver.check() is False


if __name__ == '__main__':
    main()