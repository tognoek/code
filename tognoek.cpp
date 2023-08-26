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

int Lamtron(double xr)
{   
    double k = (xr - (int)(xr));
    if (fabs(k) >= 0.5){
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

int main()
{
    double a;
    cin>>a;
    cout<<Lamtron(a);
}