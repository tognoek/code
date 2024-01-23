#include<bits/stdc++.h>

using namespace std;

int main(){

    int a, b, c, d;
    int s, m;
    cin>>a>>b>>c>>d;
    s = a + b + c + d;
    m = s / 60;
    s = s - (m * 60);
    cout<<m<<endl<<s;
    return 0;
}