#include <bits/stdc++.h>
using namespace std;
const int Nmax = 5005;
const int nMod = 1000000007;
long long max(long long __xm, long long __ym)
{
    return __xm > __ym ? __xm : __ym;
}
long long min(long long __xm, long long __ym)
{
    return __xm < __ym ? __xm : __ym;
}

int Lamtron(double __xr)
{
    double k = (__xr - (int)(__xr));
    if (fabs(k) >= 0.5)
    {
        return __xr >= 0 ? (int)(__xr + 1) : (int)(__xr - 1);
    }
    else
        return (int)(__xr);
}

void swap(long long &__xs, long long &__ys)
{
    __xs = __xs + __ys;
    __ys = __xs - __ys;
    __xs = __xs - __ys;
}

long long Tonguoc(int __k)
{
    long long __s = 1;
    for (int __i = 2; __i <= int(sqrt(__k)); __i++)
    {
        if (__k % __i == 0)
        {

            __s = __s + __i;
            if (__i != __k / __i)
            {
                __s = __s + __k / __i;
            }
        }
    }
    return __s;
}

long long luythua(long long __k, int __x)
{
    long long __tmp;
    if (__x == 1){
        return __k % nMod;
    }
    else{
        __tmp = luythua(__k , __x / 2) % nMod;
        if (__x % 2 == 0){
            return __tmp * __tmp % nMod;
        } 
        else{
            return (__tmp * __tmp % nMod) * __k % nMod;
        }
    }
}

int main()
{
    int a[Nmax], b[Nmax];
    int n, l;
    cin>>n;
    for (int i = 1; i <= n; i++){
        cin>>a[i];
    }
    l = 0;
    sort(a + 1, a + n + 1);
    for (int i = n; i > 0; i--){
        for (int t = 1; t <= l; t++){
            b[t]--;
            if (b[t] < 0){
                cout<<l;
                return 0;
            }
        }
        l++;
        b[l] = a[i];
    }
    cout<<l;
    return 0;
}