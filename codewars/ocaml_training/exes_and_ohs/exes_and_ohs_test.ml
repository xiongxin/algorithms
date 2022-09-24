open OUnit2
open Exes_and_ohs

let suite =
  "Basic tests (description examples)"
  >::: [ ("Test 1"
         >:: fun _ ->
         assert_equal
           true
           (xo "ooxx")
           ~msg:{|"ooxx" contains the same number of 'x's and 'o's : two of each.|}
           ~printer:string_of_bool)
       ; ("Test 2"
         >:: fun _ ->
         assert_equal
           false
           (xo "xooxx")
           ~msg:
             {|"xooxx" does not contains the same number of 'x's and 'o's : three 'x's and two 'o's|}
           ~printer:string_of_bool)
       ; ("Test 3"
         >:: fun _ ->
         assert_equal
           true
           (xo "ooxXm")
           ~msg:{|"ooxXm" contains the same number of 'x's and 'o's : two of each.|}
           ~printer:string_of_bool)
       ; ("Test 4"
         >:: fun _ ->
         assert_equal
           true
           (xo "zpzpzpp")
           ~msg:{|"zpzpzpp" contains the same number of 'x's and 'o's : none of each.|}
           ~printer:string_of_bool)
       ; ("Test 5"
         >:: fun _ ->
         assert_equal
           false
           (xo "zzoo")
           ~msg:
             {|"xooxx" does not contains the same number of 'x's and 'o's : no 'x's and two 'o's|}
           ~printer:string_of_bool)
       ]
;;

let _ = run_test_tt_main suite
