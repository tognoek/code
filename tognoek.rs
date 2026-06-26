use std::io;

fn waytoolong(input: String) -> String {
    if input.len() < 11 {
        return input;
    } else {
        let len_mid = input.len() - 2;
        return format!("{}{}{}", input.chars().next().unwrap(), len_mid, input.chars().last().unwrap());
    }
}

fn solve() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let mut n = input.trim().parse::<i32>().unwrap();
    while n != 0 {
        let mut string = String::new();
        io::stdin().read_line(&mut string).unwrap();
        string = string.trim().to_string();
        println!("{}", waytoolong(string));
        n = n - 1;
    }
}

fn main() {
    // tognoek learning rust language
    // today is 26/06/2026
    solve();
}