use std::io;
use io::Write;

fn main() {
	let stdout = io::stdout();
    let mut out = io::BufWriter::new(stdout.lock());
	let mut vec = vec![0; 10001];

	for mut _num in 1..10001 {
		let mut _tmp = _num;
		while _num > 0 {
			_tmp += _num % 10;
			_num /= 10;
		}
		if _tmp < 10001 {
			vec[_tmp] = 1;
		}
	}
	for _num in 1..10001 {
		if vec[_num] == 0 {
			writeln!(out, "{}", _num).unwrap();
		}
	}
}