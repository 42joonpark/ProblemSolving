fn main() {
    let mut line = String::new();
    std::io::stdin().read_line(&mut line).unwrap();
    let mut n : i32 = line.trim().parse().unwrap();
    while n > 1 {
        for _i in 2..=n {
            if n % _i == 0 {
                println!("{}", _i);
                n = n / _i;
                break ;
            }
        }
    }
}
