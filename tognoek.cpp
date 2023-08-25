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

void swap(long long &xs, long long &ys)
{
    xs = xs + ys;
    ys = xs - ys;
    xs = xs - ys;
}

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    cout << max(max(a, b), c);
}