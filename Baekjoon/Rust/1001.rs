fn main() {
	let mut line = String::new();
	std::io::stdin().read_line(&mut line).expect("error.");
	let vec: Vec<i32> = line.split(" ").map(|x| x.trim().parse().expect("error.")).collect();
	println!("{}", vec[0] - vec[1]);
}