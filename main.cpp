#include<bits/stdc++.h>
using namespace std;
const int Nmax = 105;
long long max(long long xm, long long ym){
    return xm > ym ? xm : ym;
}
long long min(long long xm, long long ym){
    return xm < ym ? xm : ym;
}

int main(){
    int t, n, k;
    int a[Nmax];
    cin>>t;
    while (t--){
        cin>>n;
        for (int i = 1; i <= n; i++){
            cin>>a[i];
        }
        sort(a + 1, a + n + 1);
        k = 1;
        for (int i = 2; i <= n; i++){
            if (a[i] - a[i-1] > 1){
                k = -1;
                break;
            }
        }
        if (k > 0){
            cout<<"YES";
        }
        else{
            cout<<"NO";
        }
        cout<<endl;
    }
    return 0;
}