https://codeforces.com/gym/465037/problem/D?locale=en

Mely là một lập trình viên trẻ rất tài năng. Cô ấy thích giải quyết các bài toán khó và luôn tìm kiếm những cách mới để cải thiện kỹ năng của mình. Một ngày nọ, Mely được giao một bài toán khó: tìm giá trị trung vị lớn nhất có thể của một mảng gồm n
 số nguyên không âm (không nhất thiết phải phân biệt), sao cho tổng các phần tử trong mảng bằng s
.

Trung vị của một mảng số nguyên có độ dài m
 là số đứng ở vị trí thứ ⌈m2⌉
 (làm tròn lên) trong dãy được sắp xếp không giảm của các phần tử. Các vị trí được đánh số bắt đầu từ 1
. Ví dụ, trung vị của mảng [20,40,20,50,50,30]
 là phần tử thứ ⌈m2⌉
 trong dãy [20,20,30,40,50,50]
, do đó là 30
. Có các định nghĩa khác về trung vị, nhưng trong vấn đề này, chúng ta sử dụng định nghĩa như đã mô tả.

# Input
Đầu vào bao gồm nhiều test case. Dòng đầu tiên chứa một số nguyên duy nhất t
 (1≤t≤104
) - số lượng test case. Mô tả các test case được đưa ra sau đó.

Mỗi test case chứa một dòng duy nhất với hai số nguyên n
 và s
 (1≤n,s≤109
) - độ dài của mảng và tổng các phần tử cần có.

# Output
Đối với mỗi test case, in ra một số nguyên duy nhất - giá trị trung vị lớn nhất có thể.

# Examples
|input|output|
|-----|------|
|8|
|1 5| 5|
|2 5| 2|
|3 5|2
|2 1|0|