#include <bits/stdc++.h>
using namespace std;

int main(){
    // Mở đọc dữ liệu từ file đàu vào và mở xuất vào file đầu ra
    freopen("maxgif.inp","r",stdin);
    freopen("maxgif.out","w",stdout);    
    // Bài toán yêu cầu tìm ra 2 số liền kề lớn nhất
    vector<int> myvector; // mảng chứa
    int n;
    long long result; // giá trị trả về
    long long temp; // giá trị tạm lưu
    cin>>n;
    for (int i = 0; i < n; i++){
        cin>>temp;
        myvector.push_back(temp);
    }
    result = myvector[0] + myvector[1]; // khởi tạo giá trị ban đầu
    for (int i = 2; i < n; i++){
        temp = myvector[i] + myvector[i-1]; // tổng 2 số liền kề
        result = max(result, temp); // so sánh với giá trị trả về [giá tị max]
    }
    cout<<result<<endl; // in kết quả ra file đầu ra
    return 0; // thoát chương trình
}