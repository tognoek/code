#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    int a[m+5];
    for (int i = 1; i <= m; i++){
        cin >> a[i];
    }
    vector<int> q;
    int x;
    for (int i = 0; i < k; i++){
        cin >> x;
        q.push_back(x);
    }
    if (n - k > 1){
        for (int i = 1; i <= m; i++){
            cout<<0;
        }
        return;
    }
    if (n - k == 0){
        for (int i = 0; i < m; i++){
            cout<<1;
        }
        return;
    }
    for (int i = 0; i < m; i++){
        if (binary_search(q.begin(), q.end(), a[i+1])){
            cout<<0;
        }else{
            cout<<1;
        }
    }
}

int main(){
    int T;
    cin >> T;
    while (T--)    {
        solve();
        cout << endl;
    }
    return 0;
}
