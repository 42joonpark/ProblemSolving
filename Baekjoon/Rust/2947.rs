fn check(_vec: &Vec<i32>) -> i32 {
    for _i in 0..4 {
        if _vec[_i] > _vec[_i + 1] {
            return 0;
        }
    }
    1
}

fn main() {
    let mut line = String::new();

    std::io::stdin().read_line(&mut line).unwrap();
    let mut _vec : Vec<i32> = line.split(" ").map(|x| x.trim().parse().unwrap()).collect();
    while check(&_vec) == 0 {
        for i in 0..4 {
            if _vec[i] > _vec[i + 1] {
                let tmp = _vec[i];
                _vec[i] = _vec[i + 1];
                _vec[i + 1] = tmp;
                println!("{} {} {} {} {}", _vec[0], _vec[1], _vec[2], _vec[3], _vec[4]);
            }
        }
    }
}
