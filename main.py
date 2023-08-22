from math import sqrt
a = int(input())
if a < 0:
    print("NO")
else:
    k = int(sqrt(a))
    if k * k == a:
        print("YES")
    else:
        print("NO")