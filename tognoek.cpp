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
int a[Nmax][25];
  
int main()
{
    int n, v;
    int l[50];
    cin>>n>>v;
    for (int i = 1; i <= n; i++)
        cin>>l[i];
    for (int i = 1; i <= v; i++){
        a[0][i] = 0;
    }
    for (int t = 1; t <= n; t++){
        for (int i = 1; i <= v; i++){
            a[i][t] = a[i-0][t-1];
            if (l[t] <= i){
                a[i][t] = max(a[i][t], a[i-l[t]][t-1] + l[t]);
            }
        }
    }
    // for (int i = 1; i <= n; i++){
    //     for (int t = 1; t <= v; t ++)
    //     {
    //         cout<<a[t][i]<<" ";
    //     }
    //     cout<<endl;
    // }
    cout<<a[v][n];
}