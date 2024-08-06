#include <bits/stdc++.h>
using namespace std;
const int N10e3 = 1015;
int ArrSangNgto[N10e3];
vector<int> ArrLoc;
long ArrRes[N10e3];
void sangNgto(int Nmax){ // Hàm sàng nguyên tố các số bé hơn N đầu vào
    ArrSangNgto[0] = 1;
    ArrSangNgto[1] = 1;
    for (int __i = 2; __i * __i <= Nmax; __i++)
        if (ArrSangNgto[__i] == 0)
            for (int __t = __i * __i; __t <= Nmax; __t += __i)
                ArrSangNgto[__t] = 1;
}
void slove(int A){ // Hàm phân tích một số ra thừa số nguyên tố
    for (auto ir : ArrLoc){
        while (A % ir == 0){
            A /= ir;
            ArrRes[ir]++;
        }
    }
}
void loc(int Nmax){ // Hàm lọc các số nguyên tố bé hơn N đầu vào
    for (int i = 2; i <= Nmax; i++){
        if (ArrSangNgto[i] == 0){
            ArrLoc.push_back(i);
        }
    }
}
int main() {
    freopen("GIAITHUA.INP","r",stdin);
    freopen("GIAITHUA.OUT","w",stdout);  
    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    // Bài toán yêu cầu phân tích N! ra thừa số nguyên số
    int N;
    cin>>N;
    sangNgto(N + 10);
    loc(N + 5);
    for (int i = 2; i <= N; i++){
        slove(i); // Với mỗi số trong tập tích [Giai thừa] sẽ phân tích ra thừa số nguyên tô.
    }
    int mx = -1;
    for (auto i : ArrLoc){
        if (ArrRes[i] > 0){
            mx = i; // Lấy ra số nguyên tố lớn nhất được tạo để tránh in thừa
        }
    }
    for (auto i : ArrLoc){
        if (i > mx){
            break;
        }
        cout<<ArrRes[i]<<" "; // In ra các chỉ số mũ của từng số nguyên tố tạo thành
    }
    return 0;
}
