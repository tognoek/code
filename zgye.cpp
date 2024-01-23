#include<bits/stdc++.h>

using namespace std;

int solve(string a, string b){
    int len, lenB;
    int resSolve;
    resSolve = 0;
    lenB = b.length();
    b = b + b;
    len = a.length();
    for (int i = 0; i < lenB; i++){
        string tmp = "";
        for (int t = i; t < i + len; t++){
            tmp = tmp + b[t];
        }
        if (tmp == a){
            resSolve++;
        }
    }
    return resSolve > 0 ? 1 : 0;
}

int main(){
    int n;
    string s, x;
    int res;
    res = 0;
    cin>>s;
    cin>>n;
    while (n--){
        cin>>x;
        res = res + solve(s, x);
    }
    cout<<res;
}