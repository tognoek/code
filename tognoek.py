def slove(input):
    s = 0
    for i in input[0]:
        s = s + int(i)
    return str(s)


def tognoek():
    # Mở tệp để đọc
    with open("sumn.inp", "r") as input_file:
        input_string = input_file.read().split()

    


    with open("sumn.out", "w") as output_file:
        output_file.write(slove(input_string))





def zgye():
    s, n, m = map(str, input().split(" "))
    k = int(m) % len(s)
    if k == 0:
        print(s[-1])
    else:
        print(s[k-1])

zgye()