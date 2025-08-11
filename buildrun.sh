#!/bin/bash
# filepath: /home/man567/code/sfml-template/build_and_run.sh

# 切换到脚本所在目录（项目根目录）
cd "$(dirname "$0")"

# 创建并进入 build 目录
mkdir -p build
cd build

# 如果没有生成 Makefile，则运行 cmake
if [ ! -f Makefile ]; then
    cmake .. || { echo "CMake 配置失败！"; exit 1; }
fi

# 运行 make
make || { echo "编译失败！"; exit 1; }

# 提示编译完成
echo "编译完成！可执行文件位于 build/bin 目录中。"

cd .. # 切换到脚本所在目录，即项目根目录,避免load图片资源等相对路径错误
./build/bin/main