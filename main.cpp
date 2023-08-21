#include<bits/stdc++.h>
using namespace std;
const int Nmax = 1000005;
long long max(long long xm, long long ym){
    return xm > ym ? xm : ym;
}

int main(){
    int q, n, k, h;
    long long kq, x, y, a;
    cin>>q;
    // q = 1;
    // long long kk[q+9];
    int l = 0;
    while(q--){
        cin>>n;
        kq = 0;
        cin>>a;
        k = a < 0 ? -1 : 1;
        h = k;
        x = a;
        y = a;
        for (int i = 2; i <= n; i++){
            cin>>a;
            h = a < 0 ? -1 : 1;
            x = a;
            if (h * k < 0){
                kq += y;
                y = x;
            } 
            else{
                y = max(y, x);
            }
            k = h;
        }
        if (h * k > 0){
            kq += y;
        }
        l++;
        cout<<kq<<endl;
        // kk[l] = kq;
    }
    // for (int i = 1; i <= l; i++)
    //     cout<<kk[i]<<endl;
}