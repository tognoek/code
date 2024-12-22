#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    long long x, y;
    cin >> n >> x >> y;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    long long total_sum = 0;
    for (long long num : a) {
        total_sum += num;
    }

    long long min_sum = total_sum - y;
    long long max_sum = total_sum - x;
    sort(a.begin(), a.end());

    long long result = 0;

    for (int i = 0; i < n; ++i) {
        long long low = min_sum - a[i];
        long long high = max_sum - a[i];
        auto lower = lower_bound(a.begin() + i + 1, a.end(), low);
        auto upper = upper_bound(a.begin() + i + 1, a.end(), high);
        result += (upper - lower);
    }

    cout << result;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        
        solve();
        cout << endl;
    }

    return 0;
}
