#!/bin/bash

# 自动 add、commit、并推送到所有远程
# 用法：./auto-commit-and-push.sh "你的提交说明"

# 检查是否有提交说明
if [ -z "$1" ]; then
  echo "用法：$0 \"提交说明\""
  exit 1
fi

commit_msg="$1"

# 自动 add 和 commit
git add .
git commit -m "$commit_msg"

# 推送到所有远程
for remote in Gtiee_Repo Gtihub_Repo; do
  echo "正在推送到 $remote ..."
  git push $remote --all
done