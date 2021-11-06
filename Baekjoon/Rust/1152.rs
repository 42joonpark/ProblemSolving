/*
fn main() {
    let mut line = String::new();

    std::io::stdin().read_line(&mut line).unwrap();

    let bytes = line.as_bytes();
    let mut _i = 0;
    let mut ct = 0;
    while _i < bytes.len() {
        let mut c = bytes[_i] as char;
        if c.is_alphabetic() {
            ct += 1;
            while c.is_alphabetic() && _i < bytes.len() {
                _i += 1;
                c = bytes[_i] as char;
            }
        }
        else {
            _i += 1;
        }
    }
    println!("{}", ct);
}
*/
fn main() {
    let mut line = String::new();

    std::io::stdin().read_line(&mut line).unwrap();
    let vec : Vec<&str> = line.trim().split_whitespace().collect();
    println!("{}", vec.len());
}
