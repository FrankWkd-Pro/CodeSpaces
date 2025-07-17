---
title: 给你的Hexo静态博客部署LateX支持
date: 2025-07-11 17:54:59
tags: 
- LateX
categories: 
- 编辑
- 建站
mathjax: true
---

# 给你的Hexo静态博客部署 $Latex$ 支持
众所周知，hexo搭建的静态博客非常nice，但是对于OIer来说没有LateX公式支持，岂不是美中不足？

# Way1: 在线编写
Link: [CodeCogs Equation Editor](http://latex.codecogs.com/)

## 插入图片
```
![](https://latex.codecogs.com/svg.latex?sin(5))
```

### 效果

![](https://latex.codecogs.com/svg.latex?sin(5))

## 其他主题

[GitHub](https://github.com/next-theme/hexo-filter-mathjax)

# Way2: [根本性解决]模块安装

```bash
npm install hexo-filter-mathjax
hexo clean
```

## 配置

`_config.yml`

:::details 点击查看新增配置
```yml
mathjax:
  tags: none # or 'ams' or 'all'
  single_dollars: true # enable single dollar signs as in-line math delimiters
  cjk_width: 0.9 # relative CJK char width
  normal_width: 0.6 # relative normal (monospace) width
  append_css: true # add CSS to pages rendered by MathJax
  every_page: false # if true, every page will be rendered by MathJax regardless the `mathjax` setting in Front-mattersa
```
:::

## 使用方法

在要启用 MathJax 的每篇文章（文章 / 页面）的前题中，将 mathjax 设置为 true。 例如：

```
---
title: On the Electrodynamics of Moving Bodies
categories: Physics
date: 1905-06-30 12:00:00
mathjax: true
---
```

然后，您可以在文章中使用 LaTeX 语法。

## NexT 主题

## 配置

`_config.next.yml`

```yml
math:
  every_page: true
  mathjax:
    enable: true
```