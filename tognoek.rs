use std::io;
use std::cmp::*;

fn solve() {
    let mut a = String::new();
    io::stdin().read_line(&mut a).unwrap();
    let mut b = String::new();
    io::stdin().read_line(&mut b).unwrap();
    let a = a.trim().as_bytes();
    let b = b.trim().as_bytes();
    let n = min(a.len(), b.len());
    for i in 0..n {
        let mut na = a[i] as i32;
        let mut nb = b[i] as i32;
        if na < 97 {
            na = na + 32;
        }
        if nb < 97 {
            nb = nb + 32;
        }
        if na < nb {
            println!("-1");
            return;
        } else if na > nb {
            println!("1");
            return;
        }
    }
    if a.len() < b.len() {
        println!("-1");
    } else if a.len() > b.len() {
        println!("1");
    } else {
        println!("0");
    }
}

fn main() {
    // tognoek learning rust language
    // today is 26/06/2026
    solve();
}