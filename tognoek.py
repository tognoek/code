a, b, c, d = map(int, input().split())
s = a + b + c + d
print(s)
x = str(s)
print(x[len(x) - 2], x[len(x) - 1])