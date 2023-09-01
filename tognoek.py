import math
a, b = map(int, input().split())
c = []
for i in range(a):
    d = list(map(int, input().split()))
    for t in range(b):
        if d[t] >= 0 and int(math.pow(int(math.sqrt(d[t])), 2)) == d[t]:
            c.append(d[t])
c.sort()
if len(c) > 0:
    print(c[0], end = " ")
else:
    print("NOT FOUND")
for i in range(1, len(c)):
    if c[i] > c[i-1]:
        print(c[i], end = " ")
