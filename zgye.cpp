#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

struct ArrayData {
    ll total; 
    ll score;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<ArrayData> arr(n);
        
        for (int i = 0; i < n; i++){
            ll total = 0, score = 0, prefix = 0;
            for (int j = 0; j < m; j++){
                int x;
                cin >> x;
                prefix += x;
                score += prefix;
                total += x;
            }
            arr[i] = {total, score};
        }
        
        sort(arr.begin(), arr.end(), [](const ArrayData &a, const ArrayData &b){
            return a.total > b.total;
        });
        ll running = 0, ans = 0;
        for (int i = 0; i < n; i++){
            ans += arr[i].score + m * running;
            running += arr[i].total;
        }
        
        cout << ans << "\n";
    }
    
    return 0;
}
