#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("LATXU.inp","r",stdin);
    freopen("LATXU.out","w",stdout);   
    long long n, x, value;
    pair<int , long long> temp, first, second;
    vector<pair<int, long long>> values;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> x;
        if (values.empty()){
            values.push_back(make_pair(x == 0 ? -1 : 1, 1));
        }else{
            first = values.back();
            value = x == 0 ? -1 : 1;
            if (i % 2 == 0){
                if (value == first.first){
                    values.pop_back();
                    values.push_back(make_pair(value, first.second + 1));
                }else{
                    values.push_back(make_pair(value, 1));
                }
            }else{
                if (value == first.first){
                    values.pop_back();
                    values.push_back(make_pair(value, first.second + 1));
                }else{
                    values.pop_back();
                    if (values.empty()){
                        values.push_back(make_pair(0 - first.first, first.second + 1));
                    }else{
                        second = values.back();
                        values.pop_back();
                        values.push_back(make_pair(second.first, first.second + second.second + 1));
                    }
                }
            }
        }
    }
    long long res = 0;
    for (auto i : values){
        if (i.first == -1){
            res = res + i.second;
        }
    }
    cout << res;
    return 0;
}
