# 2025年东师附中B层春季测试1考试总结
###### Designed By Lwj54joy AT 2025-03-01
###### 本文将遵守GNU GPL2.0开源协议.
## 概述
总分：$310/400$ 
改题分数：$400/400$
Rank：$5/50$  
期望排名：$10/50$  
评价：100/100
#### [$比赛Link[Accoders]$](http://www.accoders.com/contest.php?cid=5052)
----

## $T1-循环小数$
- [x] 已改？   
Score：$WA$ $|$ $92/100$   
- ### $总结：$ 非常简单的一道数学,没难度

- ### $做法：$ 注意: 要考虑所求位数还没到循环节的时候,Hack数据: `input: 3 3.993(121)` ; `output: 3`
  
- ### $T1-ExampleCode$
```cpp
#include<bits/stdc++.h>
using namespace std;
string rround;
int n;
string org;
bool f = 0, noww = 0;
int main() {

	string s;
	cin >> n >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '.') noww = 1;
		else if (s[i] == '(') f = 1;
		else if (s[i] == ')') f = 0;
		else {
			if (!f and noww) org += s[i];
			if (f and noww) rround = rround + to_string(s[i]-'0');
		}
	}
	if(n <= org.size()) cout<<org[n-1];
	else if((n-org.size())%rround.size() == 0) cout<<rround[rround.size()-1];
	else cout<<rround[(n-org.size())%rround.size()-1];
	
	//1.111(23) 6
	return 0;
}
```
## $T2-usaco-1.2.1-Milking Cows-挤牛奶$
- [LuoguLink](https://www.luogu.com.cn/problem/P1204)
- [x] 已改？   
- Score：$AC$ $|$ $100/100$   
- ### $总结：$ 
简单算法题.但是有好多细节:例如每个时间节点表示的是一个区间...需要用printf.
- ### $做法：$ 
数据范围很小.对于每个区间直接差分到 $ans$ 数组里面的区间内,然后统一计算答案.
- ### $T2-ExampleCode$
```cpp
#include<bits/stdc++.h>
using namespace std;
const int N = 1010, MOD = 1e9+7;
int ans[1000010];//桶被覆盖代表前端线段被覆盖。
int n;
struct timetable {
	int start, end;
} a[5010];
int maxxt = 0, minnt = INT_MAX;
int max_long_N, max_long_Y;
int long_N, long_Y;
bool contin_N, contin_Y;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].start >> a[i].end;
		ans[a[i].start]++, ans[a[i].end]--;
		maxxt = max(maxxt, a[i].end), minnt = min(minnt, a[i].start);
	}
	for (int i = minnt; i <= maxxt; i++) ans[i] += ans[i - 1];

	if (ans[minnt] == 0) contin_N = 1;
	else contin_Y = 1;
	for (int i = minnt; i <= maxxt; i++) {
		if (contin_N) {
			if (ans[i] != 0) {
				contin_Y = 1;
				contin_N = 0;
				long_Y = 1;
				max_long_N = max(max_long_N, long_N);
				long_N = 0;
			} else {
				long_N++;
				max_long_N = max(max_long_N, long_N);
			}
		} else if (contin_Y) {
			if (ans[i] == 0) {
				contin_N = 1;
				contin_Y = 0;
				long_N = 1;
				max_long_Y = max(max_long_Y,long_Y);
				long_Y = 0;
			}else{
				long_Y++;
				max_long_Y = max(max_long_Y,long_Y);
			}
		}
	}
	printf("%d %d",max_long_Y,max_long_N);//Important!!

	return 0;
}
```
## $T3-$
- [x] 已改？   
Score：$AC$ $|$ $100/100$
- ### $总结：$
调了好长时间.有好多细节,因为我做的递归(dfs)枚举是边枚举边计算,所以很难.

- ### $做法：$
一边枚举一边计算答案,答案和当前字符串等重要信息被作为参数保存.细节详见注释
- ### $T3-ExampleCode$
```cpp
#include<bits/stdc++.h>
using namespace std;
//笑死这数据范围，顺序是：' '->'+'->'-' , 调了半个点才发现和为零
int a[100];
int n;
void fun(string s, int ans, int i, int pre,char op) { //pre: 前面的累加值
	// Hack数据： 1-2 3 4 待定：5 ，那么就应该减去234再加上2345！！！
	//cout << s << endl;
	if (i > n) {
		if(ans == 0) cout << s <<endl;
		return ;
	}
	if(op == '-'){
		fun(s + " " + to_string(i), ans + pre - (10 * pre + i), i + 1, pre * 10 + i,op);//op需要继承
	}else{
		fun(s + " " + to_string(i), ans - pre + (10 * pre + i), i + 1, pre * 10 + i,op);//op需要继承
	}
	
	fun(s + '+' + to_string(i), ans + i, i + 1, i,'+');
	fun(s + '-' + to_string(i), ans - i, i + 1, i,'-');
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) a[i] = i;
	fun("1", 1, 2, 1,'+');
	return 0;
}
```
## $T4-[NOIP2004]虫食算$
- [ ] 已改？   
Score：$WA$ $|$ $0/100$   
- ### $总结：$ 
一片空白...复杂度根本不够啊算法也没有适合的,其实这题正解是高斯消元,但是蒟蒻翻边全网也没找到几个...更是一个也没看懂💦💦💦
- ### $做法(Powered With Doubao)：$ 
以下是针对 [NOIP 2004 提高组] 虫食算的详细分析与 C++ 代码实现。

### 题目描述
所谓虫食算，就是原先的算式中有一部分被虫子啃掉了，需要我们根据剩下的数字来判定被啃掉的字母所代表的数字。本题给定一个 $N$ 进制的加法算式，其中所有数字被字母替代，相同字母代表相同数字，不同字母代表不同数字。要求找出满足该算式的唯一解，若有多个解或无解则输出 `NO`。

### 解题思路
- **搜索算法**：使用全排列枚举所有可能的字母到数字的映射关系，因为每个字母对应一个不同的数字，所以可以通过枚举所有 $N$ 个数字的排列来尝试所有可能的赋值。
- **剪枝优化**：在搜索过程中，根据当前已经确定的部分结果进行判断，如果发现当前的赋值无法满足算式，就提前终止搜索，减少不必要的计算。
在解决 [NOIP 2004 提高组] 虫食算问题时，剪枝是优化搜索效率的关键，以下是几种常见且有效的剪枝策略：

### 1. 最高位无进位剪枝
在一个 $N$ 进制的加法算式中，两个加数的最高位相加不能产生进位到第 $N + 1$ 位（因为结果也是 $N$ 位）。例如，对于算式 `ABC + DEF = GHI`，在确定字母对应的数字时，如果当前尝试给最高位字母赋值，使得 `A + D >= N`，那么这种赋值肯定是不合理的，因为这会导致结果变成 $N + 1$ 位，不符合题目要求，所以可以直接跳过这种情况。

在代码实现中，当搜索到最高位时可以添加如下判断：
```cpp
if (pos == n - 1 && (num[a[pos] - 'A'] + num[b[pos] - 'A']) >= n) {
    used[i] = false;
    continue;
}
```
这里的 `pos == n - 1` 表示正在处理最高位，`num[a[pos] - 'A'] + num[b[pos] - 'A'] >= n` 表示最高位相加会产生进位，此时就跳过当前的赋值尝试。

### 2. 从右向左计算过程中的进位剪枝
在计算加法算式时，我们是从右向左逐位计算的。在搜索过程中，当我们已经确定了部分低位的数字后，可以根据这些信息判断当前高位的赋值是否合理。具体来说，如果当前位的计算结果不符合进位规则，就可以提前终止当前搜索分支。

例如，在计算第 $i$ 位时，设两个加数第 $i$ 位对应的数字为 $x$ 和 $y$，和的第 $i$ 位对应的数字为 $z$，进位为 $carry$，如果 $(x + y+ carry)\bmod N\neq z$，那么当前的赋值是不满足算式的，可以直接返回 `false`。

```cpp
bool check() {
    int carry = 0;
    for (int i = n - 1; i >= 0; i--) {
        int x = num[a[i] - 'A'];
        int y = num[b[i] - 'A'];
        int z = num[c[i] - 'A'];
        if ((x + y + carry) % n != z) return false;
        carry = (x + y + carry) / n;
    }
    return carry == 0;
}
```

### 3. 已经确定的字母数字唯一性剪枝
在搜索过程中，如果某个字母已经被赋予了一个数字，那么在后续的搜索中，这个字母对应的数字就不能再改变。并且在给其他字母赋值时，不能使用已经被占用的数字。通过使用一个 `used` 数组来标记哪些数字已经被使用，避免重复使用同一个数字。

```cpp
bool used[MAXN];  // 标记数字是否已经被使用

// 在搜索函数中
for (int i = n - 1; i >= 0; i--) {
    if (!used[i]) {
        num[pos] = i;
        used[i] = true;
        // 进行搜索操作
        if (dfs(pos + 1)) return true;
        used[i] = false;  // 回溯
    }
}
```

### 4. 提前终止无解情况
如果在搜索过程中，发现某些字母无论赋予什么数字都无法满足算式的条件，那么可以提前终止当前搜索分支。例如，在某个位置上，根据已经确定的数字和进位情况，发现剩下的字母无论怎么取值都无法使等式成立，就可以直接放弃这个分支。这种剪枝需要根据具体的算式和已确定的信息进行灵活判断。

通过以上这些剪枝策略，可以大大减少不必要的搜索，提高算法的效率，从而在合理的时间内找到虫食算的解。 
- ### $T4-ExampleCode$
下面是一份使用 C++ 解决 [NOIP 2004 提高组] 虫食算问题的完整代码，代码中使用了深度优先搜索（DFS）结合剪枝优化的方法来求解。

```cpp
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int MAXN = 26;
int n;
string a, b, c;
int num[MAXN];  // 存储每个字母对应的数字，num[i] 表示字母 'A' + i 对应的数字
bool used[MAXN];  // 标记数字是否已经被使用
bool found = false;  // 标记是否已经找到解

// 检查当前的数字赋值是否满足算式
bool check() {
    int carry = 0;
    for (int i = n - 1; i >= 0; i--) {
        int x = num[a[i] - 'A'];
        int y = num[b[i] - 'A'];
        int z = num[c[i] - 'A'];
        if (x == -1 || y == -1 || z == -1) continue;  // 如果有字母还未赋值，跳过
        if ((x + y + carry) % n != z) return false;
        carry = (x + y + carry) / n;
    }
    if (carry != 0) return false;  // 最后还有进位，不满足条件
    return true;
}

// 深度优先搜索，枚举所有可能的数字排列
void dfs(int pos) {
    if (found) return;  // 如果已经找到解，直接返回
    if (pos == n) {
        if (check()) {
            found = true;
            for (int i = 0; i < n; i++) {
                if (i > 0) cout << " ";
                cout << num[i];
            }
            cout << endl;
        }
        return;
    }
    for (int i = n - 1; i >= 0; i--) {
        if (!used[i]) {
            num[pos] = i;
            used[i] = true;
            // 剪枝：最高位无进位
            if (pos == n - 1 && (num[a[pos] - 'A'] + num[b[pos] - 'A']) >= n) {
                used[i] = false;
                continue;
            }
            // 剪枝：从右向左计算过程中的进位剪枝
            if (pos < n - 1) {
                int j = n - 1;
                int carry = 0;
                bool valid = true;
                while (j > pos) {
                    int x = num[a[j] - 'A'];
                    int y = num[b[j] - 'A'];
                    int z = num[c[j] - 'A'];
                    if (x != -1 && y != -1 && z != -1) {
                        if ((x + y + carry) % n != z) {
                            valid = false;
                            break;
                        }
                        carry = (x + y + carry) / n;
                    }
                    j--;
                }
                if (!valid) {
                    used[i] = false;
                    continue;
                }
            }
            dfs(pos + 1);
            used[i] = false;
        }
    }
}

int main() {
    cin >> n;
    cin >> a >> b >> c;
    // 初始化 num 数组为 -1，表示还未赋值
    for (int i = 0; i < n; i++) {
        num[i] = -1;
    }
    dfs(0);
    if (!found) {
        cout << "NO" << endl;
    }
    return 0;
}
```

### 代码说明：
1. **输入处理**：
    - 首先读取进制数 `n` 和三个字符串 `a`、`b`、`c`，分别代表加法算式的两个加数和结果。
    - 初始化 `num` 数组为 -1，表示每个字母还未被赋予数字。

2. **`check` 函数**：
    - 从右向左逐位检查加法算式是否成立。
    - 对于每一位，计算两个加数对应位的数字之和加上进位，判断是否等于结果对应位的数字。
    - 如果有字母还未赋值，跳过该位的检查。
    - 最后检查是否还有进位，如果有则不满足条件。

3. **`dfs` 函数**：
    - 使用深度优先搜索枚举所有可能的字母到数字的映射关系。
    - 当 `pos` 等于 `n` 时，表示已经完成了所有字母的赋值，调用 `check` 函数检查是否满足算式。
    - 在赋值过程中，使用 `used` 数组标记数字是否已经被使用，避免重复使用。
    - 采用了两种剪枝策略：
        - 最高位无进位剪枝：如果最高位相加会产生进位，跳过当前赋值。
        - 从右向左计算过程中的进位剪枝：在赋值过程中，根据已经确定的低位数字检查是否满足进位规则，如果不满足则跳过当前赋值。

4. **输出结果**：
    - 如果找到满足条件的解，输出每个字母对应的数字。
    - 如果没有找到解，输出 `NO`。

这个代码通过深度优先搜索和剪枝优化，在合理的时间内求解虫食算问题。
----
----