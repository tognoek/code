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
    long long n;
    int l;
    int x[Nmax];
    int y[Nmax];
    cin >> n;
    int s;
    s = 0;
    l = 0;
    for (int i = 2; i <= 1000000; i++)
    {
        while (n % i == 0)
        {
            s = s + 1;
            n = n / i;
        }
        if (s > 0)
        {
            l++;
            x[l] = i;
            y[l] = s;
            s = 0;
        }
    }
    int h;
    h = l;
    if (n > 1)
    {
        h++;
    }
    cout<<h<<endl;
    for (int i = 1; i <=l; i++){
        cout<<x[i]<<" "<<y[i]<<endl;
    }
    if (n > 1){
        cout<<n<<" "<<1;
    }
}