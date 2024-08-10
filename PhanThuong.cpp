#include <bits/stdc++.h>
using namespace std;
int a[9] = {0, 2, 3, 5, 7, 11, 13, 17, 19};

long long slove(long long N, int K){
    if (K == 2){
        return N / K;
    }else{
        long long res = N / K;
        long long temp = 0;
        for (int i = 1; i < 9; i++){
            if (a[i] >= K){
                return res - temp;
            }else{
                temp = temp + slove(res, a[i]);
            }
        }
        return res;
    }
}

int main()
{
    freopen("bonus.inp","r",stdin);
    freopen("bonus.out","w",stdout);
    long long n;
    long long res;
    int k;
    cin >> n >> k;
    res = n;
    for (int i = 1; i <= 8; i++)
    {
        if (a[i] <= k){
            res = res - slove(n, a[i]);
        }else{
            break;
        }
    }
    cout<<res;
}