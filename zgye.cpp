#include <bits/stdc++.h>
using namespace std;
const int nMax = 100005;
const int nMaxx2 = 1000005;
long long a[nMax];
long long f[nMaxx2];

int main()
{
    // freopen("PSEQ.inp","r",stdin);
    // freopen("PSEQ.out","w",stdout);
    int n;
    long long k;
    cin>>n>>k;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
    }
    long long dis;
    long long s = 0;
    long long res = 0;
    for (int i = 1; i <= n; i++){
        s = s + a[i];
        dis = s - k;
        res = res + 1;
    }
    return 0;
}