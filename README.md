### dynamic link library compilation

` $ clang++ -o libmath.so -shared math.cxx `

### main program compilation
` $ clang++ -o math use_math_dll.cxx -ldl`
