use std::io;
use io::Write;

fn is_sosu(num : i32) -> i32 {
	let mut i : i32 = 2;
	if num < 2 {
		return 0;
	}
	while i * i <= num {
		if num % i == 0 {
			return 0;
		}
		i += 1;
	}
	1
}
fn main() {
	let stdout = io::stdout();
	let mut out = io::BufWriter::new(stdout.lock());
	let mut line = String::new();
	std::io::stdin().read_line(&mut line).unwrap();
	let vec : Vec<i32> = line.split(" ").map(|x| x.trim().parse().unwrap()).collect();
	for _i in vec[0]..=vec[1] {
		if is_sosu(_i) == 1 {
			writeln!(out, "{}", _i).unwrap();
		}
	}
}