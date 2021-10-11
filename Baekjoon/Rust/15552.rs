use std::io;
use io::Write;

fn main() {
    let stdout = io::stdout();
    let mut out = io::BufWriter::new(stdout.lock());
	let mut line = String::new();

	std::io::stdin().read_line(&mut line).unwrap();
	let _num : u32 = line.trim().parse().unwrap();
	for _x in 0.._num {
		let mut line = String::new();
		std::io::stdin().read_line(&mut line).unwrap();
		let _num : Vec<i32> = line.split(" ").map(|x| x.trim().parse().unwrap()).collect();
		writeln!(out, "{}", _num[0] + _num[1]).unwrap();
	}
}