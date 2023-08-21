https://codeforces.com/gym/465037/problem/A

Gọi dãy b
 là một dãy con của dãy a
 nếu b
 có thể được tạo ra từ a
 bằng cách xóa 0 hoặc nhiều phần tử và không làm thay đổi thứ tự của các phần tử. Ví dụ, ta có **a=[1,2,1,3,1,2,1]**
, thì các dãy con hợp lệ là: **[1,1,1,1]**
, **[3]**
 và **[1,2,1,3,1,2,1]**
, chứ không phải **[3,2,3]**
 và **[1,1,1,1,2]**
.

Mely được cho a
 là dãy gồm n
 giá trị dương và âm (không có giá trị 0 trong dãy a
).

Nhiệm vụ của Mely là Tối đa hóa kích thước (độ dài) dãy con đảo chiều của dãy được cho . Trong tất cả những dãy con đó, Mely phải chọn ra dãy con có tổng lớn nhất . (Dãy đảo chiều là dãy mà 2 phần tử liền kề trái dấu nhau).

Nói cách khác, nếu độ dài tối đa của dãy con đảo chiều là k
 thì nhiệm vụ của Mely là phải chọn ra dãy con đảo chiều có tổng lớn nhất có độ dài là k
.

Bạn được cho t
 testcases :

# Input
Dòng đầu tiên của đầu vào chứa số nguyên t
 **(1≤t≤104
)** — số lượng test cases.

Dòng đầu tiên của mỗi testcase chứa số nguyên n
 **(1≤n≤2⋅105
)** — số lượng phần tử của dãy a
. Dòng thứ hai của mỗi testcase chứa n
 số nguyên a1,a2,…,an
 **(−109≤ai≤109,ai≠0
)**, với ai
 là phần tử thứ i
 của dãy a a
.

**Đảm bảo rằng tổng tất cả các n
 không vượt quá 2⋅105
 (∑n≤2⋅105
).**

# Output
Với mỗi testcase , in ra một số nguyên là tổng lớn nhất của dãy con đảo chiều có kích thước lớn nhất (**độ dài**) của dãy a
.