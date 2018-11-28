/* 
* Command Example: recompile <fileName> <buildType> <outputName>
* Example: recompile readFile.re readFile -backend js
*/
let args = Array.sub(Sys.argv, 1, Array.length(Sys.argv) - 1);
let rec findIndex = (element, n, arr) => {
  if(n == -1) {
    -1;
  }
  else if(Array.get(arr, n) == element) {
    n;
  } else {
    findIndex(element, n - 1, arr);
  }
};
let concatString = (str1, str2) => str1 ++ str2;
let getArgs = Array.get(args);
let index = findIndex("-pkg", Array.length(args) - 1, args) + 1;
let libs = Array.sub(args, index, Array.length(args) - index);

let fileName = 0 |> getArgs;
let outFileName = 1 |> getArgs;
let compileType = 2 |> getArgs;

let jsCommand = "bsc -pp \"refmt --print ml\" -c -impl " ++ fileName ++ " -o " ++ outFileName;
let byteCommand = "-pp \"refmt --print binary\" -o  ./" 
  ++ outFileName ++ " -impl " ++ fileName;
let nativeCommand = "-pp \"refmt --print binary\" -o  ./" 
  ++ outFileName ++ " -impl " ++ fileName;

let containsString = (stringToCheck, strChecker) => {
  /* print_endline(stringToCheck ++ "Test") */
  let re = Str.regexp_string(strChecker);
  let result = try (Str.search_forward(re,stringToCheck,0)) {
    | Not_found => 0
  };
  result;
}
let makeLibString = (extension, libArr) => Array.map(concatString(_, extension ++ " "), libArr)
  |> Array.fold_left(concatString, "");
let makeLibs = makeLibString(_, libs);
let performFlagOperation = (flag) => {
  let commandOps = switch (flag) {
    | "js" => (jsCommand, "javascript")
    | "native" => ("ocamlopt " ++ makeLibs(".cmxa") ++ nativeCommand, "native")
    | "bytecode" => ("ocamlc " ++ makeLibs(".cma") ++ byteCommand, "bytecode")
    | _ => ("empty", "empty")
  }
  let (command, outType) = commandOps;
  /* 0 means the command was successful; 2 means there was an error.*/
  let commandNumber = Sys.command(command);
   Sys.command("rm *.cm*") |> ignore;
  if(commandNumber == 0) {
    print_endline("Compiled " ++ fileName ++ " to: " ++ 
    outType ++ "; name: " ++ outFileName);
  } else {
    print_endline("Failed compilation");
  }
  
};
performFlagOperation(compileType);