/*
fn main() {
    let month : [i32; 13] = [0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];
    let week : [&str; 7] = ["SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"];
    let mut line = String::new();
    std::io::stdin().read_line(&mut line).unwrap();
    
    let vec : Vec<i32> = line.split(" ").map(|x| x.trim().parse().unwrap()).collect();
    let mut sum : i32 = 0;
    for i in 1..vec[0] as usize {
        sum += month[i];
    }
    sum += vec[1];
    println!("{}", week[(sum % 7 as i32) as usize]);
}
*/

fn main() {
    let month : [usize; 13] = [0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];
    let week : [&str; 7] = ["SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"];
    let mut line = String::new();
    std::io::stdin().read_line(&mut line).unwrap();
    
    let vec : Vec<usize> = line.split(" ").map(|x| x.trim().parse().unwrap()).collect();
    println!("{}", week[((&month[..vec[0]]).iter().sum::<usize>() + vec[1] as usize ) % 7]);
}
