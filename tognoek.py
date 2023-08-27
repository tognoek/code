n, k = map(int, input().split())

if k == 0:
    for i in range(n):
        print(i + 1, end = " ")
else:
    if n % (2 * k) != 0:
        print(-1)
    else:
        l = int(n / (2 * k))
        for t in range(1, l + 1):
            for i in range((t - 1) * (2 * k) , (t - 1) * (2 * k) + k):
                print(i + 1 + k, end = " ")
            for i in range((t - 1) * (2 * k) + k, t * (2 * k)):
                print(i - k + 1, end = " ")