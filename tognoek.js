/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var search = function(nums, target) {
    let left = 0;
    let right = nums.length - 1;
    while (left  <= right){
        let mid = Math.floor((left + right) / 2);
        console.log('mid:', mid);
        if (nums[mid] === target){
            return mid;
        }else{
            if (nums[left] < nums[right]){
                if (nums[left] <= target && target < nums[mid]){
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }else{
                if (nums[mid] < nums[right]){
                    if (nums[mid] < target){
                        if (nums[right] < target){
                            right = mid - 1;
                        }else{
                            left = mid + 1;
                        }
                    }else{
                        right = mid - 1;
                    }
                }else{
                    if (nums[mid] < target){
                        left = mid + 1;
                    }else{
                        if (nums[left] <= target){
                            right = mid - 1;
                        }else{
                            left = mid + 1;
                        }
                    }
                }
            }
        }
        console.log('left:', left);
        console.log('right:', right);
    }
    return -1;
};
a = [3,5,1]
console.log(search(a, 3))