#include <bits/stdc++.h>
using namespace std;
const int Nmax = 50005;
long long max(long long xm, long long ym)
{
    return xm > ym ? xm : ym;
}
long long min(long long xm, long long ym)
{
    return xm < ym ? xm : ym;
}

int Lamtron(double xr)
{
    double k = (xr - (int)(xr));
    if (fabs(k) >= 0.5)
    {
        return xr >= 0 ? (int)(xr + 1) : (int)(xr - 1);
    }
    else
        return (int)(xr);
}

void swap(long long &xs, long long &ys)
{
    xs = xs + ys;
    ys = xs - ys;
    xs = xs - ys;
}

long long Tonguoc(int _k)
{
    long long s = 1;
    for (int _i = 2; _i <= int(sqrt(_k)); _i++)
    {
        if (_k % _i == 0)
        {

            s = s + _i;
            if (_i != _k / _i)
            {
                s = s + _k / _i;
            }
        }
    }
    return s;
}

int main()
{
    int a[Nmax], b[Nmax];
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int v;
    for (int i = 1; i <= n; i++)
    {
        v = i - k > 0 ? i - k : 0;
        b[i] = b[v] + a[i];
        for (int t = i - 1; t > v; t--){
            b[i] = max(b[i], b[t] + a[i]);
        }
    }
    int kq = b[n];
    for (int i = n - 1; i >= n - k; i--){
        kq = max(kq, b[i]);
    }
    cout<<kq;
}