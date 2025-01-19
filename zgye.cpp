#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    
    vector<int> x(n);
    unordered_map<int, int> count; // Đếm số lần xuất hiện của mỗi số

    // Đọc các số từ bảng đen
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
        count[x[i]]++;  // Tăng số lần xuất hiện của x[i]
    }

    int score = 0;
    
    // Bob muốn tạo ra càng nhiều cặp a, b sao cho a + b = k
    // Alice sẽ tìm cách ngăn cản Bob làm điều này.
    for (auto& pair : count) {
        int a = pair.first;
        int b = k - a;
        
        if (b < 1 || b > n) continue;  // Nếu b không hợp lệ thì bỏ qua

        // Nếu a và b khác nhau, ta chỉ có thể tạo tối đa min(count[a], count[b]) cặp
        if (a != b) {
            score += min(count[a], count[b]);
        } else {
            // Nếu a == b, ta chỉ có thể tạo tối đa count[a] / 2 cặp
            score += count[a] / 2;
        }
    }

    // In kết quả
    cout << score << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();  // Gọi hàm solve cho mỗi test case
    }

    return 0;
}
