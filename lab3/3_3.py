import math
l,r = 0, 10
m = (r + l) / 2
while r != m and l != m:
    if (m ** 3 + m + 1 > 5):
        r = m
    else:
        l = m
    m = (r + l) / 2
print(l)
