/**
 * @param {number} x
 * @return {number}
 */
var reverse = function(x) {
    let sign = x < 0 ? -1 : 1;
    let result = 0;
    x = Math.abs(x);
    while (x > 0){
        result = result * 10 + x % 10;
        x = Math.floor(x / 10);
    }
    if (sign * result < -1 * Math.pow(2, 31)){
        return 0;
    }
    if (sign * result > Math.pow(2, 31) - 1){
        return 0;
    }
    return sign * result;
};


console.log(reverse(1534236469))