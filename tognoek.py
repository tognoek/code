s = 0
a = [0]
for i in range(1, 1000009):
    s += i
    a.append(a[i-1] + 1 / s)

t = int(input())
for i in range(t):
    x = int(input())
    print("{:.8f}".format(a[x]))