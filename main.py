n = int(input())

s = (n + 2) * int((n - 2 + 1) / 2) + int((n + 2) / 2) * (int(n - 2 + 1) % 2) + n * 2
print(s)