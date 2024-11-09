#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MAXN = 16; 
int R, C, N;
vector<string> island;
vector<pair<int, int>> shrines; 
int dist[MAXN][MAXN]; 
int dp[1 << MAXN][MAXN]; 

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void bfs(int start) {
    int sx = shrines[start].first;
    int sy = shrines[start].second;
    queue<pair<int, int>> q;
    vector<vector<int>> d(R, vector<int>(C, INF));
    q.push({sx, sy});
    d[sx][sy] = 0;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < R && ny >= 0 && ny < C && island[nx][ny] != '#' && d[nx][ny] == INF) {
                d[nx][ny] = d[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    for (int i = 0; i < shrines.size(); ++i) {
        int tx = shrines[i].first;
        int ty = shrines[i].second;
        dist[start][i] = d[tx][ty];
    }
}

int main() {
    cin >> R >> C >> N;
    island.resize(R);
    for (int i = 0; i < R; ++i) {
        cin >> island[i];
    }

    shrines.push_back({0, 0}); 
    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            if (island[r][c] == 'S') {
                shrines.push_back({r, c});
            }
        }
    }

    int M = shrines.size(); 

    for (int i = 0; i < M; ++i) {
        bfs(i);
    }

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < M; ++j) {
            if (dist[i][j] == INF) {
                cout << -1 << endl;
                return 0;
            }
        }
    }

    for (int mask = 0; mask < (1 << M); ++mask) {
        fill(dp[mask], dp[mask] + M, INF);
    }
    dp[1][0] = 0; 

    for (int mask = 1; mask < (1 << M); ++mask) {
        for (int u = 0; u < M; ++u) {
            if (mask & (1 << u)) {
                for (int v = 0; v < M; ++v) {
                    if (!(mask & (1 << v))) {
                        int new_mask = mask | (1 << v);
                        dp[new_mask][v] = min(dp[new_mask][v], dp[mask][u] + dist[u][v]);
                    }
                }
            }
        }
    }

    int result = INF;
    for (int i = 0; i < M; ++i) {
        result = min(result, dp[(1 << M) - 1][i]);
    }

    cout << (result < INF ? result : -1) << endl;
    return 0;
}
