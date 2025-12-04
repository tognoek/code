#include <bits/stdc++.h>

using namespace std;

vector<vector<pair<int, long long>>> nies;
vector<long long> save;

void lanTran(int d, int c, int bg) {
    save[d] = c;
     
    for (auto& nie: nies[d]) {
        if (nie.first != bg)
            lanTran(nie.first, c ^ nie.second, d);
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    nies.resize(n+5);
    save.resize(n+5);
    int x, y;
    long long z;
    long long res = 0;
    queue<tuple<int, int, long long>> q;
    for (int i = 1; i < n; i++) {
        cin >> x >> y >> z;
        q.push({x, y, z});
    }
    while (q.empty() == false) {
        auto [u, v, c] = q.front();
        q.pop();
        nies[u].push_back({v, c});
        nies[v].push_back({u, c});
    }

    lanTran(1, 0, -1);
    vector<long long> a(65, 0);
    for (int i = 0; i < 64; i++) {
        long long zore = 0, one = 0;
        for (int t = 1; t <= n; t++) {
            if ((save[t] >> i) & 1) {
                one++;
            } else {
                zore++;
            }
        }
        a[i] = one * zore;
    }
    long long re = 1;
    for (int i = 0; i < 64; i++) {
        res += re * a[i];
        re *= 2;
    }

    cout << res;
    
}