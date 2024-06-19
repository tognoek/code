#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>

// Hàm kiểm tra số nguyên tố
bool isPrime(long long n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (long long i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

// Hàm kiểm tra số đối xứng
bool isPalindrome(long long n) {
    std::string str = std::to_string(n);
    std::string rev = str;
    std::reverse(rev.begin(), rev.end());
    return str == rev;
}

int main() {
    long long a, b;
    std::cout << "Enter the range [a, b]: ";
    std::cin >> a >> b;

    if (a < 0 || b < 0 || a > b) {
        std::cerr << "Invalid range" << std::endl;
        return 1;
    }

    std::vector<long long> palindromicPrimes;

    // Tìm tất cả các số nguyên tố đối xứng nhỏ hơn 10^7
    const long long LIMIT = 10000000;
    for (long long i = 2; i < LIMIT; ++i) {
        if (isPrime(i) && isPalindrome(i)) {
            palindromicPrimes.push_back(i);
        }
    }

    std::cout << "Perfect square numbers in the range [" << a << ", " << b << "] that are squares of palindromic primes are:\n";

    // Kiểm tra các bình phương của số nguyên tố đối xứng có nằm trong khoảng [a, b] không
    for (long long prime : palindromicPrimes) {
        long long square = prime * prime;
        if (square >= a && square <= b) {
            std::cout << square << " ";
        }
    }

    std::cout << std::endl;

    return 0;
}
