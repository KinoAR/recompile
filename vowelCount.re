let args = Array.sub(Sys.argv, 1, Array.length(Sys.argv) - 1);

let isVowel = character =>
  switch (character) {
  | 'a'
  | 'e'
  | 'i'
  | 'o'
  | 'u'
  | 'y' => true
  | _ => false
  };

let fileText = fileName => {
  let lines = ref("");
  let openChannel = open_in(fileName);
  let break = ref(false);
  while (! break^) {
    let result =
      try (input_line(openChannel)) {
      | End_of_file => ""
      };
    if (String.length(result) < 1) {
      break := true;
    };
    lines := lines^ ++ result;
  };
  close_in(openChannel);
  lines^;
};

let trimFileName = name =>
  String.contains_from(name, String.length(name), '/') ?
    String.sub(name, 0, String.length(name) - 1) : name;

let vowelToNumber = (charString: string) => {
  let vowel =
    String.length(charString) > 0 ? isVowel(charString.[0]) : false;
  vowel ? 1 : 0;
};

/* let add = (x, y) => x + y;
let countVowelFromFile = fileName =>
  fileName
  |> trimFileName
  |> fileText
  |> Str.split_delim(Str.regexp(""))
  |> List.map(vowelToNumber)
  |> List.fold_left((x, y) => x + y, 0);

let vowelTotal =
  Array.map(countVowelFromFile, args) |> Array.fold_left((x, y) => x + y, 0);
print_endline(string_of_int(vowelTotal)); */