a, b = list(map(str, input().split()))

for i in range(ord(a), ord(b) + 1):
    print(chr(i).upper(), end = " ")