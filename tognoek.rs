#![allow(unused_imports)]
use std::io;
use std::cmp::*;

fn solve() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let mut chars: Vec<char> = input.trim().chars().collect();
    chars[0] = chars[0].to_ascii_uppercase();
    for i in 0..chars.len() {
        print!("{}", chars[i]);
    }
}

fn main() {
    // tognoek learning rust language
    // today is 26/06/2026
    solve();
}