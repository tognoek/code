#include <bits/stdc++.h>
using namespace std;
const int Nmax = 105;
long long max(long long xm, long long ym)
{
    return xm > ym ? xm : ym;
}
long long min(long long xm, long long ym)
{
    return xm < ym ? xm : ym;
}

long long round(float xr)
{
    // do chinh xac khong ca
    return (long long)(xr + 0.5);
}

int main()
{
    int n, m, q;
    long long l, s, k;
    cin >> q;
    while (q--)
    {
        cin >> n >> s;
        m = round(n / 2.0);
        l = n - m + 1;
        k = s / l;
        cout << k << endl;
    }
}