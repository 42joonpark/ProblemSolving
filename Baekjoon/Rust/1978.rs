fn is_sosu(num : i32) -> i32 {
	let ct : i32 = 0;
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
	let mut line = String::new();

	std::io::stdin().read_line(&mut line).unwrap();
	let _n : i32 = line.trim().parse().unwrap();
	let mut line = String::new();
	std::io::stdin().read_line(&mut line).unwrap();
	let vec : Vec<i32> = line.split(" ").map(|x| x.trim().parse().unwrap()).collect();
	let mut ct = 0;
	for _i in 0..vec.len() {
		if is_sosu(vec[_i]) == 1 {
			ct += 1;
		}
	}
	println!("{}", ct);
}