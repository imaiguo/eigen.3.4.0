
# EIGEN

## Build with MSVC

### 构建Release
```bash
> cmd
> "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat"
> mkdir build & cd build
> cmake .. -G Ninja -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=D:\devtools\eigen.3.4.0
> ninja
> ninja install
```

### 构建Debug
```bash
> cmake .. -G Ninja -DCMAKE_BUILD_TYPE=Debug -DCMAKE_INSTALL_PREFIX=D:\devtools\eigen.3.4.0
```
