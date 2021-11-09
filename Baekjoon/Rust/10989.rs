use std::io::Write;

fn main() {
	let stdout = std::io::stdout();
	let mut out = std::io::BufWriter::new(stdout.lock());
	let mut line = String::new();

	std::io::stdin().read_line(&mut line).unwrap();
	let n : usize = line.trim().parse().unwrap();
	let mut vec = vec![0; 10001];
	for _i in 0..n {
		line.clear();
		std::io::stdin().read_line(&mut line).unwrap();
		let num : usize = line.trim().parse().unwrap();
		vec[num] += 1;
	}
	for _i in 1..10001 {
		for _k in 0..vec[_i] {
			writeln!(out, "{}", _i).unwrap();
		}
	}
}