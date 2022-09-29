open Core

let longestConsec (xs : string list) (k : int) : string =
  let n = List.length xs in
  let rec iter mxs ys =
    let ss = String.concat (List.take ys k) in
    if String.length ss > String.length mxs
    then iter ss (List.tl_exn ys)
    else iter mxs (List.tl_exn ys)
  in
  if n = 0 || k > n || k <= 0 then "" else iter "" xs
;;
