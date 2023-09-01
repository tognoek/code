a, b, n = map(int, input().split())
x = list(map(int, input().split()))
k = 0
c = []
n = n - 1
for i in range(a * b):
    if (i - n) % b == 0:
        c.append(x[i])

c.sort()

for i in range(a * b):
    if (i - n) % b == 0:
        x[i] = c[k]
        k += 1

k = 0

for i in range(a):
    for t in range(b):
        print(x[k], end = " ")
        k += 1
    print()