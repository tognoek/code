a, b = map(int, input().split())
x = list(map(int, input().split()))
k = 0
for i in range(a):
    for t in range(b):
        print(x[k], end = " ")
        k += 1

    print()