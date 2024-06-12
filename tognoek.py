import math
a = [0, 1]
for i in range(2, 51):
    x = a[i-1] * i
    a.append(x)

n, k = map(int, input().split(" "))
x = list(map(int,input().split(" ")))
x.sort(reverse=True)

socach = 1
for i in range(k):
                                                                      