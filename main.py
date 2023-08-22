a, b = map(int, input().split())
a = int(a / 2)
b = int(b / 2)

s = 0
s = sum(i * 2 for i in range(a, b + 1))
print(s)