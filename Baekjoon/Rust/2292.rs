use std::io;
fn main() {
	let mut line = String::new();

	io::stdin().read_line(&mut line).unwrap();
	let num : u32 = line.trim().parse().unwrap();
	let mut _i : u32 = 2;
	let mut _ct : u32 = 1;
	let mut _gap = 6;
	while _i <= num {
		_ct += 1;
		_i += _gap;
		_gap += 6;
	}
	println!("{}", _ct);
}