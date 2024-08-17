#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("SCORES.inp","r",stdin);
    freopen("SCORES.out","w",stdout);
    unordered_map<string, int> myMaps;
    int n;
    cin >> n;
    int x, y;
    string name;
    for (int i = 0; i < n; i++){
        cin >> x;
        if (x == 1){
            cin >> name >> y;
            myMaps[name] += y;
        }
        if (x == 2){
            cin >> name;
            myMaps[name] = 0;
        }
        if (x == 3){
            cin >> name;
            cout << myMaps[name] << endl;
        }
    }
    return 0;
}