#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// Hàm kiểm tra khả năng biến đổi
bool canTransform(const vector<int>& a, const vector<int>& b) {
    unordered_map<int, int> count_a, count_b;

    // Đếm tần suất các phần tử trong a và b
    for (int x : a) {
        count_a[x]++;
    }
    for (int x : b) {
        count_b[x]++;
    }

    // Kiểm tra khả năng kết hợp các số từ a thành b
    for (auto& p : count_b) {
        int target = p.first;
        int needed = p.second;

        if (count_a.find(target) == count_a.end()) {
            return false; // Nếu không tìm thấy số này trong a
        }

        int available = count_a[target];
        
        // Nếu số lượng trong a không đủ, kiểm tra xem có thể kết hợp với số liền kề không
        if (available < needed) {
            int diff = needed - available;
            if (count_a.find(target - 1) != count_a.end() && count_a[target - 1] >= diff) {
                count_a[target - 1] -= diff;
                available = needed;
            } else if (count_a.find(target + 1) != count_a.end() && count_a[target + 1] >= diff) {
                count_a[target + 1] -= diff;
                available = needed;
            } else {
                return false;
            }
        }
    }

    return true;
}

int main() {
    int t;
    cin >> t; // Đọc số lượng test case
    while (t--) {
        int n, m;
        cin >> n >> m; // Đọc n và m
        vector<int> a(n), b(m);
        
        for (int i = 0; i < n; i++) {
            cin >> a[i]; // Đọc dãy a
        }
        for (int i = 0; i < m; i++) {
            cin >> b[i]; // Đọc dãy b
        }

        // Kiểm tra và in kết quả
        if (canTransform(a, b)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
