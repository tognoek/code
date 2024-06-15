#include <iostream>
#include <vector>
#include <algorithm> // std::max

using namespace std;

long long maxSubArraySum(const vector<long long>& nums) {
    long long max_current = nums[0];
    long long max_global = nums[0];

    for (size_t i = 1; i < nums.size(); ++i) {
        max_current = max(nums[i], max_current + nums[i]);
        if (max_current > max_global) {
            max_global = max_current;
        }
    }

    return max_global;
}

int main() {
    int n;
    cin >> n;
    vector<long long> nums(n);

    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    cout << maxSubArraySum(nums) << endl;

    return 0;
}
