use std::fs::File;
use std::io::{BufRead, BufReader};

fn main() {
    let f = File::open("../input.txt").unwrap();
    let r = BufReader::new(f);
    let slopes = vec![(1, 1), (3, 1), (5, 1), (7, 1), (1, 2)];
    let lines: Vec::<String> = r.lines().map(|x| x.unwrap()).collect();
    let runs = slopes.iter().map(|x| count_trees(&lines, &x));
    let mut answer = 1;
    for hits in runs {
	answer = answer * hits;
	println!("Hit: {}", hits);
    }
    println!("Answer: {}", answer);
}

fn count_trees(lines: &Vec::<String>, slope: &(usize, usize)) -> usize {
    let mut col: usize = 0;
    let mut row: usize = 0;
    let mut trees: usize = 0;

    for (i, l) in lines.iter().enumerate() {
	if i == row {
	    for (j, c) in l.chars().enumerate() {
		if j == col && c == '#' {
		    trees += 1;
		}
	    }
	    row +=slope.1;
	    col = (col+slope.0) % l.len();
	}
    }
    return trees;
}
