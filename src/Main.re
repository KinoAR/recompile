/* 
* Command Example: recompile <fileName> <buildType> <outputName>
* Example: recompile readFile.re readFile -backend js
*/
let args = Array.sub(Sys.argv, 1, Array.length(Sys.argv) - 1);
let startWithDash = (string) => String.contains(string, '-');
let startWithoutDash = (string) => !String.contains(string, '-');
let arrGet = (index, arr) => Array.get(arr, index);
let flags = args |> Array.to_list |> List.filter(startWithDash) 
  |> Array.of_list;
let fileNames = args |> Array.to_list |> List.filter(startWithoutDash) 
  |> Array.of_list;

let fileName = Array.get(fileNames, 0);
let outFileName = Array.get(fileNames, 1);
let jsCommand = "bsc -pp \"refmt --print ml\" -c -impl " ++ fileName ++ " -o " ++ outFileName;
let byteCommand = "ocamlc str.cma -verbose -pp \"refmt --print binary\" -o  ./" 
  ++ outFileName ++ " -impl " ++ fileName;
let nativeCommand = "ocamlc str.cma -verbose -pp \"refmt --print binary\" -o  ./" 
  ++ outFileName ++ " -impl " ++ fileName;
let performFlagOperation = (flag) => {
  let commandOps = switch (flag) {
    | "-js" => (jsCommand, "javascript")
    | "-native" => (nativeCommand, "native")
    | "-bytecode" => (byteCommand, "bytecode")
    | _ => ("empty", "empty")
  }
  let (command, outType) = commandOps;
  Sys.command(command) |> ignore;
  Sys.command("rm *.cm*") |> ignore;
  print_endline("Compiled " ++ fileName ++ " to: " ++ 
    outType ++ "; name: " ++ outFileName);
};
performFlagOperation(Array.get(flags, 0));