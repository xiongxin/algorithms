open Base

let rec digital_root (n : int) : int =
  let res =
    String.fold
      ~f:(fun acc c -> Int.of_string (Char.to_string c) + acc)
      ~init:0
      (Int.to_string n)
  in
  if res > 9 then digital_root res else res
;;
