fn main() {
	let mut line = String::new();
	std::io::stdin().read_line(&mut line).unwrap();
	let vec : Vec<i32> = line.split(" ").map(|x| x.trim().parse().unwrap()).collect();
	println!("{}", (vec[0] + vec[1]) % vec[2]);
	println!("{}", ((vec[0] % vec[2]) + (vec[1] % vec[2])) % vec[2]);
	println!("{}", (vec[0] * vec[1]) % vec[2]);
	println!("{}", ((vec[0] % vec[2]) * (vec[1] % vec[2])) % vec[2]);
}