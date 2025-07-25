#!/bin/bash

# 获取脚本真实路径（即使通过软链接调用也能正确处理）
SCRIPT_DIR=$(cd "$(dirname "$(readlink -f "${BASH_SOURCE[0]}")")" &>/dev/null && pwd)
# VSCode配置路径（默认位置）
VSCODE_CONFIG_DIR="/home/$USER/.config/Code/User"
# 备份目标目录（自定义）
BACKUP_DIR="$SCRIPT_DIR/Source"
# 备份保留天数（示例保留最近3份）
MAX_BACKUPS=14

# 创建带时间戳的备份目录
TIMESTAMP=$(date +"%Y%m%d_%H%M%S")
TARGET_DIR="$BACKUP_DIR/vscode_backup_$TIMESTAMP"
mkdir -p "$TARGET_DIR"

# 备份配置文件夹（压缩为tar.gz）
tar -czf "$TARGET_DIR/vscode_config.tar.gz" -C "$VSCODE_CONFIG_DIR" .

# 清理旧备份（保留最新的MAX_BACKUPS份）
cd "$BACKUP_DIR" || exit
ls -1tr | head -n -$MAX_BACKUPS | xargs -d '\n' rm -rf --

# 记录日志（可选）
echo "[$(date)] VSCode配置已备份至 $TARGET_DIR" >> "$BACKUP_DIR/backup.log"

/media/frank/FrankW/_default/_Mine!/Working/code-spaces/GitPush.sh "Update vscode config backup files".
