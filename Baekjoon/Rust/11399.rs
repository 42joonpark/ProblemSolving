fn main() {
	let mut line = String::new();

	std::io::stdin().read_line(&mut line).unwrap();
	let _num : u32 = line.trim().parse().unwrap();
    line = String::new();
    std::io::stdin().read_line(&mut line).unwrap();
	let mut _vec : Vec<i32> = line.split(" ").map(|x| x.trim().parse().unwrap()).collect();
    _vec.sort();
    let mut _sum = 0;
    for _idx in 0.._vec.len(){
        if _idx > 0 {
            _vec[_idx] += _vec[_idx - 1];
        }
        _sum += _vec[_idx];
    }
    println!("{}", _sum);
}
