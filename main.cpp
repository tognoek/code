#include<bits/stdc++.h>
using namespace std;
const int Nmax = 105;
long long max(long long xm, long long ym){
    return xm > ym ? xm : ym;
}
long long min(long long xm, long long ym){
    return xm < ym ? xm : ym;
}

int a[Nmax], l[5], v[5];

int main(){
    int t, n, k, x;
    cin>>t;
    while (t--){
        x = 0;
        cin>>n;
        for (int i = 1; i <= 101; i++){
            a[i] = 0;
        }
        for (int i = 1; i <= n; i++){
            cin>>k;
            if (a[k] == 0){
                x++;
                l[x] = k;
                v[x] = i;
            }
            a[k]++;
        }
        if (a[l[1]] == 1){
            cout<<v[1];
        }
        else{
            cout<<v[2];
        }
        cout<<endl;
    }
    return 0;
}