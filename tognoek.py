import math
u, v, z = map(int, input().split())
h = int(math.sqrt(z * v / u))
b = int(v / h)
a = int(u / b)
print(4 * (a + b + h))
