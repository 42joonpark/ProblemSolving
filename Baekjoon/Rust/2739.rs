fn main() {
	let mut line = String::new();
	std::io::stdin().read_line(&mut line).expect("error");
	let n : u32 = line.trim().parse().expect("msg: &str");
	for i in 1..10 {
		println!("{} * {} = {}", n, i, n * i);
	}
}