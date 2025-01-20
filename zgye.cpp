#include <iostream>
#include <vector>

const int MOD = 998244353;

using namespace std;

int solve(const vector<int> &a, int n)
{
    vector<int> dp(n + 1, 0); // dp[i] là số cách hợp lệ khi xét đến học sinh thứ i
    dp[0] = 1;                // Cơ sở: không có học sinh nào là 1 cách hợp lệ

    // Duyệt qua từng học sinh từ 1 đến n
    for (int i = 1; i <= n; i++)
    {
        if (a[i - 1] == 0)
        {
            // Nếu học sinh thứ i nói có 0 liars bên trái, có 2 cách: honest hoặc liar
            dp[i] = (2 * dp[i - 1]) % MOD;
        }
        else
        {
            // Nếu học sinh thứ i báo có a[i-1] liars bên trái, kiểm tra hợp lệ
            if (i - a[i - 1] - 1 >= 0)
            {
                dp[i] = dp[i - a[i - 1] - 1];
            }
        }
    }

    return dp[n];
}

int main()
{
    int t;
    cin >> t; // Đọc số test case
    while (t--)
    {
        int n;
        cin >> n; // Đọc số học sinh trong test case
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i]; // Đọc số lượng kẻ nói dối mà mỗi học sinh nói
        }

        // In kết quả cho test case này
        cout << solve(a, n) << endl;
    }
    return 0;
}
