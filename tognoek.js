/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var threeSum = function (nums) {
    console.time('fuck')
    let flags = [];
    let flagsResult = [];
    let result = [];
    nums.sort();
    for (let index = 0; index < nums.length; index++) {
        if (flags[nums[index]]) {
            flags[nums[index]]++;
        } else {
            flags[nums[index]] = 1;
        }
    }
    for (let indexFisrt = 0; indexFisrt < nums.length; indexFisrt++) {
        for (let indexSecond = indexFisrt + 1; indexSecond < nums.length; indexSecond++) {
            let target = 0 - nums[indexFisrt] - nums[indexSecond];
            let countNumber = flags[target];
            countNumber = countNumber - (nums[indexFisrt] === target ? 1 : 0) - (nums[indexSecond] === target ? 1 : 0);
            if (countNumber > 0) {
                let values = [nums[indexFisrt], nums[indexSecond], target];
                values.sort();
                if (flagsResult[values.join('_')] == undefined) {
                    flagsResult[values.join('_')] = true;
                    result.push(values);
                }
            }
        }
    }
    console.timeEnd('fuck')
    return result;
};

threeSum([-1, 0, 1, 0]);
// console.log(parseInt(true));
