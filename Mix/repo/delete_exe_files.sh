#!/bin/bash

# 切换到脚本所在的目录
cd "$(dirname "$0")"

# 删除当前目录下所有的 .exe 文件
rm -f *.exe

rm -f *.cpp__tests

echo "所有 .exe 文件已被删除。"