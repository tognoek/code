#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("SONTTQ.INP","r",stdin);
    freopen("SONTTQ.OUT","w",stdout); 
    string s;
    int n, c;
    int a[11];
    for (int i = 0; i < 11; i++){
        a[i] = 0;
    }
    cin>>s;
    cin>>n;
    vector<int> myVector;
    for (int i = 0; i < s.length(); i++){
        c = s[i] - '0';
        if (a[c] == 0){
            a[c] = 1;
            myVector.push_back(c);
        }
    }
    sort(myVector.begin(), myVector.end());
    if (myVector.size() < n){
        cout<<-1;
    }else{
        c = myVector.at(n-1);
        if (c == 2 || c == 3 || c == 5 || c == 7){ 
            cout<<c<<" "<<"Yes";
        }else{
            cout<<c<<" "<<"No";
        }
    }
}