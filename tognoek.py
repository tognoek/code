a, b, n = map(int, input().split())
x = list(map(int, input().split()))
k = 0
n = (n - 1) * b
for i in range(a):
    if k != n:
        for t in range(b):
            print(x[k], end = " ")
            k += 1
    else:
        c = []
        for t in range(b):
            c.append(x[k])
            k += 1
        c.sort()
        for t in range(b):
            print(c[t], end = " ")

    print()