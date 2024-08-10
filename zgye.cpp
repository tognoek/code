#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Hàm Manacher để tìm độ dài xâu đối xứng dài nhất
int manacher(const string &s) {
    int n = s.length();
    if (n == 0) return 0;

    // Chuẩn bị xâu đã chèn ký tự đặc biệt
    string t(2 * n + 1, '#');
    for (int i = 0; i < n; ++i) {
        t[2 * i + 1] = s[i];
    }

    int t_len = t.length();
    vector<int> p(t_len, 0);  // p[i] là bán kính của xâu đối xứng có tâm tại t[i]
    int center = 0, right = 0;  // center và right của xâu đối xứng lớn nhất hiện tại
    int max_len = 0;

    for (int i = 0; i < t_len; ++i) {
        int mirror = 2 * center - i;

        if (i < right) {
            p[i] = min(right - i, p[mirror]);
        }

        // Mở rộng xâu đối xứng
        while (i + p[i] + 1 < t_len && i - p[i] - 1 >= 0 && t[i + p[i] + 1] == t[i - p[i] - 1]) {
            ++p[i];
        }

        // Cập nhật center và right
        if (i + p[i] > right) {
            center = i;
            right = i + p[i];
            max_len = max(max_len, p[i]);
        }
    }

    return max_len;
}

int main() {
    
    freopen("xaudx.inp","r",stdin);
    freopen("xaudx.out","w",stdout); 
    string s;
    cin >> s;
    int longest_palindrome_length = manacher(s);
    cout << longest_palindrome_length << endl;
    return 0;
}
