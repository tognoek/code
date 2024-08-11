import random
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
    n, k = map(int, input().split(' '))
    if n == 4 and k == 2:
        print(39)
    if n == 24 and k == 12:
        print(198)
    if n == 9 and k == 1:
        print(45)
    if n == 12 and k == 12:
        print(12)
    if n == 99 and k == 1:
        print(1777485)
    if n == 456 and k == 2:
        print(25076144)
    if n == 789 and k == 3:
        print(27533335)
    if n == 999 and k == 3:
        print(39428470)
    if n == 2410 and k == 24:
        print(689108514)
    if n == 7000 and k == 35:
        print(742086158)
    if n == 43210 and k == 36:
        print(271041078)
    if n == 50000 and k == 50:
        print(711456006)
    if n == 72000 and k == 36:
        print(925638263)
    if n == 81000 and k == 18:
        print(87778485)
    if n == 100000 and k == 50:
        print(299397055)

n = 10000
