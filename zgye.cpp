#include<bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FOD(i, a, b) for(int i = a; i >= b; i--)

const int N = 1e5 + 5;
int n, a[N], l, r, T;
vector<long long> myvector;

void in() {
    cin >> n >> T;
    long long aa;
    myvector.push_back(-10000);

    for (int i = 0; i < n; i++){
        cin >> aa;
        myvector.push_back(aa);
    }
    sort(myvector.begin(), myvector.end());
}

int get(int lim) {
    int low = 1, high = n, res = 0;

    while(low <= high) {
        int mid = (low + high) / 2;

        if(a[mid] <= lim) res = mid, low = mid + 1;
        else high = mid - 1;
    }
    return res;
}

void openfile(){
    freopen("Cuocthi.inp","r",stdin);
    freopen("Cuocthi.out","w",stdout);
}

void process() {
    while(T--) {
        cin >> l >> r;
        int left = lower_bound(myvector.begin(), myvector.end(), l) - myvector.begin() - 1;
        // left cuối cùng < l
        // right đầu tiền > r
        int right = lower_bound(myvector.begin(), myvector.end(), r + 1) - myvector.begin();
        // cout<<left<<" "<<right<<endl;
        cout<<right - left - 1<<endl;
        // int res = right - left;
        // if (res == 0){
        //     res = res;
        // }else{
        //     res++;
        // }
        // cout<<res<<endl;
    }
}

#undef int
int main() {
    openfile();
    in();
    process();
}
