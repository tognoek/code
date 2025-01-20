#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

void solve() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        unordered_map<int, int> freq;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            freq[a[i]]++;
        }

        vector<int> candidates;
        for (auto &[key, value] : freq) {
            if (value >= 2) {
                candidates.push_back(key);
            }
        }

        if (candidates.size() < 2) {
            cout << "-1\n";
            continue;
        }

        sort(candidates.begin(), candidates.end());
        pair<int, int> best_pair = {-1, -1};
        double min_ratio = 1e9;

        for (int i = 1; i < candidates.size(); i++) {
            double ratio = (double)candidates[i] / candidates[i - 1];
            if (ratio < min_ratio) {
                min_ratio = ratio;
                best_pair = {candidates[i - 1], candidates[i]};
            }
        }

        int x = best_pair.first;
        int y = best_pair.second;
        if (freq[x] >= 4) {
            cout << x << " " << x << " " << x << " " << x << "\n";
        } else if (freq[y] >= 4) {
            cout << y << " " << y << " " << y << " " << y << "\n";
        } else {
            cout << x << " " << x << " " << y << " " << y << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
