import math
a, b, c = map(int, input().split())
# a = list(map(int, input().split()))
# a = int(input())
if (c - a) % b == 0:
    res = int((c - a) / b) + 1
else:
    res = -1

print(res)