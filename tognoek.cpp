#include <bits/stdc++.h>
using namespace std;
const int Nmax = 50005;
const int nMod = 1000000007;
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

long long luythua(long long k, int x)
{
    long long tmp;
    if (x == 1){
        return k % nMod;
    }
    else{
        tmp = luythua(k , x / 2) % nMod;
        if (x % 2 == 0){
            return tmp * tmp % nMod;
        } 
        else{
            return (tmp * tmp % nMod) * k % nMod;
        }
    }
}

int main()
{
    long long n, k;
    cin >> n >> k;
    cout<< luythua(n, k);
}