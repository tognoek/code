#include <bits/stdc++.h>
using namespace std;
//tognoek begin
const int Nmax = 5005;
const int nMod = 1000000007;
const int N10e6 = 1000005;
short ArrSangNgto[N10e6];
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
        return __xr >= 0 ? (int)(__xr + 1) : (int)(__xr - 1);
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
        if (__k % __i == 0){
            __s = __s + __i;
            if (__i != __k / __i)
                __s = __s + __k / __i;
        }
    return __s;
}

long long luythua(long long __k, int __x)
{
    long long __tmp;
    if (__x == 1)
        return __k % nMod;
    else{
        __tmp = luythua(__k , __x / 2) % nMod;
        if (__x % 2 == 0)
            return __tmp * __tmp % nMod;
        else
            return (__tmp * __tmp % nMod) * __k % nMod;
    }
}

void sangNgto(){
    ArrSangNgto[0] = 1;
    ArrSangNgto[1] = 1;
    for (int __i = 2; __i * __i <= N10e6; __i++)
        if (ArrSangNgto[__i] == 0)
            for (int __t = __i * __i; __t <= N10e6; __t += __i)
                ArrSangNgto[__t] = 1;
}

int Binary_search(int ___Arr[], int ___lenArr, int ___target){
    int ___dot, ___dotLeft, ___dotRight;
    ___dotLeft = 1;
    ___dotRight = ___lenArr;
    ___dot = (___dotRight + ___dotLeft) / 2;
    while (___dot >= ___dotLeft && ___dot <= ___dotRight){
        if (___Arr[___dot] == ___target)
            return ___dot;
        if (___Arr[___dot] > ___target)
            ___dotRight = ___dot - 1;
        else
            ___dotLeft = ___dot + 1;
        ___dot = (___dotRight + ___dotLeft) / 2;
    }    
    return ___target != 0 ? 0 : -1;
}
long long luyThua(int ___k, int ___n){
    if (___n == 1)
        return ___k;
    int ___tmp;
    ___tmp = ___n / 2;
    if (___n % 2 == 1)
        return luyThua(___k * ___k, ___tmp) * ___k;
    else
        return luyThua(___k * ___k, ___tmp);
}
short lenInt(long long ___k){
    int ___res;
    ___res = 0;
    while ( ___k > 0){
        ___res++;
        ___k = ___k / 10;
    }
    return ___res;
}
short getCharInt(long long ___k, int ___index){
    ___index = lenInt(___k) - ___index + 1;
    while (___index-- > 1)
        ___k = ___k / 10;
    return ___k % 10;
}
int soDoiXungDauDuoi(long long k){
    int res;
    res = 0;
    if (k < 10){
        return k;
    }
    if (k <= 100){
        int x, y;
        x = k / 10;
        y = k % 10;
        if (x <= y){
            return x + 9;
        }
        else{
            return (x - 1) + 9;
        }
    }
    int len = lenInt(k);
    
    return res;
}
//tognoek end

// Khai báo biến toàn cục 
int a[N10e6];
short b[N10e6];
// tognoek

int main()
{
    int n;
    long long res;
    cin>>n;
    res = 1;
    for (int i = 2; i <= n; i++)
        res = res * i;
    cout<<res;
}