use std::io;

fn count_problem(a: Vec<i32>) -> bool {
    let mut count = 0;
    for i in 0..a.len() {
        if a[i] == 1 {
            count += 1;
        }
    }
    return count > 1;

}

fn solve() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let n = input.trim().parse::<i32>().unwrap();
    let mut res = 0;
    for _ in 0..n {
        let mut input = String::new();
        io::stdin().read_line(&mut input).unwrap();
        let a = input.trim().split_whitespace().map(|x| x.parse::<i32>().unwrap()).collect();
        if count_problem(a) {
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