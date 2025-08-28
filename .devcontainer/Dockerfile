FROM mcr.microsoft.com/devcontainers/cpp:1-ubuntu-22.04

# 安装编译工具
RUN apt-get update && \
    apt-get install -y gdb build-essential cmake clang

# 设置工作目录
WORKDIR /workspace