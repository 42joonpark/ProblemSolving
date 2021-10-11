fn main() {
	let mut line = String::new();
	std::io::stdin().read_line(&mut line).unwrap();
	let vec : Vec<i32> = line.split(" ").map(|x| x.trim().parse().unwrap()).collect();
	let _n = vec[0];
	let _val = vec[1];
	line = String::new();
	std::io::stdin().read_line(&mut line).unwrap();
	let vec : Vec<i32> = line.split(" ").map(|x| x.trim().parse().unwrap()).collect();
	for x in vec {
		if x < _val {
			println!("{}", x);
		}
	}
}