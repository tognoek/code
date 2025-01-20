#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Hàm DFS để tìm thành phần liên thông
void dfs(int node, const vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited);
        }
    }
}

void solve() {
    int n, m1, m2;
    cin >> n >> m1 >> m2;

    vector<vector<int>> F(n + 1), G(n + 1);

    // Đọc đồ thị F
    for (int i = 0; i < m1; ++i) {
        int u, v;
        cin >> u >> v;
        F[u].push_back(v);
        F[v].push_back(u);
    }

    // Đọc đồ thị G
    for (int i = 0; i < m2; ++i) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    // Tìm số lượng thành phần liên thông trong F
    vector<bool> visitedF(n + 1, false);
    int componentsF = 0;
    for (int i = 1; i <= n; ++i) {
        if (!visitedF[i]) {
            dfs(i, F, visitedF);
            componentsF++;
        }
    }

    // Tìm số lượng thành phần liên thông trong G
    vector<bool> visitedG(n + 1, false);
    int componentsG = 0;
    for (int i = 1; i <= n; ++i) {
        if (!visitedG[i]) {
            dfs(i, G, visitedG);
            componentsG++;
        }
    }

    // Kết quả: số phép toán tối thiểu
    cout << abs(componentsF - componentsG) + (componentsG > 1 ? componentsG - 1 : 0) << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
