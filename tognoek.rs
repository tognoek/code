#![allow(unused_imports)]
use std::io;
use std::cmp::*;

fn solve() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let mut numbers: Vec<i32> = input.trim().split("+").map(|x| x.parse().unwrap()).collect();
    numbers.sort();
    for (index, value) in numbers.iter().enumerate() {
        print!("{}", value);
        if index != numbers.len() - 1 {
            print!("+");
        }
    }
}

fn main() {
    // tognoek learning rust language
    // today is 26/06/2026
    solve();
}