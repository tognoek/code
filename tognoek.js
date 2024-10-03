/**
 * @param {number[][]} triangle
 * @return {number}
 */
var minimumTotal = function (triangle) {
    let f = []
    f[0] = [triangle[0][0]];
    let n = triangle.length;
    console.log(n)
    for (let i = 1; i < n; i++) {
        let temp = []
        for (let t = 0; t < triangle[i].length; t++) {
            if (t === 0){
                temp[t] = triangle[i][t] + f[i-1][t];
            }
            else if (t === triangle[i].length - 1) {
                temp[t] = triangle[i][t] + f[i-1][t-1];
            }
            else {
                temp[t] = Math.min(f[i-1][t-1], f[i-1][t]) + triangle[i][t];
            }
        }
        console.log(temp);
        f[i] = temp;
    }
    let result = f[n-1][0];
    for (let i = 0; i < triangle[n-1].length; i++){
        console.log(f[n-1][i])
        if (f[n-1][i] < result) result = f[n-1][i];
    }
    console.log(result);
    return result;
};

minimumTotal([[2], [3, 4], [6, 5, 7], [4, 1, 8, 3]]);
