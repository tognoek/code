#include <bits/stdc++.h>
using namespace std;

int main(){
    // Mở đọc dữ liệu từ file đàu vào và mở xuất vào file đầu ra
    freopen("CHARNUM.INP","r",stdin);
    freopen("CHARNUM.OUT","w",stdout);    
    // Bài toán yêu cầu đếm số lượng số đã dùng khi đánh số từ 1 - n
    long long n, temp;
    long long result = 0; // kết qủa trả về
    cin>>n;
    if (n < 10){
        cout<<n; // trường hợp các số nhỏ hơn 10 thì xuất ra luôn;
        return 0; 
    }
    int lenN = 0; // độ dài của số được cho 
    temp = n; // sử dụng biến tạm để không mất đi giá trị đầu vào;
    while(temp != 0){
        lenN++;
        temp /= 10;
    }
    result = 9;
    long long begin = 10; // số bắt đầu để tính
    long long end = 99; // số kết thúc trong khoảng tính
    long long numSize; // số lượng số trong khoảng các số có x chữ số
    for (int i = 2; i < lenN; i++){
        numSize = end - begin + 1;
        result = result + i * numSize;
        begin = begin * 10; // tăng số khởi đàu thêm 1 số
        end = end * 10 + 9; // tăng số kết thúc thêm 1 số
    }
    numSize = n - begin + 1; // số lượng số đã dùng trong khoảng các số có x chữ số [đến số đã cho]
    result = result + numSize * lenN; // chèn thêm phần đuôi cụt
    cout<<result; 
    return 0; // thoát chương trình
}