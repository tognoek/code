#include <bits/stdc++.h>

using namespace std;
int a[10];
int main(){
    freopen("div3.inp","r",stdin);
    freopen("div3.out","w",stdout); 
    int n, x;
    cin>>n;
    long long res = 0;
    for (int i = 1; i <= n; i++){
        cin>>x;
        x = x % 3;
        if (x == 0){
            res = res + a[0];
        }else{
            res = res + a[3-x];
        }
        a[x]++;
    }
    cout<<res;
    return 0;
}