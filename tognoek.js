/**
 * @param {string} s
 * @param {number} numRows
 * @return {string}
 */
var convert = function(s, numRows) {
    if (numRows === 1){
        return s;
    }
    let length = s.length;
    let variable = [numRows * 2 - 2, 0];
    let result = '';
    let indexVariable;
    for (let index = 0; index < numRows; index++) {
        let indexChar = index;
        indexVariable = 0;
        while (indexChar < length) {
            if (variable[indexVariable] > 0){
                result += s[indexChar];
            }
            indexChar += variable[indexVariable];
            indexVariable = (indexVariable + 1) % 2;
        }
        variable[0] -= 2;
        variable[1] += 2;
    }
    return result;  
};


console.log(convert("PAYPALISHIRING", 1))

// console.log("PAHNAPLSIIGYIR".length)