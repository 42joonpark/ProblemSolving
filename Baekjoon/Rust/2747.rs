fn main() {
    let mut line = String::new();

    std::io::stdin().read_line(&mut line).unwrap();
    let mut _n : i32 = line.trim().parse().unwrap();
    let mut result = 0;
    let mut a = 0;
    let mut b = 1;
    if _n == 0 {
        println!{"{}", a};
    } else if _n == 1 || _n == 2 {
        println!{"{}", b};
    } else {
        while _n > 1 {
            result = a + b;
            a = b;
            b = result;
            _n -= 1;
        }
        println!("{}", result);
    }
}
