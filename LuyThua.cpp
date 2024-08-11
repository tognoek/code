// Nếu có ai xem code này thì xin cảm ơn. Bài này đọc nhầm đề nên làm tính ra n! mà n nhỏ nhất chia hết a

#include<bits/stdc++.h>

using namespace std;
int a[100005];

long long max(long long x, long long y){
    if (x > y)
        return x;
    return y;
}

int main(){
    // freopen("power.INP","r",stdin);
    // freopen("power.OUT","w",stdout); 
    long long n;
    long long count, res, temp, tenp;
    res = 0;
    cin >> n;
    tenp = n;
    for (int i = 2; i <= sqrt(n); i++){
        count = 0;
        while (n % i == 0){
            count = count + 1;
            n = n / i;
        }
        a[i] = count;
        if (count > 0){
            cout<<i<<" "<<count<<endl;
        }
    }
    if (n > 1){
        cout<<n<<endl;
        res = n;
    }
    for (int i = 2; i < 1e6; i++){
        temp = i;
        for (int t = 2; t <= sqrt(i); t++){
            count = 0;
            while (temp % t == 0){
                count = count + 1;
                temp = temp / t;
            }
            a[t] = a[t] - count;
            if (a[t] < 0){
                a[t] = 0;
            }
        }
        if (temp > 0){
            a[temp] -= 1;
        }
        int check = 0;
        for (int r = 2; r <= sqrt(tenp); r++){
            if (a[r] > 0){
                check = 1;
            }
        }
        if (check == 0){
            cout << max(res, i);
            return 0;
        }
    }
}