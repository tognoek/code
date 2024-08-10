#include<bits/stdc++.h>
using namespace std;

int a[1000006];

bool check(int a){
    int r = 0;
    for (int i = 1; i <= sqrt(a); ++i){
        if (a % i == 0){
            if (i * i == a) r++;
            else r += 2;
        }
        if (r > 9){
            return false;
        }
    }
    if (r == 9){
        return true;
    }else{
        return false;
    }
}

int main(){
    for (int i = 1; i < 1000005; i ++){
        if (i % 3 == 0){
            if (check(i)){
                // cout<<i<<endl;
                a[i] = a[i-1]+1;
            }else{
                a[i] = a[i-1];
            }
        }else{
            a[i] = a[i-1];
        }
    }
    freopen("sdb.inp","r",stdin);
    freopen("sdb.out","w",stdout);   
    int n;
    int u, v;
    cin >> n;
    while (n--){
        cin >> u >> v;
        cout << a[v] - a[u-1] << "\n";
    }
}