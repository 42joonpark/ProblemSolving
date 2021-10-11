fn main() {
	let mut line = String::new();

	std::io::stdin().read_line(&mut line)
	.expect("could not read.");

	let inputs: Vec<u32> = line.split(" ")
	.map(|x| x.trim().parse().expect("Not an integer")).collect();
	println!("{}", inputs[0] + inputs[1]);
}