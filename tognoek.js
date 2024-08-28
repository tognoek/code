/**
 * @param {string} s
 * @return {number}
 */
var myAtoi = function(s) {
    s = s.trim();
    s = s + 'end';
    let sign = 1;
    let result = 0;
    let length = s.length;
    for (let index = 0; index < length; index++) {
        let char = parseInt(s[index]);
        if (isNaN(char)){
            if (index === 0){
                switch (s[index]) {
                    case '-':
                        sign = -1;
                        break;
                    case '+':
                        sign = 1;
                        break;
                    default:
                        return 0;
                }
            }else{
                if (sign * result < -1 * Math.pow(2, 31)){
                    return -1 * Math.pow(2, 31);
                }
                if (sign * result > Math.pow(2, 31) - 1){
                    return Math.pow(2, 31) - 1;
                }
                if (result == 0){
                    return 0;
                }
                return sign * result;
            }
        }else{
            result = result * 10 + char;
        }
    }

};