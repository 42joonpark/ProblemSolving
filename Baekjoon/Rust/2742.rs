use std::io;
use io::Write;

fn main() {
	let stdout = io::stdout();
	let mut out = io::BufWriter::new(stdout.lock());
	let mut line = String::new();

	io::stdin().read_line(&mut line).unwrap();
	let mut n : u32 = line.trim().parse().unwrap();
	while n > 0 {
		writeln!(out, "{}", n).unwrap();
		n -= 1;
	}
}