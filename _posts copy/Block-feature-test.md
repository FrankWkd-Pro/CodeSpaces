---
title: 关于本博客的代码块功能说明&构建日志
mathjax: true
date: 2025-07-11 21:09:22
tags: 
- Others
categories: 
- 建站
---
# 代码块
统一格式：
```
:::[type] [title]
文本内容

:::

```
> 虽然是代码块，但是也能放其他东西（和文章的要求没什么区别）。
> 如果`[title]`一栏为空，则显示高亮默认内容，否则高亮显示`[title]`的内容。

:::warning 
避坑指南：
- 每个代码块的结尾标记和前面后面必须跟空行，否则会出现渲染错误。
- 每个代码块的结尾标记那一行必须只能有`:::`三个英文半角冒号，否则会出现渲染错误。

:::

## 隐藏/折叠代码块
### 格式
```
:::details [block title]
[Custom text goes here]

:::

```
### 实例
:::details 点击此处查看已折叠内容(这里的可以自定义哦～)
This is a hidden code.
This is a custom **plaintext**.

:::

----

## 警告代码块
### 格式
```
:::warning [block title]
[Custom text goes here]

:::

```
### 实例
:::warning 警告(这里的可以自定义哦～)
This is a warning code.
This is a custom **plaintext**.

:::

----

## 提示代码块
### 格式
```
:::tip [block title]
[Custom text goes here]

:::

```
### 实例
:::tip 提示(这里的可以自定义哦～)
This is a reminder.
This is a custom **plaintext**.

:::

----

## 危险代码块
### 格式
```
:::danger [block title]
[Custom text goes here]

:::

```
### 实例
:::danger 警告(这里的可以自定义哦～)
This is a danger code.
This is a custom **plaintext**.

:::

----

# 建站日志
```
2025.07.10 建站于Ubuntu 24.04 LTS [Hexo+NPM]
2025.07.10 托管代码于Github，使用Github Pages提供的网页界面
2025.07.10 使用Vercel加速网站访问（似乎用处不大）
2025.07.11 使用CloudFlare代替Vercel加速网站访问，使得从国内也可以极速访问
2025.07.11 把大部分洛谷写过的题解搬运到这里
2025.07.11 添加博客的latex公式支持
```


:::details 点此展开感谢名单
- Github
- Hexo
- Nodejs
- npm
- yarn
- nvm
- Github Pages
- Cloudflare
- Vercel
- SusTech CDN
- Aurora Blog Theme
- Jsdelivr CDN
- Ubuntu (Pro)
- Clash Verge
- vscode
- Copilot
- Luogu@heishao || uid: 1059545
- Doubao
- Vim
- Gitlen Entension
- Markdown
- LateX
- Remote SSH Entensions Pack
- Bash
- Git
- Gitee
- Deepseek
- Wechat
- 说实话，最感谢的就是QQ音乐，比咖啡中用多了! ![](https://qqemoji.heyc.eu.org/56x56/mm.gif)

:::