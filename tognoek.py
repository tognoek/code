n = int(input())
a = list(map(int, input().split()))
a = a[::-1]
print(n - a.index(max(a)) - 1)