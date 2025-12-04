#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m, 0));
    char r;
    int x, y;
    for (int i = 0; i < n; i++) {
        for (int t = 0; t < m; t++) {
            cin >> r;
            if (r == 'S') {
                x = i;
                y = t;
                a[i][t] = 99;
            }
            if (r == 'D') {
                a[i][t] = -99;
            }
            if (r == '-') {
                a[i][t] = 0;
            }
            if (r == '+') {
                a[i][t] = 1;
            }
        }
    }
    queue<tuple<int, int, int, int>> q;
    vector<vector<vector<bool>>> th(n, vector<vector<bool>>(m, vector<bool>(4, false)));

    q.push({x, y, 3, 0});
    th[x][y][3] = true;

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    int res = -1;

    while (!q.empty()) {
        auto [x, y, hp, time] = q.front();
        q.pop();

        if (a[x][y] == -99) {
            res = time;
            break;
        }

        for (int i = 0; i < 4; i++) {
            int nr = x + dr[i];
            int nc = y + dc[i];
            int new_time = time + 1;

            if (nr < 0 || nr >= n || nc < 0 || nc >= m) {
                continue;
            }

            int new_hp = hp;
            if (a[nr][nc] == 1) {
                new_hp--;
            }
            
            if (new_hp <= 0) {
                continue; 
            }

            if (!th[nr][nc][new_hp]) {
                th[nr][nc][new_hp] = true;
                q.push({nr, nc, new_hp, new_time});
            }
        }
    }
    cout << res;
}