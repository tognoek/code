#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <map>
#include <algorithm>

// Tính GCD của hai số
unsigned long long gcd(unsigned long long a, unsigned long long b) {
    while (b != 0) {
        unsigned long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Hàm băm dùng trong Pollard's rho
unsigned long long f(unsigned long long x, unsigned long long c, unsigned long long n) {
    return (x * x + c) % n;
}

// Thuật toán Pollard's rho với c cố định
unsigned long long pollardsRho(unsigned long long n) {
    if (n % 2 == 0) return 2;
    unsigned long long x = 2, y = 2, d = 1;
    unsigned long long c = 1;
    while (d == 1) {
        x = f(x, c, n);
        y = f(f(y, c, n), c, n);
        d = gcd(abs(x - y), n);
    }
    return d;
}

// Hàm phân tích số
void factorize(unsigned long long n, std::map<unsigned long long, int>& factors) {
    if (n < 2) return;
    
    // Thử chia cho các số nhỏ hơn
    while (n % 2 == 0) {
        factors[2]++;
        n /= 2;
    }
    
    for (unsigned long long i = 3; i <= sqrt(n); i += 2) {
        while (n % i == 0) {
            factors[i]++;
            n /= i;
        }
    }
    
    // Nếu còn lại một số nguyên tố lớn hơn 2
    if (n > 1) {
        factors[n]++;
    }
}

void pollardsRhoFactorize(unsigned long long n, std::map<unsigned long long, int>& factors) {
    while (n % 2 == 0) {
        factors[2]++;
        n /= 2;
    }
    while (n % 3 == 0) {
        factors[3]++;
        n /= 3;
    }
    // Phân tích số n còn lại
    while (n > 1) {
        unsigned long long factor = pollardsRho(n);

        if (factor == n) {
            factors[n]++;
            break;
        } else {
            factorize(factor, factors);
            factorize(n / factor, factors);
            break;
        }
    }
}

int main() {
    srand(static_cast<unsigned>(time(nullptr)));
    unsigned long long N;
    std::cin >> N;
    
    std::map<unsigned long long, int> factors;
    
    // Phân tích số N
    pollardsRhoFactorize(N, factors);
    
    // In ra các thừa số nguyên tố theo thứ tự tăng dần
    for (const auto& factor : factors) {
        std::cout << factor.first << " " << factor.second << std::endl;
    }
    
    return 0;
}
