#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    
    vector<long long> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    sort(b.begin(), b.end()); 

    long long min_diff = LLONG_MAX;
    for (int i = 0; i < m; i++) {
        min_diff = min(min_diff, b[i] - a[0]);
    }
    if (min_diff < a[0]) a[0] = min_diff;

    for (int i = 1; i < n; i++) {
        if (a[i] >= a[i - 1]) {
            int t = lower_bound(b.begin(), b.end(), a[i] + a[i-1]) - b.begin();
            if (t != b.size()){
                a[i] = min(a[i], b[t] - a[i]);
            }
        } else {
            int t = lower_bound(b.begin(), b.end(), a[i] + a[i-1]) - b.begin();
            if (t != b.size()){
                a[i] = b[t] - a[i];
            }else{
                cout << "NO\n";
                return;
            }
        }
    }

    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
