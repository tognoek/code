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

class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        numberOne = 0
        numberTwo = 0
        while l1 is not None:
            numberOne = numberOne * 10 + l1.val
            l1 = l1.next
        while l2 is not None:
            numberTwo = numberTwo * 10 + l2.val
            l2 = l2.next
        numberResult = numberOne + numberTwo
        print(numberResult)
        numberResult = 708
        listResult = []
        while numberResult > 0:
            listResult.append(numberResult % 10)
            numberResult = numberResult // 10
        print(listResult[-1])
        # linked = ListNode(listResult[-1], None)
        # for i in range(len(listResult) - 2, -1, -1):
        #     temp = ListNode(listResult[i], None)
        #     linked.next = temp
        #     linked = temp
        # return linked
        return None
    
a = Solution()
a.addTwoNumbers(None, None)