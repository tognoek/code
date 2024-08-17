#include<bits/stdc++.h>
using namespace std;
const int N10e5 = 2 * 1e5 + 5;
long long Xpoints[N10e5];
long long Ypoints[N10e5];

long long max(long long x, long long y){
    return x > y? x : y;
}

long long min(long long x, long long y){
    return x < y? x : y;
}

bool compare(pair<long long, char> x, pair<long long, char> y){
    return x.first < y.first;
}

int main(){
    freopen("STORES.inp","r",stdin);
    freopen("STORES.out","w",stdout);  
    for (int i = 0; i < N10e5; i++){
        Xpoints[i] = -1;
        Ypoints[i] = -1;
    }
    vector<pair<long long, char>> myDatas;  
    int n, p;
    char store;
    long long sum, res;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> p >> store;
        myDatas.push_back(make_pair(p, store));
    }
    sort(myDatas.begin(), myDatas.end(), compare);
    sum = 0;
    res = 0;
    Ypoints[0] = -1;
    for (int i = 0; i < myDatas.size(); i++){
        if (myDatas[i].second == 'N'){
            sum += 1;
        }else{
            sum -= 1;
        }
        // cout << sum << endl;
        if (sum > 0){
            if (Xpoints[sum] == -1){
                Xpoints[sum] = i;
            }else{
                res = max(res, abs(myDatas[i].first - myDatas[Xpoints[sum] + 1].first));
            }
        }else{
            if (Ypoints[-sum] == -1 && sum < 0){
                Ypoints[-sum] = i;
            } else{
                res = max(res, abs(myDatas[i].first - myDatas[Ypoints[-sum] + 1].first));
            }
        }
    }
    cout << res;
    return 0;
}