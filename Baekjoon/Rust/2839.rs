fn main() {
    let mut line = String::new();
    std::io::stdin().read_line(&mut line).unwrap();
    let _n : i32 = line.trim().parse().unwrap();
    
    let mut _sum = 0;
    let mut _a = 0;
    let mut _b = 1;
    if _n >= 2 {
        let mut _idx = 2;
        while _idx <= _n {
            _sum = _a + _b;
            _a = _b;
            _b = _sum;
            _idx += 1;
        }
        println!("{}", _sum);
    }
    else if _n == 0 {
        println!("0");
    }
    else if _n == 1 {
        println!("1");
    }
}
