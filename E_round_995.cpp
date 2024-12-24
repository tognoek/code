#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<pair<int, int>> customers(n);
        for (int i = 0; i < n; ++i) {
            cin >> customers[i].first; 
        }
        for (int i = 0; i < n; ++i) {
            cin >> customers[i].second; 
        }

        sort(customers.begin(), customers.end());

        vector<int> a, b;
        for (auto [ai, bi] : customers) {
            a.push_back(ai);
            b.push_back(bi);
        }

        vector<int> prices;
        for (int i = 0; i < n; ++i) {
            prices.push_back(a[i]);
            prices.push_back(b[i]);
        }

        sort(prices.begin(), prices.end());
        prices.erase(unique(prices.begin(), prices.end()), prices.end());

        long long max_profit = 0;

        for (int price : prices) {
            int idx = lower_bound(a.begin(), a.end(), price) - a.begin();

            long long profit = 0;
            int positive_reviews = n - idx; 
            profit += positive_reviews * price;

            int negative_reviews = 0;

            vector<int> remaining_b(b.begin(), b.begin() + idx);
            sort(remaining_b.begin(), remaining_b.end());

            int position = lower_bound(remaining_b.begin(), remaining_b.end(), price) - remaining_b.begin();

            int num_negative_reviews = remaining_b.size() - position;
            if (num_negative_reviews <= k) {
                profit += num_negative_reviews * price;
                max_profit = max(max_profit, profit);
            } 
        }

        cout << max_profit << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
