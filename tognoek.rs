use std::io;

fn main() {
    let mut input = String::new();
    let mut count_chart = vec![0;255];
    io::stdin().read_line(&mut input).unwrap();
    
    for c in input.chars() {
        count_chart[c as usize] = 1;
    }
    let mut res = 0;
    for i in 0..255 {
        if count_chart[i] == 1 {
            res += 1;
        }
    }
    if res % 2 == 0 {
        println!("CHAT WITH HER!");
    } else {
        println!("IGNORE HIM!");
    }
}