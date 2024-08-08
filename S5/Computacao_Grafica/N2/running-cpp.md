Using g++:
`g++ file.cpp -o buildfile -lGL -lGLU -lglut && ./buildfile`

Using makefile:
```bash
  make all # build and run above commands with g++
  make clear # equals to rm buildfile
```

Using cmake:
```bash
  mkdir build
  cd build/
  cmake ..
  make
  ./buildfile # (based on CMakeLists.txt "add_executable()")
```