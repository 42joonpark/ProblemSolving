fn main() {
    let mut line = String::new();
    std::io::stdin().read_line(&mut line).unwrap();
    
    let _n = line.trim().parse().unwrap();
    let mut _arr = vec![0; _n + 1];
    for i in 2..=_n {
        _arr[i] = _arr[i - 1] + 1;
        if i % 2 == 0 {
            if _arr[i] > _arr[i / 2] + 1 {
                _arr[i] = _arr[i / 2] + 1;
            }
        }
        if i % 3 == 0 {
            if _arr[i] > _arr[i / 3] + 1 {
                _arr[i] = _arr[i / 3] + 1;
            }
        }
    }
    println!("{}", _arr[_n]);
}
