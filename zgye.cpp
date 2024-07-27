#include <bits/stdc++.h>
using namespace std;
const int nMax = 100005;
long long a[nMax];

int main()
{
    freopen("PSEQ.inp","r",stdin);
    freopen("PSEQ.out","w",stdout);
    int n;
    long long k;
    cin>>n>>k;
    unordered_map<long long, int> myUnorderedMap;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
    }
    long long dis;
    long long s = 0;
    long long res = 0;
    myUnorderedMap[0] = 1;
    for (int i = 1; i <= n; i++){
        s = s + a[i];
        dis = s - k;
        if (myUnorderedMap.find(dis)!= myUnorderedMap.end()){
            res = res + myUnorderedMap[dis];
        }
        if (myUnorderedMap.find(s) != myUnorderedMap.end()){
            myUnorderedMap[s]++;
        }else{
            myUnorderedMap[s] = 1;
        }
    }
    cout<<res;
    return 0;
}