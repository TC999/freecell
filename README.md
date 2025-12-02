# freecell
win7 空当接龙原始反编译项目

## 项目结构

- `decomp/` - IDA 反编译输出文件（不要修改）
- `freecell/` - 重构后的可编译源代码

## 构建说明

### 前提条件

需要安装 MinGW-w64 交叉编译工具链：

```bash
# Ubuntu/Debian
sudo apt-get install g++-mingw-w64-x86-64

# Arch Linux
sudo pacman -S mingw-w64-gcc
```

### 构建步骤

```bash
cd freecell
make
```

构建成功后会生成 `FreeCell.exe` 可执行文件。

### 清理构建产物

```bash
cd freecell
make clean
```

### 使用 CMake 构建（可选）

```bash
mkdir build && cd build
cmake -DCMAKE_TOOLCHAIN_FILE=mingw-toolchain.cmake ../freecell
make
```

## 文件说明

| 文件 | 说明 |
|------|------|
| `types.h` | 公共类型定义和全局变量声明 |
| `IEngineInterface.h` | 引擎接口定义 |
| `EngineHandler.h/cpp` | 引擎处理器实现 |
| `DialogHelper.h/cpp` | 对话框辅助类 |
| `FreeCellGame.h/cpp` | 空当接龙游戏主逻辑 |
| `InitializeEngine.h/cpp` | 引擎初始化 |
| `winmain.cpp` | Windows 程序入口 |
| `globals.cpp` | 全局变量定义 |

## 注意事项

1. 所有修改都在 `freecell/` 目录下进行，不要修改 `decomp/` 目录
2. 当前代码是基于 IDA 反编译结果重构的框架代码
3. 部分功能为存根实现，需要根据 `decomp/` 中的反编译结果进一步完善
