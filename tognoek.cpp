#include <bits/stdc++.h>
using namespace std;
const int Nmax = 15;
int a[Nmax], b[Nmax], c[Nmax], d[Nmax];
int binarySearch(int left, int right, int x)
{
    int middle;

    while (left <= right)
    {
        middle = (left + right) / 2;
        if (c[middle] == x)
            return middle;
        if (x > c[middle])
            left = middle + 1;
        else
            right = middle - 1;
    }
    return -1;
}

int main()
{
    int n, t, q, k;
    cin >> t;

    a[0] = -1;
    b[0] = 0;
    c[0] = 0;
    d[0] = 0;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++)
        {
            cin >> b[i];
            c[i] = b[i] * (a[i] - a[i - 1] - 1) + d[i - 1];
            d[i] = d[i - 1] + b[i];
        }
        for (int i = 1; i <= n; i++){
            cout<<c[i]<<endl;
        }
        cin >> q;
        for (int i = 1; i <= q; i++)
        {
            cin >> k;
            cout << binarySearch(1, n, k) << endl;
        }
    }

    return 0;
}