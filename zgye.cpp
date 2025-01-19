#include <iostream>
#include <vector>
#include <string>
using namespace std;

void solve() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;

        // Ma trận a, là ma trận gốc với các giá trị cho sẵn.
        vector<vector<long long>> a(n, vector<long long>(m));

        // Đọc ma trận gốc
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }

        // Khởi tạo ma trận b để chứa kết quả (altitudes restored)
        vector<vector<long long>> b = a;

        // Duyệt qua chuỗi s và điền giá trị vào ma trận b
        int x = 0, y = 0;
        b[x][y] = 0;  // Bắt đầu từ (1,1), giá trị này đã được set là 0

        // Đi qua các bước D (down) và R (right) trong chuỗi s
        for (char c : s) {
            if (c == 'D') {
                x++;
            } else if (c == 'R') {
                y++;
            }
            b[x][y] = 0;  // Các ô trên đường đi có giá trị là 0
        }

        // Khôi phục các giá trị ngoài đường đi
        // Sử dụng công thức khôi phục giá trị cho các ô còn lại
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (b[i][j] == 0) {
                    long long value = a[i][j];
                    // Tính giá trị cho ô này theo quy tắc bài toán
                    if (i > 0) value += b[i-1][j];  // Ô trên
                    if (j > 0) value += b[i][j-1];  // Ô trái
                    b[i][j] = value;
                }
            }
        }

        // In ma trận b ra kết quả
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << b[i][j] << " ";
            }
            cout << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    return 0;
}
