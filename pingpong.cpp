#include <bits/stdc++.h>

using namespace std;

int r[30];
long long result;

void check(int n, int a, int b)
{
    int x, y;
    x = 0;
    y = 0;
    for (int e = 1; e < a + b + 1; e++)
    {
        if (r[e] == 0)
        {
            x += 1;
        }
        else
        {
            y += 1;
        }
    }
    if (x == a && y == b)
    {
        if (x >= n || y >= n)
        {
            result += 1;
        }
    }
}

void recursive(int n, int a, int b, int t)
{
    for (int i = 0; i < 2; i++)
    {
        r[t] = i;
        if (t == a + b)
        {
            check(n, a, b);
        }
        if (t < a + b)
        {
            recursive(n, a, b, t + 1);
        }
    }
}

void slove()
{
    int n, a, b;
    cin >> n >> a >> b;
    result = 0;
    if (abs(a - b) > 1)
    {
        recursive(n, a, b, 1);
    }
    cout << result << endl;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        slove();
    }
    return 0;
}