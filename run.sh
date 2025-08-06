#!/bin/bash
# filepath: /home/man567/code/sfml-template/run.sh

# 进入 build/bin 目录
cd build/bin

# 检查可执行文件是否存在
if [ -f main ]; then
    # 运行可执行文件
    ./main
else
    echo "错误：可执行文件 'main' 不存在，请先编译项目。"
fi