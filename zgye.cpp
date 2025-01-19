#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isValid(vector<vector<int>>& cards, vector<int>& order, int n, int m) {
    int topCard = -1; 
    vector<int> indices(n, 0);

    for (int round = 0; round < m; ++round) {
        for (int i = 0; i < n; ++i) {
            int cow = order[i];
            while (indices[cow] < m && cards[cow][indices[cow]] <= topCard) {
                indices[cow]++;
            }

            if (indices[cow] == m) {
                return false;
            }

            topCard = cards[cow][indices[cow]];
            indices[cow]++;
        }
    }

    return true;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> cards(n, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> cards[i][j];
            }
            sort(cards[i].begin(), cards[i].end()); 
        }

        vector<int> order(n);
        for (int i = 0; i < n; ++i) {
            order[i] = i;
        }

        bool found = false;
        do {
            if (isValid(cards, order, n, m)) {
                found = true;
                break;
            }
        } while (next_permutation(order.begin(), order.end()));

        if (found) {
            for (int i = 0; i < n; ++i) {
                cout << order[i] + 1 << " ";
            }
            cout << endl;
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}
