#include <bits/stdc++.h>

using namespace std;

long long slove(long long k, long long x){
    long long res = k * x;
    long long s = 0;
    long long u = x / 2 + x % 2;
    if (k % 2 == 1){
        long long v = u * 2 - 1;
        long long l = (v - 1) / 2 + 1;
        s = ((v + 1) * (l / 2)) + ((v + 1) * (l % 2)  / 2);
        s = s * 2;
        if (x % 2 == 1){
            s = s - v;
        }
        s = s + 2 * x;
    }else{
        long long v = u;
        long long l = (v - 1) + 1;
        s = ((1 + v) * (l / 2) + (1 + v) * (l % 2) / 2) * 2;
        s = s * 2;
        if (x % 2 == 0){
            s = s + (v + 1) * 2;
        }
        s = s - 2;
    }
    long long dev = (x + 1) * (x / 2) + (1 + x) * (x % 2) / 2;
    return (res - s) / 2 - dev;
}

int main(){
    freopen("BAI4.inp","r",stdin);
    freopen("BAI4.out","w",stdout); 
    long long n;
    cin>>n;
    long long x;
    x = n / 3 - 1;
    cout<<slove(n, x);
}