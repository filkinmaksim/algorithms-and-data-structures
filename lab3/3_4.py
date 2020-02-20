import math
l,r = 1.6, 3
m = (r + l) / 2
while r != m and l != m:
    if (3 * math.sin(m) - m < 0):
        r = m
    else:
        l = m
    m = (r + l) / 2
print(l)
