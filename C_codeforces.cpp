#include <bits/stdc++.h>

using namespace std;

int encode_binary(const string& s, int start, int length) {
    int result = 0;
    for (int i = start; i < start + length; ++i) {
        result = (result << 1) | (s[i] - '0');
    }
    return result;
}

int find_best_match(const string& s1, const string& s2) {
    int n1 = s1.size();
    int n2 = s2.size();
    int s2_encoded = encode_binary(s2, 0, n2);

    int min_diff = -INT_MAX;
    int best_start = -1;   

    for (int i = 0; i <= n1 - n2; ++i) {
        int match_count = 0; 
        for (int j = 0; j < n2; ++j) {
            if (s1[i + j] == s2[j]) {
                match_count++;
            } else {
                break;
            }
        }
        if (match_count > min_diff) { 
            min_diff = match_count;
            best_start = i;
        }
    }


    return best_start + 1; 
}

void solve(){
    string s, mau;
    cin >> s;
    int t = 0;
    mau = "";
    for (int i = 0; i < s.length(); i++){
        if (s[i] == '0'){
            t = 1;
            mau = mau + '1';
        }else{
            if (t == 1){
                mau = mau + '0';
            }
        }
    }
    if (mau.length() == 0){
        cout << 1 << " " << s.length() << " " << 1 << " " << 1;
        return;
    }
    int r = find_best_match(s, mau);
    cout << 1 << " " << s.length() << " " << r << " " << r + mau.length() - 1;
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    while (T--){
        solve();
        cout << endl;
    }
    return 0;
}
