#include<bits/stdc++.h>
using namespace std;

void openfile(){
    freopen("interval.inp", "r", stdin);
    freopen("interval.out", "w", stdout);
}
int count(long long n){
    long long res = 0;
    while (n > 0){
        res++;
        n = n / 10;
    }
    return res;
}

long long dem(long long n){
    long long r;
    r = 1;
    for (int i = 1; i <= n - 2; i++){
        r = r * 10;
    }
    return 9 * r;
}

long long slove(long long n){
    if (n < 10){
        return n;
    }
    long long res = 9;
    if (n < 100){
        res = res + n / 10;
        if (n / 10 > n % 10){
            res--;
        }
        return res;
    }else{
        res = res + 9;
    }

    int l = count(n);

    for (int i = 3; i < l; i++){
        res = res + dem(i);
    }
    // be hon 1 chu so

    long long dau;
    dau = n;
    while (dau >= 10){
        dau = dau / 10;
    }

    long long r = 1;
    for (int i = 1; i <= l - 2; i++){
        r = r * 10;
    }
    res = res + (dau - 1) * r;
    long long temp = n;
    temp = temp / 10;
    temp = temp % r + 1;
    res = res + temp * 1;


    long long cuoi;
    cuoi = n % 10;
    if (dau > cuoi){
        return res - 1;
    }else{
        return res;
    }
}

int main() {
    // openfile();
    long long L, R;
    cin>>L>>R;
    cout<<slove(R) - slove(L-1)<<endl;
    // cout<<count(123);
}
