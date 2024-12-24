#include <iostream>
#include <vector>
using namespace std;

// Kiểm tra xem số lẻ từ 1 đến 9 nào chia hết số được viết
vector<int> findOddDivisors(long long n, int d) {
    vector<int> result;

    // Tính các số lẻ từ 1 đến 9
    vector<int> oddDigits = {1, 3, 5, 7, 9};

    // Tính n! chỉ để kiểm tra tính chia hết
    long long factorial = 1;
    for (long long i = 2; i <= n; i++) {
        factorial *= i;
        // Nếu factorial lớn hơn 9, ta chỉ cần kiểm tra modulo 9 vì chu kỳ chia hết lặp lại
        if (factorial > 9) {
            factorial %= 9;
        }
    }

    // Kiểm tra các số lẻ từ 1 đến 9
    for (int odd : oddDigits) {
        if (d % odd == 0 && factorial % odd == 0) {
            result.push_back(odd);
        }
    }

    return result;
}

int main() {
    int t;
    cin >> t; // Số lượng test case

    while (t--) {
        long long n;
        int d;
        cin >> n >> d;

        vector<int> divisors = findOddDivisors(n, d);
        for (int div : divisors) {
            cout << div << " ";
        }
        cout << endl;
    }

    return 0;
}
