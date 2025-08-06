#!/bin/bash
# filepath: /home/man567/code/sfml-template/git_push.sh

# 提示用户输入提交信息
echo "请输入提交信息："
read commit_message

# 执行 Git 命令
git add .
git commit -m "$commit_message"
git push origin master

# 提示完成
echo "代码已成功提交并推送到远程仓库！"