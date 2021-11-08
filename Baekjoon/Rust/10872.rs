fn main() {
    let mut line = String::new();

    std::io::stdin().read_line(&mut line).unwrap();
    let n : i32 = line.trim().parse().unwrap();
    let mut sum = 1;
    for _i in 1..= n {
        sum = sum * _i;
    }
    println!("{}", sum);
}
