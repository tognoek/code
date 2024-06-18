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
    n = int(input())
    print(2 ** n)

zgye()