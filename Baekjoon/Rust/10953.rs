fn main() {
    let mut line = String::new();

    std::io::stdin().read_line(&mut line).unwrap();
    let _test_case : i32 = line.trim().parse().unwrap();
    for _i in 0.._test_case {
        line.clear();
        std::io::stdin().read_line(&mut line).unwrap();
        let _vec : Vec<i32> = line.split(",").map(|x| x.trim().parse().unwrap()).collect();
        println!("{}", _vec[0] + _vec[1]);
    }
}
