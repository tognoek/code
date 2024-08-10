#include<bits/stdc++.h>

using namespace std;

bool isPerfectSquare(unsigned long long x){
    unsigned long long y;
    y = sqrt(x);
    return (y*y == x);
}

bool isFibonaci(unsigned long long x){
    return isPerfectSquare(5*x*x + 4) || isPerfectSquare(5*x*x - 4);
}

int main() {
    unsigned long long x;
    int n;
    freopen("fibnum.inp","r",stdin);
    freopen("fibnum.out","w",stdout); 
    cin>>n;
    while(n--){
        cin>>x;
        if(isFibonaci(x)){
            cout<<"Yes\n";
        }
        else{
            cout<<"No\n";
        }
    }

}