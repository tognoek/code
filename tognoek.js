/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
    let location = {};
    let countChar = {};
    let start = -1;
    let startChar = -1;
    let result = 0;
    let length = s.length;
    let char;
    for (let index = 0; index < length; ++index){
        // console.log(char)
        char = s[index];
        if (isNaN(countChar[char])){
            countChar[char] = 1;
        }else{
            countChar[char]++;
        }
        if (countChar[char] > 1){
            startChar = location[char];
            if (startChar > start){
                start = startChar;
            }
            countChar[char] = 1;
        }
        result = Math.max(result, index - start);
        location[char] = index;
    }
    return result;
};
console.log(lengthOfLongestSubstring("abcad")); 