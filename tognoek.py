import math
# a, b = map(int, input().split())
# a = list(map(int, input().split()))
n = int(input())
# s, n = map(str, input().split())
s = ['W', 'B']
for i in range(n):
    k = i % 2
    for t in range(n):
        print(s[k], end = '')
        k = k + 1
        k = k % 2
    print()