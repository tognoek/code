#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    uint64_t k;
    cin >> N >> M >> k;

    vector<vector<uint64_t>> matrix(N, vector<uint64_t>(M));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> matrix[i][j];

    uint64_t maxSum = 0;

    for (int left = 0; left < M; ++left) {
        vector<uint64_t> temp(N, 0);
        
        for (int right = left; right < M; ++right) {
            for (int i = 0; i < N; ++i) {
                temp[i] += matrix[i][right];
            }

            vector<uint64_t> modMap(k, INT64_MAX);
            modMap[0] = 0; 
            uint64_t currentSum = 0;

            for (int i = 0; i < N; ++i) {
                currentSum += temp[i];
                int mod = currentSum % k;

                if (modMap[mod] != INT64_MAX) {
                    maxSum = max(maxSum, currentSum - modMap[mod]);
                }
                
                modMap[mod] = min(modMap[mod], currentSum);
            }
        }
    }

    cout << maxSum << endl;
    return 0;
}
