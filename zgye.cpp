#include<bits/stdc++.h>

using namespace std;

int a[5];

long long trand(long long r, long long e){
    long long tmp;
    tmp = e / 2;
    if (r > tmp){
        return e - r + 1;
    }
    else{
        return r;
    }
}
long long min(long long a, long long b){
    return a > b ? b : a;
}

int solve(long long u, long long v, long long m){
    u = trand(u, m);
    v = trand(v, m);
    long long tg;
    if (m % 2 == 1){
        if (u == m % 2 + 1){
            return v % 3;
        }
        if (v == m % 2 + 1){
            return u % 3;
        }
        tg = min(u, v);
        return tg % 3;
    }
    else{
        tg = min(u, v);
        return tg % 3;
    }
}

int main(){
    long long n, x, y;
    int k;
    a[0] = 3;
    a[1] = 1;
    a[2] = 2;
    a[3] = 3;
    cin>>n;
    cin>>k;
    while (k--){
        cin>>x>>y;
        cout<<a[solve(x, y, n)]<<endl;
    }
}