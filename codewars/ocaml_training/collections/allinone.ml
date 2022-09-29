open Batteries

let rec all_num n res =
  match n with
  | 0 -> res
  | _ -> all_num (n / 10) ((n mod 10) :: res)
;;

let dig_pow (n : int) (p : int) : int =
  let pow =
    List.fold_left (fun (sum, po) v -> sum + Int.pow v po, po + 1) (0, p) (all_num n [])
  in
  if fst pow mod n = 0 then fst pow / n else -1
;;

let prod4sum (a : int) (b : int) (c : int) (d : int) =
  ((a * a) + (b * b)) * ((c * c) + (d * d))
;;

(* 又理解错题目了 -_-! *)
let prod2Sum (a : int) (b : int) (c : int) (d : int) : int array array =
  let sum = prod4sum a b c d in
  let rec loop i until res checked =
    match i with
    | n1 when n1 = until -> res
    | n2 ->
      (match List.find_opt (fun v -> v = n2) checked with
      | None ->
        let m = sum - (n2 * n2) in
        let sqrt_m = int_of_float (sqrt (float_of_int m)) in
        if m = Int.pow sqrt_m 2
        then
          loop
            (n2 + 1)
            until
            (Array.append res [| [| n2; sqrt_m |] |])
            (n2 :: sqrt_m :: checked)
        else loop (n2 + 1) until res checked
      | Some _ -> loop (n2 + 1) until res checked)
  in
  if sum = 0 then [||] else loop 1 (int_of_float (sqrt (float_of_int sum))) [||] []
;;
