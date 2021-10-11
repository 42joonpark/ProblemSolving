use std::io;
use io::Write;

fn main() {
	let stdout = io::stdout();
	let mut out = io::BufWriter::new(stdout.lock());
	let mut line = String::new();

	io::stdin().read_line(&mut line).unwrap();
	let test_case : i32 = line.trim().parse().unwrap();
	for _case in 0..test_case {
		let mut line = String::new();
		io::stdin().read_line(&mut line).unwrap();
		let vec : Vec<i32> = line.split(" ").map(|x| x.trim().parse().unwrap()).collect();
		let _sum : i32 = vec[1..].iter().sum();
		let mut ct : i32 = 0;
		let average : f64 = (_sum as f64) / (vec[0] as f64);
		for _i in 1..vec.len() {
			if (vec[_i] as f64) > average {
				ct += 1;
			}
		}
		writeln!(out, "{:.3}%", ((ct as f64) / (vec[0] as f64) * 100.0)).unwrap();
	}
}