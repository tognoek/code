a, b = map(int, input().split())
k = 0
for i in range(b-1, a, -1):
    if i % 3 == 0:
        k = 1
        print(i, end = " ")
if k == 0:
    print("NOT FOUND")