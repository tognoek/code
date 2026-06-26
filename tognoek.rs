use std::io;

fn solve() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let nums: Vec<i32> = input.trim().split_whitespace().map(|x| x.parse::<i32>().unwrap()).collect();
    let n = nums[0];
    let k = nums[1];
    input.clear();
    io::stdin().read_line(&mut input).unwrap();
    let a: Vec<i32> = input.trim().split_whitespace().map(|x| x.parse::<i32>().unwrap()).collect();
    let mut res = 0;
    for i in 0..n {
        if a[i as usize] > 0 && a[i as usize] >= a[k as usize - 1] {
            res += 1;
        }
    }
    println!("{}", res);
}

fn main() {
    // tognoek learning rust language
    // today is 26/06/2026
    solve();
}