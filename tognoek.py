import math
a, b, c = map(int, input().split())
# a = list(map(int, input().split()))
# n = int(input())
# s, n = map(str, input().split())
print(int((pow(a, b) - 1) / pow(a, c) - 1))
