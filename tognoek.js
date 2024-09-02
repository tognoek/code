/**
 * @param {string[]} strs
 * @return {string}
 */
var longestCommonPrefix = function(strs) {
    let result = "";
    let lengthMin = strs.reduce((min, str) => str.length < min ? str.length : min, 201);
    for (let index = 0; index < lengthMin; index++) {
        let char = strs[0][index];
        if (strs.every((str) => {
            return str[index] === char;
        })){
            result += char;
        }else{
            return result;
        }
    }
    return result;
};
const input = ["dog","racecar","car"]
console.log(longestCommonPrefix(input))