#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    int a[n+5], b[n+5];
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++){
        cin >> b[i];
    }
    long long result = 0;
    for (int i = 1; i < n; i++){
        if (a[i] - b[i+1] > 0){
            result = result + a[i] - b[i+1];
        }
    }
    cout << result + a[n];
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
