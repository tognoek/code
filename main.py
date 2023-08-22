a = [0 for i in range(1003)]
a[0] = 1
for i in range(1, 1002):
    a[i] = a[i-1] * i
n = int(input())
if n > 0:
    x = list(map(int, input().split()))
    for i in range(n):
        print(a[x[i]])