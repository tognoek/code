#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("DICT.inp","r",stdin);
    freopen("DICT.out","w",stdout);    
    unordered_map<string, int> myMaps;
    int n;
    string key;
    int q;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> q >> key;
        if (q == 1){
            myMaps[key]++;
        }
        else{
            cout << myMaps[key] << endl;
        }
    }
}