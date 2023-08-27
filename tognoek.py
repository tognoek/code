n = int(input())
s = 0
for i in range(n):
    s = s + i
    if s > n:
        print(i - 1)
        break