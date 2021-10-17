# QPanda-gui
GUI for quantum computing framework QPanda-2(https://github.com/OriginQ/QPanda-2), based on Qt5.12.11

## build
just run cmake in build dir
```bash
mkdir build
cd build
cmake ..
cmake --build .
```
if Qt is installed in stander dir, run
```bash
mkdir build
cd build
cmake .. -DQT_DIR="your_qt_root_dir/5.12.11/gcc_64"
cmake --build .
```

## run
```bash
cd build
./src/QPanda_gui
```
It will work properly after config QPanda installed dir in gui