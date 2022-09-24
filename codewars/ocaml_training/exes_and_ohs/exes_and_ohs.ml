open Base

let xo (s : string) : bool =
  let x, o =
    String.fold
      ~f:(fun (f, s) c ->
        if Char.equal c 'x' || Char.equal c 'X'
        then f + 1, s
        else if Char.equal c 'o' || Char.equal c 'O'
        then f, s + 1
        else f, s)
      ~init:(0, 0)
      s
  in
  x = o
;;
