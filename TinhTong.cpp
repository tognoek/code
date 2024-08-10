#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("bai2.inp","r",stdin);
    freopen("bai2.out","w",stdout); 
    long long n, k, b;
    cin >> n >> k >> b;
    int a[n+10];
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    b = b % n;
    long long sum = 0;
    a[0] = a[n];
    for (int i = b; i < b + k; i++) {
        sum += a[i % n];
    }
    cout << sum;
}