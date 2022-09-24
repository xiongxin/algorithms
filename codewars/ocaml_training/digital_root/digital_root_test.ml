open OUnit2
open Digital_root

let suite =
  let test_with input expected =
    let format_input = Printf.sprintf "n = %d" in
    assert_equal
      expected
      (digital_root input)
      ~msg:(format_input input)
      ~printer:string_of_int
  in
  "Fixed tests"
  >:: fun _ ->
  test_with 16 7;
  test_with 195 6;
  test_with 992 2;
  test_with 999999999 9;
  test_with 167346 9;
  test_with 0 0
;;

let _ = run_test_tt_main suite
