Using g++:
`g++ file.cpp -o file -lGL -lGLU -lglut && ./file`

Using cmake:
```bash
  mkdir build
  cd build/
  cmake ..
  make
  ./file # (based on CMakeLists.txt "add_executable()")
```