use std::fs::File;
use std::io::{BufRead, BufReader};

fn main() {
    let f = File::open("../input.txt").unwrap();
    let r = BufReader::new(f);
    let mut pos = 0;
    let mut trees = 0;

    for l in r.lines().map(|x| x.unwrap()) {
	for (i, c) in l.chars().enumerate() {
	    if i == pos && c == '#' {
		trees += 1;
	    }
	}
	pos = (pos+3) % l.len();
    }
    println!("Answer: {}", trees);
}
