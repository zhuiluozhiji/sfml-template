#!/bin/bash
# filepath: /home/man567/code/sfml-template/build.sh

# 创建并进入 build 目录
mkdir -p build
cd build

# 如果没有生成 Makefile，则运行 cmake
if [ ! -f Makefile ]; then
    cmake ..
fi

# 运行 make
make

# 提示编译完成
echo "编译完成！可执行文件位于 build/bin 目录中。"