use::std::io;
fn main() {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    let _tmp : Vec<i32> = line.split(" ").map(|x| x.trim().parse().unwrap()).collect();
    let _N : i32 = _tmp[0];
    let mut _K : i32 = _tmp[1];
    let mut _vec : Vec<i32> = Vec::new();
    for _i in 0.._N {
        line = String::new();
        io::stdin().read_line(&mut line).unwrap();
        let num = line.trim().parse().unwrap();
        _vec.push(num);
    }
    let mut _ct = 0;
    for _i in (0.._vec.len()).rev() {
        while _vec[_i] <= _K
        {
            _ct += 1;
            _K -= _vec[_i];
        }
    }
    println!("{}", _ct);
}
