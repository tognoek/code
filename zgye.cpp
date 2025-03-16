#include <bits/stdc++.h>
using namespace std;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t; 
    cin >> t;
    while(t--){
        int n, m, k;
        cin >> n >> m >> k;
 
        // Xét trường hợp một loại ký tự bằng 0.
        if(n == 0){
            // Chuỗi chỉ có '1'; balance = |0 - m| = m.
            if(k == m) {
                cout << string(m, '1') << "\n";
            } else {
                cout << -1 << "\n";
            }
            continue;
        }
        if(m == 0){
            // Chuỗi chỉ có '0'; balance = n.
            if(k == n) {
                cout << string(n, '0') << "\n";
            } else {
                cout << -1 << "\n";
            }
            continue;
        }
 
        string s;
        // Trường hợp n >= m: dùng ánh xạ '0' → +1, '1' → –1.
        if(n >= m){
            // Điều kiện cần: k >= (n-m) và k <= n.
            if(k < (n - m) || k > n){
                cout << -1 << "\n";
                continue;
            }
            // Bắt buộc: ép k bước đầu bằng '0'.
            s = string(k, '0');
            int current = k;          // Giá trị hiện tại.
            int rem0 = n - k;         // Số '0' còn lại.
            int rem1 = m;             // Số '1' còn lại.
            int target = n - m;       // Giá trị cần đạt cuối cùng.
 
            // Tiến hành xây dựng phần còn lại.
            while(rem0 > 0 || rem1 > 0){
                if(current == k){
                    // Đang ở biên trên, không được tăng nữa.
                    if(rem1 > 0){
                        s.push_back('1');
                        current--; rem1--;
                    } else break; // Không có bước nào.
                }
                else if(current == 0){
                    // Ở biên dưới, chỉ được tăng.
                    if(rem0 > 0){
                        s.push_back('0');
                        current++; rem0--;
                    } else break;
                }
                else { // current trong (0, k)
                    int delta = target - current;
                    if(delta > 0){
                        // Cần tăng: ưu tiên dùng '0' nếu còn.
                        if(rem0 > 0){
                            s.push_back('0');
                            current++; rem0--;
                        } else if(rem1 > 0){
                            s.push_back('1');
                            current--; rem1--;
                        }
                    }
                    else if(delta < 0){
                        // Cần giảm: ưu tiên dùng '1' nếu còn.
                        if(rem1 > 0){
                            s.push_back('1');
                            current--; rem1--;
                        } else if(rem0 > 0){
                            s.push_back('0');
                            current++; rem0--;
                        }
                    }
                    else { // delta == 0: hiện tại đạt target.
                        // Chọn bước sao cho không dễ “đuôi” ra ngoài biên.
                        int distDown = current;       // Khoảng cách đến 0.
                        int distUp = k - current;       // Khoảng cách đến k.
                        if(distUp < distDown){
                            if(rem1 > 0){
                                s.push_back('1');
                                current--; rem1--;
                            } else if(rem0 > 0){
                                s.push_back('0');
                                current++; rem0--;
                            }
                        } else {
                            if(rem0 > 0){
                                s.push_back('0');
                                current++; rem0--;
                            } else if(rem1 > 0){
                                s.push_back('1');
                                current--; rem1--;
                            }
                        }
                    }
                }
            }
 
            if(rem0==0 && rem1==0 && current == target)
                cout << s << "\n";
            else
                cout << -1 << "\n";
        }
        else {
            // Trường hợp m > n: dùng ánh xạ ngược, cho '1' → +1, '0' → –1.
            if(k < (m - n) || k > m){
                cout << -1 << "\n";
                continue;
            }
            s = string(k, '1');
            int current = k;          // Giá trị hiện tại.
            int rem1 = m - k;         // Số '1' còn lại.
            int rem0 = n;             // Số '0' còn lại.
            int target = m - n;       // Giá trị cần đạt.
 
            while(rem0 > 0 || rem1 > 0){
                if(current == k){
                    // Ở biên trên: chỉ được giảm, nghĩa là thêm '0'.
                    if(rem0 > 0){
                        s.push_back('0');
                        current--; rem0--;
                    } else break;
                }
                else if(current == 0){
                    // Ở biên dưới: chỉ được tăng, thêm '1'.
                    if(rem1 > 0){
                        s.push_back('1');
                        current++; rem1--;
                    } else break;
                }
                else {
                    int delta = target - current;
                    if(delta > 0){
                        // Cần tăng: ưu tiên '1'.
                        if(rem1 > 0){
                            s.push_back('1');
                            current++; rem1--;
                        } else if(rem0 > 0){
                            s.push_back('0');
                            current--; rem0--;
                        }
                    }
                    else if(delta < 0){
                        // Cần giảm: ưu tiên '0'.
                        if(rem0 > 0){
                            s.push_back('0');
                            current--; rem0--;
                        } else if(rem1 > 0){
                            s.push_back('1');
                            current++; rem1--;
                        }
                    }
                    else { // delta == 0:
                        int distDown = current;
                        int distUp = k - current;
                        if(distUp < distDown){
                            if(rem0 > 0){
                                s.push_back('0');
                                current--; rem0--;
                            } else if(rem1 > 0){
                                s.push_back('1');
                                current++; rem1--;
                            }
                        } else {
                            if(rem1 > 0){
                                s.push_back('1');
                                current++; rem1--;
                            } else if(rem0 > 0){
                                s.push_back('0');
                                current--; rem0--;
                            }
                        }
                    }
                }
            }
 
            if(rem0==0 && rem1==0 && current == target)
                cout << s << "\n";
            else
                cout << -1 << "\n";
        }
    }
    return 0;
}
