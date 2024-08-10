#include <bits/stdc++.h>

using namespace std;
int modInverse(long long a, long long m) {
    long long m0 = m, t, q;
    long long x0 = 0, x1 = 1;
    
    if (m == 1) return 0;
    
    while (a > 1) {
        q = a / m;
        t = m;
        m = a % m;
        a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    
    if (x1 < 0) x1 += m0;
    
    return x1;
}

long long sumOfSquaresMod(long long n, long long m) {
    long long a = n % m;
    long long b = (n + 1) % m;
    long long c = (2 * n + 1) % m;
    long long product = (a * b) % m;
    product = (product * c) % m;
    long long inv_6 = modInverse(6, m);
    long long result = (product * inv_6) % m;
    return (int)result;
}

int main(){
    freopen("sqroot.inp","r",stdin);
    freopen("sqroot.out","w",stdout); 
    long long n;
    cin >> n;
    cout<<sumOfSquaresMod(n, 2021);
    return 0;
}