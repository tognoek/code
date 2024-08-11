// Đây là bài làm theo đề tính n^n mod a == 0

#include<bits/stdc++.h>

using namespace std;

long long max(long long x, long long y){
    if (x > y)
        return x;
    return y;
}

int main(){
    freopen("power.INP","r",stdin);
    freopen("power.OUT","w",stdout); 
    long long n;
    long long count, value, max_count, res;
    cin >> n;
    value = 1;
    max_count = 0;
    for (int i = 2; i <= sqrt(n); i++){
        count = 0;
        while (n % i == 0){
            count = count + 1;
            n = n / i;
        }
        if (count > 0){
            value = value * i;
            max_count = max(max_count, count);
        }
    }
    if (n > 1){
        value = value * n;
        max_count = max(max_count, 1);
    }
    res = value;
    while (res < max_count){
        res = res + value;
    }
    cout<<res;
}