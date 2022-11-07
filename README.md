# ArtiApp-Template

Template to use [ArtiApp](https://github.com/Erick3900/ArtiApp) preconfigured to load a custom font on ImGui and to hide the console on windows in release mode

## Build instructions

```bash
mkdir build
cd build
conan install ../deps/ArtiApp --build=missing -s build_type=Release
cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=1 -DCMAKE_BUILD_TYPE=Release ..
cmake --build . -j8
```
