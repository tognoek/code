use std::io;

fn solve() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let nums: Vec<i32> = input.trim().split_whitespace().map(|x| x.parse::<i32>().unwrap()).collect();
    let m = nums[0];
    let n = nums[1];
    let res = m * n / 2;
    println!("{}", res);
}

fn main() {
    // tognoek learning rust language
    // today is 26/06/2026
    solve();
}