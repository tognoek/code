#include <bits/stdc++.h>

#define endl "\n";
#define PI 3.14;

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
    if (___n % 2 == 1)
        return luyThua(___k * ___k, ___n / 2) * ___k;
    else
        return luyThua(___k * ___k, ___n / 2);
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
int soDoiXungDauDuoi(long long __k){
    int ___res;
    ___res = 0;
    if (__k < 10){
        return __k;
    }
    if (__k <= 100){
        int ___x, ___y;
        ___x = __k / 10;
        ___y = __k % 10;
        if (___x <= ___y){
            return ___x + 9;
        }
        else{
            return (___x - 1) + 9;
        }
    }
    
    return ___res;
}
long demUocDuog(long long __k){
    long long __n = abs(__k);
    int res = 0;
    for (int ___i = 1; ___i * ___i <= __n; ___i++){
        if (__n % ___i == 0){
            res++;
            if (__n / ___i !=  ___i)
                res++;
        }
    }
    return res;
}
short kiemTraNamNhuan(int __k){
    if ((__k <= 0) || (__k > 100000)) return -1;
    else
    {
        if (((__k % 4 == 0) && (__k % 100 != 0)) || (__k % 400 == 0))
            return 0;
        else
            return 1;
    }
}
long long toHopChapKcuaN(int n, int __k, vector<vector<long long>>& __memo) {
    // Nhớ tạo vecotr 2 chiều [n + 1, k + 1] phần tử giá trị -1
    if (__k == 0 || __k == n) {
        return 1;
    }
    if (__memo[n][__k] != -1) {
        return __memo[n][__k];
    }
    __memo[n][__k] = toHopChapKcuaN(n - 1, __k - 1, __memo) + toHopChapKcuaN(n - 1, __k, __memo);
    return __memo[n][__k];
}
void coutVip(double __k, int __n, bool __endl){
    cout<< fixed << setprecision(__n) << __k;
    if (__endl) cout<< endl else cout<<" ";
}
//tognoek end

// Khai báo biến toàn cục 
int a[N10e6];
short b[N10e6];
// tognoek

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 
 // tognoek
    long long a[12];
    for (int i = 1; i < 12; i ++){
        cin>>a[i];
    }
    bool chekc = false;
    for (int i = 1; i < 11; i++){
        if (a[i] == a[11]){
            cout<<i<<" ";
            chekc = true;
        }
    }
    if (!chekc) cout<<-1;
    
//tognoek
    return 0;
}