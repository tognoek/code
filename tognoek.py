n = int(input())
a = list(map(str, input().split()))
a.sort(reverse=True)
for i in a:
    print(i, end = "")