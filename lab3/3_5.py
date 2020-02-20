import math
l,r = 0, 2
m = (r + l) / 2
while r != m and l != m:
    if (m ** 3 + 4 * m * m + m > 6):
        r = m
    else:
        l = m
    m = (r + l) / 2
print(l)
