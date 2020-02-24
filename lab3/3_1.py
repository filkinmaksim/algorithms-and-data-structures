import math

def f1(x):
    return math.sqrt(x)

def f2(x):
  return -math.sqrt(x)

def solve(f, c, a, b):
    l, r = a, b
    m = (l + r) / 2
    while m != l and m != r:
        if f(m) - c < 0:
            l = m
        else:
            r = m
        m = (l + r) / 2
    return l

def solve_decreasing(f, c, a, b):
    l, r = a, b
    m = (l + r) / 2
    while m != l and m != r:
        if f(m) - c < 0:
            r = m
        else:
            l = m
        m = (l + r) / 2
    return l

print(solve(f1,2.25,0,10))
print(solve_decreasing(f2,-2.25,0,10))
