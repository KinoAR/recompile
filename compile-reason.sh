ocamlc str.cma -pp "refmt --print binary" -o ./$2 -impl $1
rm *.cm*