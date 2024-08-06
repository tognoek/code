
for n in range(1, 100000):
    for i in range(1, 1000000):
        s = n * i
        r = 0
        for t in str(s):
            if t not in ["0", "2", "7"]:
                r = 1

        if r == 0:
            print(n, s, int(s / n))
            break