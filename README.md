https://codeforces.com/gym/465037/problem/C

Bạn được cho một mảng a
 gồm n
 số nguyên dương **(n≥3
)**. Điều này có nghĩa là trong mảng này, tất cả các số trừ một số là giống nhau (ví dụ: trong mảng **[4,11,4,4]**
 tất cả các số trừ một số là bằng 4
).

Hãy in ra chỉ số của phần tử không bằng các phần tử còn lại trong mảng. Các số trong mảng được đánh số từ một.

# Input
Dòng đầu tiên chứa một số nguyên t
 **(1≤t≤100
)** — số lượng bộ test. Tiếp theo là t
 bộ test.

Mỗi bộ test bắt đầu bằng một số nguyên n
 **(3≤n≤100
)** — độ dài của mảng a
. Dòng tiếp theo của mỗi bộ test chứa n
 số nguyên a1,a2,…,an
 **(1≤ai≤100
)**.

Đảm bảo rằng trong mảng a
, tất cả các số trừ một số đều giống nhau.

# Output
Đối với mỗi bộ test, in ra một số nguyên duy nhất — chỉ số của phần tử không bằng các phần tử còn lại trong mảng.

# Example
|**input**|**output**|
|---|---|
|4|
|4|
|11 13 11 11|2|
|5|
|1 4 4 4 4|1|
|10|
|3 3 3 3 10 3 3 3 3 3|5|
|3|
|20 20 10|3|
