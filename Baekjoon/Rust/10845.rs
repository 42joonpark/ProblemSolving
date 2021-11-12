use std::io;
use io::Write;
fn main()
{
	let out = io::stdout();
    let mut stdout = io::BufWriter::new(out.lock());
	let mut line = String::new();
	std::io::stdin().read_line(&mut line).unwrap();
	let n : i32 = line.trim().parse().unwrap();
	let mut _vec = Vec::new();
	for _i in 0..n {
		line.clear();
		std::io::stdin().read_line(&mut line).unwrap();
		let tmp : Vec<String> = line.split(" ").map(|x| x.trim().parse().unwrap()).collect();
		let command = &tmp[0];
		match command.as_str() {
			"push" => {
				_vec.push(tmp[1].parse::<i32>().unwrap());
			}
			"pop" => {
				if _vec.len() == 0 {
					writeln!(stdout, "-1").unwrap();
				}
				else {
					writeln!(stdout, "{}", _vec[0]).unwrap();
					_vec.remove(0);
				}
			}
			"size" => {
				writeln!(stdout, "{}", _vec.len()).unwrap();
			}
			"empty" => {
				if _vec.len() == 0 {
					writeln!(stdout, "1").unwrap();
				} else {
					writeln!(stdout, "0").unwrap();
				}
			}
			"front" => {
				if _vec.len() == 0 {
					writeln!(stdout, "-1").unwrap();
				}
				else {
					writeln!(stdout, "{}", _vec[0]).unwrap();
				}	
			}
			"back" => {
				if _vec.len() == 0 {
					writeln!(stdout, "-1").unwrap();
				}
				else {
					writeln!(stdout, "{}", _vec[_vec.len() - 1]).unwrap();
				}
			}
			_ => {
			}
		}
	}
}