use std::io;

fn solve() {
    let mut n: i32 = -1;
    let mut m: i32 = -1;
    let mut input = String::new();
    for i in 0..5 {
        io::stdin().read_line(&mut input).unwrap();
        let nums: Vec<i32> = input.trim().split_whitespace().map(|x| x.parse::<i32>().unwrap()).collect();
        for (index, value) in nums.into_iter().enumerate() {
            if value == 1 {
                n = i as i32;
                m = index as i32;
                break;
            }
        }
        input.clear();
    }
    let res = (n - 2).abs() + (m - 2).abs();
    println!("{}", res);

}

fn main() {
    // tognoek learning rust language
    // today is 26/06/2026
    solve();
}