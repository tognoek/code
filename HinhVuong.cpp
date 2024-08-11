#include<bits/stdc++.h>

using namespace std;

long long max(long long x, long long y){
    if (x > y)
        return x;
    return y;
}
long long min(long long x, long long y){
    if (x < y)
        return x;
    return y;
}
int main(){
    freopen("square.inp","r",stdin);
    freopen("square.out","w",stdout); 
    int n;
    int x, y, mix, miy, mxx, mxy, res;
    cin >> n;
    mix = 1000;
    miy = 1000;
    mxx = -10;
    mxy = -10;
    for (int i = 1; i <= n; i++){
        cin>>x>>y;
        mix = min(mix, x);
        miy = min(miy, y);
        mxx = max(mxx, x);
        mxy = max(mxy, y);
    }
    res = mxx - mix;
    res = max(res, mxy - miy);
    if (res == 0){
        res = 1;
    }
    cout << res * res;
    return 0;
} 