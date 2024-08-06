#include <bits/stdc++.h>
using namespace std;
string findNumber(int N) {
    queue<string> q;
    unordered_set<int> visited;

    // Khởi tạo hàng đợi với các số ban đầu là "2", "7", và "0"
    q.push("2");
    q.push("7");

    while (!q.empty()) {
        string current = q.front();
        q.pop();

        // Chuyển đổi số hiện tại thành số nguyên để kiểm tra chia hết
        long long num = stoll(current);
        
        // Kiểm tra xem số hiện tại có chia hết cho N không
        if (num % N == 0) {
            return current;
        }

        // Nếu chiều dài hiện tại của số chưa đạt tới 20, thêm các chữ số tiếp theo
        if (current.length() < 20) {
            // Tạo số mới bằng cách thêm chữ số "0", "2", "7" vào số hiện tại
            q.push(current + "0");
            q.push(current + "2");
            q.push(current + "7");
        }
    }

    return "-1"; // Không tìm thấy số nào thỏa mãn
}

int main() {
    int N;
    freopen("bhk.inp","r",stdin);
    freopen("BHK.out","w",stdout);  
    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    // Bài toán yêu cầu với mỗi số N thì tìm ra một số S mà số đó chia hết N và chỉ chứa các số[2, 7, 0]
    while (cin >> N){
        string result = findNumber(N);
        cout <<result << endl;
    }
    // Bài này có O(3 mũ 20) nhưng mà đã pass trên web, sử dụng BFS đề tìm ra tất cả các trường hợp tạo thành.
    return 0;
}
