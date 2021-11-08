/*
use std::io::{self, Read};
fn main() {
    for b in io::stdin().bytes() {
        let c = b.unwrap() as char;
        print!("{}", c);
    }
}
*/

use std::io::prelude::*;
fn  main() {
    let stdin = std::io::stdin();

    for line in stdin.lock().lines() {
        println!("{}", line.unwrap());
    }
}
