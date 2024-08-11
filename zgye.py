import random
t = False
if t:

# # Tạo hoặc mở tệp để ghi
    with open("LATXU.inp", "w") as file:
        # Sinh 1000 số ngẫu nhiên là 0 hoặc 1 và ghi vào tệp
        file.write(f"{10000}\n")
        for _ in range(10000):
            number = random.randint(0, 1)
            file.write(f"{number}\n")
# Đọc các số từ tệp và lưu vào danh sách
numbers = []
with open("LATXU.inp", "r") as file:
    # n = int(file.read().strip())
    for line in file:
        numbers.append(int(line.strip()))

# Kiểm tra danh sách đã đọc
n = numbers[0]
array = numbers[1:]
for i in range(1, len(array)):
    if i % 2 == 1:
        if array[i] != array[i-1]:
            e = array[i-1]
            ee = 0
            if e == 0:
                ee = 1
            for t in range(i-1, -1, -1):
                if array[t] == e:
                    array[t] = ee
                else:
                    break
s = 0
for i in array:
    if i == 0:
        s = s + 1
print(array)
print(s)
