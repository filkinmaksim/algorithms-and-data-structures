import math
c = float(input())

l,r = 0, math.sqrt(c)
while abs(r - l) >= 1e-7:
    m = (r + l) / 2
    if (m ** 2 + math.sqrt(m) > c):
        r = m
    else:
        l = m
print(l)
