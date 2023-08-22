a, b = map(int, input().split())

s = 0
s = sum(i * 2 for i in range(a, b + 1))
print(s)