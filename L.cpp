#include <bits/stdc++.h>

using namespace std;

vector<vector<pair<int, int>>> nies;

int max(int a, int b) {
    return a > b ? a : b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, v;
    cin >> n >> m >> v;
    int x, y, z;
    nies.resize(n+5);
    for (int i = 0; i < m; i++) {
        cin >> x >> y >> z;
        nies[x].push_back({y, z});
        nies[y].push_back({x, z});
    }
    int bg, ed;
    cin >> bg >> ed;
    vector<int> detime(n+5);
    for (int i = 1; i <= n; i++){
        detime[i] = max(0, nies[i].size() - 2);
    }
    detime[bg] = 0;
    detime[ed] = 0;
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
    vector<double> time_s(n+5, 1e18);
    time_s[bg] = 0.0;
    pq.push({0.0, bg});
    while (pq.empty() == false) {
        double time = pq.top().first;
        int p = pq.top().second;
        pq.pop();

        if (time > time_s[p]) {
            continue;
        }

        if (p == ed) {
            break;
        }

        for (auto& nie : nies[p]) {
            int p_nie = nie.first;
            int dis = nie.second;

            double time_run = (double)dis / v;
            double time_total = time_s[p] + time_run + detime[p_nie];
            if (time_total < time_s[p_nie]) {
                time_s[p_nie] = time_total;
                pq.push({time_total, p_nie});
            }
        }
    }

    cout << fixed << setprecision(6) << time_s[ed];
}