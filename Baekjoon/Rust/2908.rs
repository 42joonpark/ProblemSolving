fn reverse(mut num : i32) -> i32 {
	let mut val;

	val = 0;
	while num > 0 {
		val *= 10;
		val += num % 10;
		num /= 10;
	}
	val
}

fn main() {
	let mut line = String::new();

	std::io::stdin().read_line(&mut line).unwrap();
	let vec : Vec<i32> = line.split(" ").map(|x| x.trim().parse().unwrap()).collect();
	let rA = reverse(vec[0]);
	let rB = reverse(vec[1]);
	if rA > rB {
		println!("{}", rA);
	}
	else {
		println!("{}", rB);
	}
}