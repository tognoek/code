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
    int q, n;
    long long a, h, x, y, s, u, v;
    cin >> q;
    while (q--)
    {
        /* code */
        cin >> n >> h;
        cin >> x;
        cin >> y;
        if (x < y)
        {
            swap(x, y);
        }
        for (int i = 3; i <= n; i++)
        {
            cin >> a;
            if (a >= x)
            {
                y = x;
                x = a;
            }
            else
            {
                if (a > y)
                {
                    y = a;
                }
            }
        }
        s = x + y;
        u = h - (int)(h / s) * s;
        if (x >= u && u > 0)
        {
            v = (h / s) * 2 + 1;
        }
        if (x < u && u > 0)
        {
            v = (h / s) * 2 + 2;
        }
        if (u <= 0)
        {
            v = (h / s) * 2;
        }
        cout << v << endl;
    }
}