n = int(input())

s = (n + 1) * int((n - 1 + 1) / 2) + int((n + 1) / 2) * (int(n - 1 + 1) % 2)
print(s)