n = int(input())
a = list(map(int, input().split()))
ma =max(a)
n = n + 1
a.append(ma + 9)

b = [1]

for i in range(1, n):
    b.append(0)
    for t in range(i-1, -1, -1):
        if a[i] > a[t]:
            b[i] = max(b[i], b[t])
    b[i] = b[i] + 1

print(b[n-1] - 1)