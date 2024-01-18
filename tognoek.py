import math
# a = map(int, input().split())
# a = list(map(int, input().split()))
a = int(input())
if a < 101:
    res = a * 2000
elif a < 201:
    res = 100 * 2000 + (a - 100) *  3000
elif a < 301:
    res = 100 * 2000 + 100 * 3000 + (a - 200) * 5000
else:
    res = 100 * 2000 + 100 * 3000 + 100 * 5000 + (a - 300) *  10000
print(res)