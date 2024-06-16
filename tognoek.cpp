#include <bits/stdc++.h>

#define endl "\n";
#define PI 3.14;

using namespace std;
//tognoek begin
const int Nmax = 5005;
const int nMod = 1000000007;
const int N10e6 = 1000005;
const int N10e5 = 100005;
const int N10e4 = 100005;
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
int soLuongDoiXungDauDuoi(long long __k){
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

bool kiemTraDoiXuong(long long ___k){
    if (___k < 0) {
        return false;
    }

    int __original = ___k;
    int __reversed = 0;

    while (___k != 0) {
        int __digit = ___k % 10;
        __reversed = __reversed * 10 + __digit;
        ___k /= 10;
    }

    return __original == __reversed;
}

bool kiemTraNguyenToCungNhau(long long ___x, long long ___y){
    for (int ___i = 2; ___i * ___i <= ___x; ___i++){
        if (___x % ___i == 0){
            if (___y % ___i == 0){
                return false;
            }
            if (___y % (___x / ___i) == 0){
                return false;
            }
        }
    }
    return true;
}

long long power_mod(long long ___a, long long ___b, long long ___M) // Tính ___a^___b % ___M.
{
      if (___b == 0)
           return 1;
      if (___b == 1)
           return ___a;

      long long half = power_mod(___a, ___b / 2, ___M) % ___M;

      if (___b % 2 == 0)
           return (half * half) % ___M;
      else 
           return (((half * half) % ___M) * ___a) % ___M;
}

long long modulo_inverse(int ___a, int ___M)
{
      return power_mod(___a, ___M - 2, ___M);
}

long long modulo_divide(long long ____a, long long ____b, long long ____c)
{
      long long inverse = modulo_inverse(____b, ____c);
      return (____a % ____c * inverse) % ____c;
}

long long binomial_coefficient_mod(long long ___n, long long ___k, long long ___M) {
    if (___k > ___n)
        return 0;
    if (___k == 0 || ___k == ___n)
        return 1;

    vector<long long> fact(___n + 1, 1);
    for (int __i = 2; __i <= ___n; ++__i) {
        fact[__i] = (fact[__i - 1] * __i) % ___M;
    }

    long long numerator = fact[___n];
    long long denominator = (fact[___k] * fact[___n - ___k]) % ___M;

    return (numerator * modulo_inverse(denominator, ___M)) % ___M;
}

//tognoek end

// Khai báo biến toàn cục 
int a[N10e6];
long long a_long[N10e6];
short b[N10e6];
// tognoek

// slove
void slove(long long a){

    int res;
    res = 0;
    while (a > 0){
        res = res + a % 2;
        a = a / 2;
    }
    if (res % 2 == 0){
        cout<<"even";
    }
    else{
        cout<<"odd";
    }


}
// tognoek

int main()
{
    bool tognoek;
    tognoek = true;
    // Đọc file
    if (tognoek){
        freopen("Parity.inp","r",stdin);
        freopen("Parity.out","w",stdout);    
    }

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 
 // tognoek
    
    int T;
    long long x;
    cin>>T;
    while (T--) {
        cin>>x;
        slove(x);
        cout<<endl;        
    }
    

//tognoek
    return 0;
}