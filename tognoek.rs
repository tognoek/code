use std::io;

fn solve() {
    let mut input = String::new();
    io::stdin().read_line(&mut input). unwrap();
    let weight_watermelon = input.trim().parse::<i32>().unwrap();

    if weight_watermelon % 2 == 0 && weight_watermelon > 2 {
        println!("YES");
    } else {
        println!("NO");
    }
}

fn main() {
    // tognoek learning rust language
    // today is 26/06/2026
    solve();
}