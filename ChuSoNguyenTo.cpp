#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("bai2.inp","r",stdin);
    freopen("bai2.out","w",stdout);    
    int a[11];
    for (int i = 0; i < 11; i++)
        a[i] = 0;
    a[2] = 1;
    a[3] = 1;
    a[5] = 1;
    a[7] = 1;
    string s;
    int n;
    cin>>s;
    for (int i = 0; i < s.length(); i++){
        int n = s[i] - '0';
        if (a[n] == 1){
            cout<<n<<" ";
            a[n] = 0;
        }
    }
}