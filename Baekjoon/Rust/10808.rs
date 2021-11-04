fn main() {
    let mut _vec = vec![0; 26];
    let mut line = String::new();
    std::io::stdin().read_line(&mut line).unwrap();
    for _val in line.chars() {
        if _val == '\n' {
            break;
        }
        _vec[_val as usize - 'a' as usize] += 1;
    }
    for _i in 0..26 {
        print!("{} ", _vec[_i]);
    }
}
