let args = Array.sub(Sys.argv, 1, Array.length(Sys.argv) - 1);
let startWithDash = (string) => String.contains(string, '-');
let arrGet = (index, arr) => Array.get(arr, index);
let flags = args |> Array.to_list |> List.filter(startWithDash) |> Array.of_list;
let performFlagOperation = (flag) => {
    let message = switch (flag) {
    | "-js"=> "Compiling to js"
    | "-bytecode" => "Compiling to bytecode"
    | "-native" => "Compiling to native"
    | _ => "Invalid compiler options"
    };
    message;
};
let test = "Hello World";
print_endline( Array.get(args, 0));
print_endline(Array.get(flags, 0) |> performFlagOperation);