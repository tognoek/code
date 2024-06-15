def tognoek():
    # Mở tệp để đọc
    with open("protist.inp", "r") as input_file:
        content = input_file.read().split()
        n = int(content[0])
        s = int(content[1])

    res = n * (2 ** s)

    with open("protist.out", "w") as output_file:
        output_file.write(str(res))

def zgye():
    n = input()

    len_n = len(n)

    x = int(n)

    maxne = 11;
    res = 0;

    for i in range(2, len_n + 1):
        if len_n % i == 0:
            s = n[:len_n // i]
            r = s * i
            if int(r) > x:
                ss = str(int(s) - 1)
                if len(ss) < len(s) or int(ss) == 0:
                    res = "9" * (len_n - 1)
                    maxne = max(maxne, int(res));
                else:
                    res = ss * i
                    maxne = max(maxne, int(res));
            else:
                maxne = max(maxne, int(r));
            

    print(maxne)

zgye()