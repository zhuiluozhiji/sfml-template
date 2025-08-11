#!/bin/bash
# filepath: /home/man567/code/sfml-template/run.sh




cd "$(dirname "$0")" # 切换到脚本所在目录，即项目根目录,避免load图片资源等相对路径错误
./build/bin/main
