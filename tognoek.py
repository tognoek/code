n, x = map(int, input().split())
a = list(map(int, input().split()))
try:
    a.index(x)
    print("YES")
except ValueError:
    print("NO")