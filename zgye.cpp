#include <iostream>
#include <algorithm>

using namespace std;

// Hàm tính giá trị biểu thức (a XOR b) + (b XOR c) + (c XOR a)
int calculate(int a, int b, int c)
{
    return (a ^ b) + (b ^ c) + (c ^ a);
}

// Hàm tìm giá trị max của biểu thức và in ra a, b, c
void findMaxXORSum(int l, int r)
{
    if (l == r)
    {
        cout << "a = b = c = " << l << endl;
        cout << "Max value: 0" << endl;
        return;
    }

    // Tìm giá trị tối đa của (a XOR b) + (b XOR c) + (c XOR a)
    // Chúng ta thử các giá trị a = l, b = r, và c trong phạm vi [l, r]
    int maxSum = 0;
    int bestA = l, bestB = l, bestC = l;

    // Thử các giá trị a, b trong phạm vi [l, r] và tìm c sao cho giá trị biểu thức tối đa
    for (int a = l; a <= r; ++a)
    {
        for (int b = l; b <= r; ++b)
        {
            for (int c = l; c <= r; ++c)
            {
                int sum = calculate(a, b, c);
                if (sum > maxSum)
                {
                    maxSum = sum;
                    bestA = a;
                    bestB = b;
                    bestC = c;
                }
            }
        }
    }

    // In các giá trị a, b, c và giá trị biểu thức
    cout << "a = " << bestA << ", b = " << bestB << ", c = " << bestC << endl;
    cout << "Max value: " << maxSum << endl;
}

int main()
{
    int l, r;
    cin >> l >> r;

    findMaxXORSum(l, r);

    return 0;
}
