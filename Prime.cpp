#include<bits/stdc++.h>
using namespace std;
const int N10e6 = 1000005;
const long long N10e12 = 1e12 + 5;
int ArrSangNgto[1000005];
void sangNgto(){
    ArrSangNgto[0] = 1;
    ArrSangNgto[1] = 1;
    for (int __i = 2; __i * __i <= N10e6; __i++)
        if (ArrSangNgto[__i] == 0)
            for (int __t = __i * __i; __t <= N10e6; __t += __i)
                ArrSangNgto[__t] = 1;
}
int main(){
    freopen("cprime.inp","r",stdin);
    freopen("cprime.out","w",stdout);    
    long long powerValues;
    vector<long long> myVector;
    vector<long long> values;
    sangNgto();
    for (int i = 1; i < N10e6; i++){
        if (ArrSangNgto[i] == 0)
            myVector.push_back(i);
    }
    for (int i = 0; i < myVector.size(); i++){
        powerValues = 1;
        for (int t = 1; t < 50; t++){
            powerValues *= myVector[i];
            if (powerValues < N10e12){
                if (t > 1 && ArrSangNgto[t+1] == 0){
                    values.push_back(powerValues);
                }
            }else{
                break;
            }
        }
    }
    sort(values.begin(), values.end());
    // for (int i = 0; i < values.size(); i++){
    //     if (values.at(i) < 101){
    //         cout << values.at(i) << " ";
    //     }
    // }
    // cout<<endl;
    int n;
    long long a, b;
    int begin, end;
    cin >> n;
    while (n--){
        cin >> a >> b;
        begin = lower_bound(values.begin(), values.end(), a) - values.begin();
        end = upper_bound(values.begin(), values.end(), b) - values.begin();
        cout << end - begin << endl;
    }
}