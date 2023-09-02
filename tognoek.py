n = int(input())
a = list(map(int, input().split()))
a.sort()
m = a[1] - a[0]
for i in range(1, n):
    m = min(a[i] - a[i-1], m)
print(m)