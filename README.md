# CameraTest

基于大恒 GalaxySDK 的工业相机采集示例，集成 rm_log 日志系统。

## 依赖

- 大恒 GalaxySDK Linux 版（需自行安装，并提供 `GxIAPI.h` 和 `libgxiapi.so`）
- spdlog
- CMake >= 3.10
- g++（支持 C++17）

## 编译

1. 修改 `CMakeLists.txt` 中的 `GALAXY_SDK_ROOT` 为你本机的大恒 SDK 路径。
2. 执行：

```bash
mkdir build && cd build
cmake ..
make
