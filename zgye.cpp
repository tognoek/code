#include <iostream>
#include <vector>
#include <algorithm>

bool canFindSubarrayWithAvgAtLeast(const std::vector<int>& nums, int k, double avg) {
    int n = nums.size();
    std::vector<double> prefixSum(n + 1, 0.0);
    for (int i = 0; i < n; ++i) {
        prefixSum[i + 1] = prefixSum[i] + nums[i] - avg;
    }
    //for (auto& i : prefixSum) {
    //    std::cout << i << " ";
    //}
    //std::cout<<std::endl;
    double minPrefix = 0.0;
    for (int i = k; i <= n; ++i) {
        if (prefixSum[i] - minPrefix >= 0) {
        //std::cout<<-1<<" "<<i<<" "<<prefixSum[i]<<" " <<avg<<" "<<minPrefix<<std::endl;
            return true;
        }
        //std::cout<<i - k + 1<<" "<<prefixSum[i - k + 1]<<" " <<avg<<" "<<minPrefix<<std::endl;
        minPrefix = std::min(minPrefix, prefixSum[i - k + 1]);
    }

    return false;
}

double findMaxAverage(const std::vector<int>& nums, int k) {
    double left = *std::min_element(nums.begin(), nums.end());
    double right = *std::max_element(nums.begin(), nums.end());
    double precision = 1e-5;

    while (right - left > precision) {
        double mid = left + (right - left) / 2.0;
        if (canFindSubarrayWithAvgAtLeast(nums, k, mid)) {
            left = mid;
        } else {
            right = mid;
        }
    }

    return left;
}

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> nums[i];
    }

    double result = findMaxAverage(nums, k);
    std::cout.precision(3);
    std::cout << std::fixed << result << std::endl;

    return 0;
}
