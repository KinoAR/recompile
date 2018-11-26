# Recompile
### Author:  Kino Rose

This project allows you to take a single reason file and compile it for either bytecode or into a Javascript Node.js script with some caveats. Requires some understanding of what binaries are available for use on your system.

# Install Dependencies
```
npm install 
```

# Build
```
npm run build
```
# Build + Watch

```
npm run start
```

# Build Native
```
npm run native
```
# Build Bytecode
```
npm run bytecode
```



# Editor
If you use `vscode`, Press `Windows + Shift + B` it will build automatically
# How Does It Work?
This works by taking the reason code and running it through a **refmt** to convert it to plain Ocaml or binary. Next the code is compiled to either bytecode, native, or Javascript.

## Compile To Bytecode
```
./lib/bs/native/recompile vowelCount.re vowelCount -bytecode
```

## Compile To JS
```
./lib/bs/native/recompile vowelCount.re vowelCount -js
```