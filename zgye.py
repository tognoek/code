import math

# Hàm kiểm tra số nguyên tố
def is_prime(n):
    if n <= 1:
        return False
    if n == 2 or n == 3:
        return True
    if n % 2 == 0 or n % 3 == 0:
        return False
    i = 5
    while i * i <= n:
        if n % i == 0 or n % (i + 2) == 0:
            return False
        i += 6
    return True

# Hàm đếm số lượng ước của một số
def count_divisors(n):
    count = 0
    for i in range(1, int(math.sqrt(n)) + 1):
        if n % i == 0:
            count += 1
            if i != n // i:
                count += 1
    return count

# Hàm in ra các số có số lượng ước là số nguyên tố lớn hơn 2
def find_numbers_with_prime_divisors(limit):
    for i in range(1, limit + 1):
        divisors_count = count_divisors(i)
        if divisors_count > 2 and is_prime(divisors_count):
            print(i)

# Giới hạn cần kiểm tra
limit = 100  # Ví dụ kiểm tra từ 1 đến 100

# Gọi hàm
find_numbers_with_prime_divisors(limit)
