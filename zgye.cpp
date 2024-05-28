#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    cin>>n;
    if ((n <= 0) || (n > 100000)) cout<<"INVALID";
    else
    {
        if (((n % 4 == 0) && (n % 100 != 0)) || (n % 400 == 0))
            cout<<"YES";
        else
            cout<<"NO";
    }
}