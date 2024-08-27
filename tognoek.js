/**
 * @param {string} s
 * @return {string}
 */
var longestPalindrome = function(s) {
    string = '#' + s.split('').join('#') + '#';
    // console.log(string);
    let n = string.length;
    let left, right;
    let listCount = Array(n + 5).fill(0)
    left = 0;
    right = -1;
    let result = {left : 0, right : -1, length : -1};
    for (let index = 1; index < n; index++) {
        listCount[index] = Math.max(0, Math.min(right - index, listCount[left + (right - index)]));
        if (isNaN(listCount[index])) {
            listCount[index] = 0;
        }
        while (string[index + listCount[index]] === string[index - listCount[index]] 
            && index + listCount[index] >= 0 
            && index + listCount[index] < n) {
            listCount[index]++;
        }
        if (index + listCount[index] > right) {
            left = index - listCount[index];
            right = index + listCount[index];
        }
        // console.log(string[index], left, right);
        if (right - left > result.length) {
            result.left = left + 1;
            result.right = right - 1;
            result.length = right - left;
        }
    }
    let stringReslut = string.slice(result.left + 1, result.right);
    return stringReslut.replaceAll('#', '');

};

console.log(longestPalindrome("aabcbaa"))