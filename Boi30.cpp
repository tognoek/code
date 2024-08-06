#include <bits/stdc++.h>
using namespace std;

int main(){
    // Mở đọc dữ liệu từ file đàu vào và mở xuất vào file đầu ra
    freopen("BOI30.INP","r",stdin);
    freopen("BOI30.OUT","w",stdout);    
    // Bài toán yêu cầu chuyển số được cho về số lớn nhất chia hết cho 30
    string s;
    cin>>s;
    int n = s.length();
    vector<int> myvector; //  dùng để chứa các số trong riêng lẻ
    for (int i = 0; i < n; i++){
        myvector.push_back(s[i]-'0');
    }
    int sum = 0; // chứ tổng các số 
    bool check = false; // kiểm tra xem có số 0 nào tồn tại hay không
    for (auto i : myvector){
        if (i == 0){
            check = true;
        }
        sum = sum + i;
    }
    if (check == false || sum % 3 != 0){ // nếu nhưng số đó không có số 0 nào hoặc là là không chia hết cho 3 thì sẽ không chia hết 30
        cout<<-1;
        return 0;
    }
    sort(myvector.begin(), myvector.end(), greater<int>());
    // in ra số lớn nhất chia hết cho 30
    for (auto i : myvector){
        cout<<i;
    }
    return 0;
}