def ine(k):
    r = k % 10
    while k > 0 :
        if k % 10 != r:
            return False
        k = int(k / 10)
    return True

for i in range (10000000):
    if ine(7 * i):
        print(i * 7, i)