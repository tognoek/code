/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var threeSumClosest = function (nums, target) {
    let lengthNums = nums.length;
    let fault;
    let closestSum;
    for (let i = 0; i < lengthNums; i++) {
        for (let j = i + 1; j < lengthNums; j++) {
            for (let k = j + 1; k < lengthNums; k++) {
                let sum = nums[i] + nums[j] + nums[k];
                let diff = Math.abs(target - sum);
                if (fault === undefined || diff < fault) {
                    fault = diff;
                    closestSum = sum;
                }
            }
        }
    }
    return closestSum;
};
