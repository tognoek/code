#include <bits/stdc++.h>
using namespace std;
const int Nmax = 1000005;
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
    double a[Nmax];
    a[0] = 0;
    int s = 0;
    for (int i = 1; i < Nmax; i++){
        s += i;
        a[i] = a[i-1] + (1.0/s);
    }
    int t, x;
    cin>>t;
    for (int r= 1; r <= t; r++){
        cin>>x;
        printf("%.8f", a[x]);
        cout<<endl;
    }
    return 0;
}