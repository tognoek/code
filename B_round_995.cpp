#include <bits/stdc++.h>

using namespace std;

void solve(){
    long long n, a, b, c;
    cin >> n >> a >> b >> c;
    long long s;
    s = a + b + c;
    long long result;
    result = (n / s) * 3;
    n = n % s;
    // cout << n << " " << result << " ";
    if (n > 0){
        n = n - a;
        result = result + 1;
    }
    if (n > 0){
        n = n - b;
        result = result + 1;
    }
    if (n > 0){
        n = n - c;
        result = result + 1;
    }
    cout << result;
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
