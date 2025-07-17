---
title: CSP-S 02 做题记录
mathjax: true
date: 2025-07-12 06:42:14
tags: 
- C++
categories:
- 做题记录
- czos
---
> ###### Latest Updated: 2025.07.14

# T1 扩容（Expend）

:::details 点击展开题面

### 题目描述
小 $A$ 有一个云系统，初始容量为 $S$ 个单位。随着芯片技术的飞速发展，云系统会不定期的为小 $A$ 免费扩容。

具体的扩容方法为：枚举当前容量 $S$ 中每一位的数值。
- 如果当前数值为 $1$，扩容后当前这一位的值依然是 $1$。
- 如果当前数值为 $2$，扩容后当前这一位的值会扩展为 $22$。
- 如果当前数值为 $3$，扩容后当前这一位的值会扩展为 $333$。
- $\dots$
- 如果当前数值为 $i$，扩容后当前这一位的值会扩展为 $i$ 个 $i$。

例如：假设云系统的初始容量为 $S = 123$，那么接下来 $3$ 次扩容，系统容量的变化分别为。
- 第 $1$ 次扩容后，容量变为 $122333$。
- 第 $2$ 次扩容后，容量变为 $1222233333333$。
- 第 $3$ 次扩容后，容量变为 $122222222333333333333333333333333333$。

经过多年的扩容，云系统的容量将变得非常大。请你编程计算出，在经过 $10^{15}$ 次扩容之后，云系统容量从左向右数第 $C$ 位的数值是多少？

### 输入
第一行输入一个数字串 $S$，由数字 $1$ 到 $9$ 组成，表示初始容量。  
第 $2$ 行输入整数 $C$，表示答案要求的最终容量从左向右数的位数。  

### 输出
输出一个整数，表示经过 $10^{15}$ 次扩容之后，云系统容量从左向右数第 $C$ 位的数值。  

### 样例
#### 输入
```
123
5
```
#### 输出
```
2
```

#### 输入
```
5
180
```
#### 输出
```
5
```

#### 输入
```
179692458
9460730472580800
```
#### 输出
```
7
```

### 说明
#### 样例解释
##### 样例 1 解释  
请参考题目描述中的解释。  

##### 样例 2 解释  
初始容量为 $5$，无论怎样扩容，容量数值的每一位都将是 $5$。  

### 数据范围
对于所有的测试数据，保证：数字串 $S$ 的长度在 $[1, 100]$ 范围内，且仅由数字 $1$ 到 $9$ 组成。$1 \leq C \leq 10^{18}$。经过 $10^{15}$ 次扩容后，数字串的长度至少为 $C$。  

### 测试点
| 测试点      | 特殊性质     |
| ----------- | ------------ |
| $1 \sim 4$  | 特殊性质 $A$ |
| $6 \sim 8$  | 特殊性质 $B$ |
| $9 \sim 20$ | 无           |

#### 特殊性质 $A$：满足 $C = 1$。  
#### 特殊性质 $B$：满足 $S[0] \neq 1$。  

:::

## T1 Sol
考虑到扩容次数非常巨大，即使是 $2$ 扩容 $10^{15}$ 之后也有 $2^{10^{15}}$ 位。这远远超出了可存储范围。

我们从前往后遍历。遇到 $1$ 就认为它扩容后不会变，遇到其他的就直接输出。如果直到第 $c$ 位还是 $1$ ，就直接输出 $1$。

:::warning 警告！

请开 $long\ long$.  
$string$ 类型的字符数组要注意 $c > string.size()$ 时的越界问题。  
还要注意 $string$ 从 $0$ 开始计数。

:::

## T1 Code **[40pts]**
> 根据特性 `A` & `B` 骗分

```cpp
/*
 * > CPP Code Snippet <
 * > Powered by Microsoft Visual Studio Code <
 *
 * @Author    FrankWKD (wangkedi01)
 * @Date      2025-07-14
 * @Network   "https://oj.czos.cn/contest/problem?id=25573&pid=0"
 * @License   GNU General Public License 2.0
 * @Platform  [Frank]iMac Ubuntu Pro 24.04 LTS
 * @FileName  T1[40pts].cpp
 * @FilePath  /media/frank/FrankW/_default/_Mine!/Working/code-spaces/czos/CSP-S_Practise/Lesson2/T1[40pts].cpp
 * @Solution  针对特殊性质拿分，40pts极简代码。实际拿分65pts。
 */

// #pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("sample.in","r",stdin);
    // freopen("sample.out","w",stdout);
    // ios::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);
    string s;
    int c;
    cin >> s >> c;
    cout << s[0] << endl;
    // fclose(stdin);
    // fclose(stdout);
    return 0;
}
```

## T1 Code **[100pts]**
```cpp
/*
 * > CPP Code Snippet <
 * > Powered by Microsoft Visual Studio Code <
 *
 * @Author    FrankWKD (wangkedi01)
 * @Date      2025-07-14
 * @Network   "https://oj.czos.cn/contest/problem?id=25573&pid=0&_pjax=%23p0"
 * @License   GNU General Public License 2.0
 * @Platform  [Frank]iMac Ubuntu Pro 24.04 LTS
 * @FileName  T1[100pts].cpp
 * @FilePath  /media/frank/FrankW/_default/_Mine!/Working/code-spaces/czos/CSP-S_Practise/Lesson2/T1[100pts].cpp
 * @Solution  --
 */

// #pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("sample.in","r",stdin);
    // freopen("sample.out","w",stdout);
    // ios::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);
    string s;
    long long c;
    cin >> s >> c;
    if (c == 1)
        cout << s[0];
    else {
        if (s[0] == '1') {
            long long i = 0;
            while (i < min(c - 1, (long long)(s.size() - 1)) and s[i] == '1') i++;
            cout << s[i];
        } else
            cout << s[0];
    }
    // fclose(stdin);
    // fclose(stdout);
    return 0;
}
```
# T2 解密游戏
:::details 点击展开题面
### 题目描述
在一堂趣味盎然的数学课上，老师设计了一个名为 “解密纸条” 的游戏。班上有 $N$ 个同学，每位同学在一张纸条上秘密写下一个数字，要么是 $1$，要么是 $2$。

设第 $i$ 位同学纸条上写的数字为 $P_i$（$P_i$ 的值为 $1$ 或 $2$）。

你的任务是破解所有同学的纸条内容，即确定 $P_1, P_2, \ldots, P_N$ 的值。

老师提供了 $M$ 条解密线索，每条线索描述为：第 $X_i$ 位同学和第 $Y_i$ 位同学纸条上的数字之和加上一个值 $Z_i$ 总和为偶数（即 $P_{X_i} + P_{Y_i} + Z_i$ 是偶数）。

作为游戏的破解者，你可以执行以下操作任意次：选择一位同学，查看他/她纸条上的数字，每次查看需要消耗 $1$ 个单位的时间。

请计算确定所有同学纸条内容的最少总时间。

### 输入
第一行包含两个整数 $N$ 和 $M$，分别表示同学人数和线索数量。

接下来 $M$ 行，每行包含三个整数 $X_i, Y_i, Z_i$，表示一条线索：第 $X_i$ 位同学和第 $Y_i$ 位同学纸条上的数字之和加上 $Z_i$ 为偶数。

### 输出
输出一个整数，表示确定所有同学纸条内容的最少总时间。

### 样例
#### 样例输入 1
```
2 1
1 2 1
```
#### 样例输出 1
```
1
```

#### 样例输入 2
```
6 3
1 2 1
2 3 2
4 5 4
```
#### 样例输出 2
```
3
```

#### 样例输入 3
```
8 6
1 2 3
2 3 5
2 4 6
5 7 8
6 8 2
5 8 3
```
#### 样例输出 3
```
2
```

### 说明
#### 样例 1 说明
有 $2$ 个人，$1$ 个线索，线索指示 $P_1 + P_2 + 1$ 为偶数，因此只需要查看第 $1$ 位同学的纸条或者第 $2$ 位同学的纸条，就可以确定两位同学纸条上的数字了。

### 数据范围
对于 $100\%$ 的数据，满足 $2 \leq N \leq 10^5$，$1 \leq M \leq 10^5$，$1 \leq X_i < Y_i \leq N$，$1 \leq Z_i \leq 100$。

且满足：所有 $(X_i, Y_i)$ 互不相同，输入线索无矛盾，即一定可以解出一组 $P_1, P_2, \ldots, P_N$ 满足所有线索条件。

#### 测试点 特殊性质
| 测试点      | 特殊性质 |
| ----------- | -------- |
| $1 \sim 4$  | $M = 1$  |
| $5 \sim 20$ | 无       |

:::

## T2 Sol
1．对于 $3$ 个数：$P_1 + P_2 + Z_i$，如果他们的和是偶数，且知道 $Z_i$ 的奇偶性，说明就能知道 $P_1 + P_2$ 的奇偶性，此时 $P_1$ 和 $P_2$ 只要知道 $1$ 个数，就能知道另一个数。  

2．考虑更复杂的情况：  
$P_1 + P_2 + Z_1$  
$P_2 + P_3 + Z_2$  
$P_3 + P_4 + Z_3$  

三组数中，看上去每组只要知道一个数就能知道另一个数。  

但其实第 $1$ 组数，如果知道了 $P_1$，$P_2$ 就知道了，这样第 $2$ 组的 $P_3$ 也能推导出来，第 $3$ 组的 $P_4$ 也能推导。  

因此：对于每一组中的 $P_i$ $P_j$，我们可以认为其是一个集合元素，对于一个集合中的元素只要知道一个就能推导出其余数，因此问题转换为求集合的数量。  

## T2 Code
```cpp
/*
 * > CPP Code Snippet <
 * > Powered by Microsoft Visual Studio Code <
 *
 * @Author    FrankWKD (wangkedi01)
 * @Date      2025-07-15
 * @Network   "https://oj.czos.cn/contest/problem?id=25573&pid=1"
 * @License   GNU General Public License 2.0
 * @Platform  [Frank]iMac Ubuntu Pro 24.04 LTS
 * @FileName  T2.cpp
 * @FilePath  /media/frank/FrankW/_default/_Mine!/Working/code-spaces/czos/CSP-S_Practise/Lesson2/T2.cpp
 * @Solution  --
 */

// #pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
int xi, yi, ans, n, m;
int f[1010100];
int find(int x) {
    return f[x] == x ? x : f[x] = find(f[x]);
}
void merge(int x, int y) {
    f[find(x)] = f[find(y)];
}
int main() {
    // freopen("sample.in","r",stdin);
    // freopen("sample.out","w",stdout);
    // ios::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        f[i] = i;
    }
    for (int i = 1; i <= m; i++) {
        int mi;
        cin >> xi >> yi >> mi;
        merge(xi, yi);
    }
    for (int i = 1; i <= n; i++) {
        if (find(f[i]) == i)
            ans++;
    }
    cout << ans << endl;

    // fclose(stdin);
    // fclose(stdout);
    return 0;
}
```

# T3 [CSP-S 2024] 染色
:::details 点击查看题面

### 题目描述

给定一个长度为 $n$ 的正整数数组 $A$，其中所有数从左至右排成一排。

你需要将 $A$ 中的每个数染成红色或蓝色之一，然后按如下方式计算最终得分：

设 $C$ 为长度为 $n$ 的整数数组，对于 $A$ 中的每个数 $A_i$（$1 \leq i \leq n$）：

- 如果 $A_i$ 左侧没有与其同色的数，则令 $C_i = 0$。
- 否则，记其左侧**与其最靠近的同色数**为 $A_j$，若 $A_i = A_j$，则令 $C_i = A_i$，否则令 $C_i = 0$。

你的最终得分为 $C$ 中所有整数的和，即 $\sum \limits_{i=1}^n C_i$。你需要最大化最终得分，请求出最终得分的最大值。

### 输入格式

**本题有多组测试数据。**

输入的第一行包含一个正整数 $T$，表示数据组数。

接下来包含 $T$ 组数据，每组数据的格式如下：

第一行包含一个正整数 $n$，表示数组长度。

第二行包含 $n$ 个正整数 $A_1, A_2, \dots, A_n$，表示数组 $A$ 中的元素。

### 输出格式

对于每组数据：输出一行包含一个非负整数，表示最终得分的最大可能值。

### 输入输出样例 #1

### 输入 #1

```
3
3
1 2 1
4
1 2 3 4
8
3 5 2 5 1 2 1 4
```

### 输出 #1

```
1
0
8
```

### 说明/提示

**【样例 1 解释】**

对于第一组数据，以下为三种可能的染色方案：

1. 将 $A_1, A_2$ 染成红色，将 $A_3$ 染成蓝色（$\red{1}\red{2}\blue{1}$），其得分计算方式如下：
- 对于 $A_1$，由于其左侧没有红色的数，所以 $C_1 = 0$。
- 对于 $A_2$，其左侧与其最靠近的红色数为 $A_1$。由于 $A_1 \neq A_2$，所以 $C_2 = 0$。
- 对于 $A_3$，由于其左侧没有蓝色的数，所以 $C_3 = 0$。    
该方案最终得分为 $C_1 + C_2 + C_3 = 0$。
2. 将 $A_1, A_2, A_3$ 全部染成红色（$\red{121}$），其得分计算方式如下：
- 对于 $A_1$，由于其左侧没有红色的数，所以 $C_1 = 0$。
- 对于 $A_2$，其左侧与其最靠近的红色数为 $A_1$。由于 $A_1 \neq A_2$，所以 $C_2 = 0$。
- 对于 $A_3$，其左侧与其最靠近的红色数为 $A_2$。由于 $A_2 \neq A_3$，所以 $C_3 = 0$。    
该方案最终得分为 $C_1 + C_2 + C_3 = 0$。
3. 将 $A_1, A_3$ 染成红色，将 $A_2$ 染成蓝色（$\red{1}\blue{2}\red{1}$），其得分计算方式如下：
- 对于 $A_1$，由于其左侧没有红色的数，所以 $C_1 = 0$。
- 对于 $A_2$，由于其左侧没有蓝色的数，所以 $C_2 = 0$。
- 对于 $A_3$，其左侧与其最靠近的红色数为 $A_1$。由于 $A_1 = A_3$，所以 $C_3 = A_3 = 1$。    
该方案最终得分为 $C_1 + C_2 + C_3 = 1$。

可以证明，没有染色方案使得最终得分大于 $1$。

对于第二组数据，可以证明，任何染色方案的最终得分都是 $0$。

对于第三组数据，一种最优的染色方案为将 $A_1, A_2, A_4, A_5, A_7$ 染为红色，将 $A_3, A_6, A_8$ 染为蓝色（$\red{35}\blue{2}\red{51}\blue{2}\red{1}\blue{4}$），其对应 $C = [0, 0, 0, 5, 0, 1, 2, 0]$，最终得分为 $8$。

**【样例 2】**

见选手目录下的 color/color2.in 与 color/color2.ans。

**【数据范围】**

对于所有测试数据，保证：$1\leq T\leq 10$，$2\leq n\leq 2\times 10^5$，$1\leq A_i\leq 10^6$。

|   测试点    |         $n$         |    $A_i$    |
| :---------: | :-----------------: | :---------: |
|  $1\sim 4$  |      $\leq 15$      |  $\leq 15$  |
|  $5\sim 7$  |     $\leq 10^2$     | $\leq 10^2$ |
| $8\sim 10$  |     $\leq 2000$     | $\leq 2000$ |
|   $11,12$   | $\leq 2\times 10^4$ | $\leq 10^6$ |
| $13\sim 15$ | $\leq 2\times 10^5$ |  $\leq 10$  |
| $16\sim 20$ | $\leq 2\times 10^5$ | $\leq 10^6$ |

:::

## Sol


题意：有 $N$ 个数，每个数设置为红或者蓝。  

1．如果 $A_i$ 左侧没有同色的数，$C_i=0$。  
2．如果有，找最近的同色的数 $A_j$，如：$A_i=A_j$，$C_i=A_i$，否则 $C_i=0$。  

最终得分 $= C_i$ 的和，求最大得分。  

**20pts：** 枚举每个数颜色取 $1$，和取 $2$ 这两种情况的所有的组合，求每种组合下，分数的最大值。  


### 1．状态定义  

$f[i][0]$：前 $i$ 个数，如果第 $i$ 个数对于答案没有贡献，最大得分。  
$f[i][1]$：前 $i$ 个数，如果第 $i$ 个数对于答案有贡献，最大得分。  

要注意：并不是第 $i$ 个数可以对答案有贡献时（即：左侧有等值的数），产生贡献一定最优。  

比如：$1\ 2\ 3\ 3\ 3\ 2\ 1$，对于第 $6$ 个数，如果要对答案有贡献，那么 $2\ 3\ 3\ 3\ 2$ 必须同色，此时得分 $= 0 + 0 + 0 + 3 + 0 + 1 = 4$ 分。  

而让第 $6$ 个数不产生贡献，答案反而更大，即：染色方案为 $1\ 2\ 3\ 3\ 3\ 2\ 1$，此时得分 $= 0 + 0 + 0 + 3 + 2 + 0 = 5$ 分。  


### 2．状态转移  

(1) 如果第 $i$ 个数对于得分无贡献。  

- 等价于第 $i$ 个数不存在：$f[i][0] = \max(f[i - 1][0], f[i - 1][1]);$  


(2) 如果第 $i$ 个数对于得分有贡献。  

- 此时需满足 $a[i]$ 左侧有和其值相等的数，假设 $a[i]$ 左侧和其值相等的最近的数的位置是 $p$。  

- ![img](https://img2024.cnblogs.com/blog/3594125/202507/3594125-20250716173300658-1875576247.png)  
- 则有：$p$ 和 $i$ 必然同色，且 $p+1 \sim i-1$，必然和 $p/i$ 异色。  

- 则到 $i$ 为止的最大得分可以分为 3 部分讨论。  

  - 第一部分：第 $i$ 个数的贡献，就是 $a[i]$。  

  - 第二部分：$p+2 \sim i-1$ 的贡献，这部分只能是每个数 $==$ 其左侧的数，才有贡献，可以通过前缀和求区间和维护出来。  

  - 第三部分：$1 \sim p+1$ 的贡献 $= \max(f[p + 1][0], f[p + 1][1]);$  


### 为什么有贡献时，一定是从最近的等值的数转移过来最优？  
![img](https://img2024.cnblogs.com/blog/3594125/202507/3594125-20250716173355764-1011999790.png)

设 $i$ 的左侧有多个和其值相等的点，比如有 $p$ 和 $p'$，如果从 $p'$ 转移过来，导致从 $p'+1 \sim p+1$ 这段必须只能是同色，而同色只是所有颜色排列的情况之一，讨论了更少的情况不可能产生更优解。

:::danger 

- 多测问题：  
  - 1．每组数据计算前：将需要清空的变量清空。$☆☆☆☆☆$  
  - 2．输出格式一定不能错!!!每个输出都要检查!!!  
  - 使用桶排序等需要使用 $a_i$ 的取值范围!例如 `T3 Code` 里面的 `last` 数组。必须考虑到 $a_i$ 的取值范围，否则会爆下标 RE.

:::

:::tip

在 `windows` 下和 `linux` 下比较两个文件的不同：  

`Windows`:  
```
fc 1.out t1.out  
fc 1.out t1.out > result.txt  
fc /N file1.txt file2.txt > differences.txt  显示行号  
```

`Linux`: `diff` 指令  

:::

:::warning

特别注意：`fc` 指令比较时，要求严格一致，如果我们输出的内容每一行结尾多了空格，也认为是不同的。另外，如果题目给的测评数据 `ans` 文件是 `linux` 下创造的，但我们是在 `windows` 下生成的 `.out`，换行符是不一样，`fc` 也会比较出来!!!

:::

## T3 Code
```cpp
/*
 * > CPP Code Snippet <
 * > Powered by Microsoft Visual Studio Code <
 *
 * @Author    FrankWKD (wangkedi01)
 * @Date      2025-07-16
 * @Network   "https://oj.czos.cn/contest/problem?id=25573&pid=2"
 * @License   GNU General Public License 2.0
 * @Platform  [Frank]iMac Ubuntu Pro 24.04 LTS
 * @FileName  T3.cpp
 * @FilePath  /media/frank/FrankW/_default/_Mine!/Working/code-spaces/czos/CSP-S_Practise/Lesson2/T3.cpp
 * @Solution  --
 */

// #pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10;
int a[N], b[N], f[N][2], n, t, last[1000010];  // warning: last
signed main() {
    // freopen("sample.in","r",stdin);
    // freopen("sample.out","w",stdout);
    // ios::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        memset(last, 0, sizeof last);
        memset(b, 0, sizeof b);
        memset(f, 0, sizeof f);
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++) {
            if (a[i] == a[i - 1])
                b[i] = a[i] + b[i - 1];
            else
                b[i] = b[i - 1];
        }
        for (int i = 1; i <= n; i++) {
            f[i][0] = max(f[i - 1][1], f[i - 1][0]);
            if (last[a[i]] > 0) {
                f[i][1] = a[i] + max(f[last[a[i]] + 1][0], f[last[a[i]] + 1][1]) + ((last[a[i]] + 1 < i - 1) ? (b[i - 1] - b[last[a[i]] + 1]) : 0);
            }
            last[a[i]] = i;
        }
        cout << max(f[n][0], f[n][1]) << endl;
    }
    // fclose(stdin);
    // fclose(stdout);
    return 0;
}
```