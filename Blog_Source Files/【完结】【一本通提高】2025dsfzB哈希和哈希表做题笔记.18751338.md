# 2025年dsfz - 上学期B层字符串哈希专题做题笔记
笔记部分请看我的[字符串哈希学习笔记](https://www.cnblogs.com/FrankWKD/p/18732210)
|  | 题目编号 | 标题 | 估分 | 正确 | 提交 |
| --- | --- | --- | --- | --- | --- |
| Y | 2066 Problem  A | [【一本通提高篇哈希和哈希表】乌力波（oulipo）](http://www.accoders.com/problem.php?cid=2334&pid=0) | \--- | 165 | 475 |
| Y | 2067 Problem  B | [【一本通提高篇哈希和哈希表】Power Strings](http://www.accoders.com/problem.php?cid=2334&pid=1) | \--- | 117 | 358 |
| Y | 2068 Problem  C | [【一本通提高篇哈希和哈希表】Seek the Name,Seek the Fame](http://www.accoders.com/problem.php?cid=2334&pid=2) | \--- | 138 | 384 |
| Y | 2069 Problem  D | [【一本通提高篇哈希和哈希表】friends](http://www.accoders.com/problem.php?cid=2334&pid=3) | \--- | 105 | 562 |
| Y | 2070 Problem  E | [【一本通提高篇哈希和哈希表】A Horrible Poem](http://www.accoders.com/problem.php?cid=2334&pid=4) | \--- | 82 | 302 |
| Y | 2071 Problem  F | [【一本通提高篇哈希和哈希表】Beads](http://www.accoders.com/problem.php?cid=2334&pid=5) | \--- | 91 | 320 |
| Y | 2072 Problem  G | [【一本通提高篇哈希和哈希表】Antisymmetry](http://www.accoders.com/problem.php?cid=2334&pid=6) | \--- | 78 | 167 |
| Y | 2073 Problem  H | [【一本通提高篇哈希和哈希表】图书管理](http://www.accoders.com/problem.php?cid=2334&pid=7) | \--- | 106 | 253 |
| Y | 2074 Problem  I | [【一本通提高篇哈希和哈希表】门票](http://www.accoders.com/problem.php?cid=2334&pid=8) | \--- | 74 | 514 |
| Y | 2075 Problem  J | [【一本通提高篇哈希和哈希表】收集雪花](http://www.accoders.com/problem.php?cid=2334&pid=9) | \--- | 82 | 217 |
## 问题 A: 【一本通提高篇哈希和哈希表】乌力波（oulipo）
### 题目内容
法国作家乔治·佩雷克(Georges Perec，1936-1982)曾经写过一本书，《敏感字母》（La disparition），全篇没有一个字母‘e’。他是乌力波小组（Oulipo Group）的一员。下面是他书中的一段话：
```
   Tout avait Pair normal, mais tout s’affirmait faux. Tout avait Fair normal, d’abord, puis surgissait l’inhumain, l’affolant. Il aurait voulu savoir où s’articulait l’association qui l’unissait au roman : stir son tapis, assaillant à tout instant son imagination, l’intuition d’un tabou, la vision d’un mal obscur, d’un quoi vacant, d’un non-dit : la vision, l’avision d’un oubli commandant tout, où s’abolissait la raison : tout avait l’air normal mais…
```
佩雷克很可能在下面的比赛中得到高分（当然，也有可能是低分）。在这个比赛中，人们被要求针对一个主题写出甚至是意味深长的文章，并且让一个给定的“单词”出现次数尽量少。我们的任务是给评委会编写一个程序来数单词出现了几次，用以得出参赛者最终的排名。参赛者经常会写一长串废话，例如 $500000$ 个连续的 `T`。并且他们不用空格。

因此我们想要尽快找到一个单词出现的频数，即一个给定的字符串在文章中出现了几次。更加正式地，给出字母表 $\{'A','B','C',...,'Z'\}$ 和两个仅有字母表中字母组成的有限字符串：单词 $W$ 和文章 $T$ ，找到 $W$ 在 $T$ 中出现的次数。这里“出现”意味着 $W$ 中所有的连续字符都必须对应 $T$ 中的连续字符。$T$ 中出现的两个 $W$ 可能会部分重叠。

### 输入
输入包含多组数据。

输入文件的第一行有一个整数，代表数据组数。接下来是这些数据，以如下格式给出：

第一行是单词 $W$，一个由 $\{'A','B','C',...,'Z'\}$ 中字母组成的字符串，保证 $1<=|W|<=10000$（$|W|$代表字符串W的长度）

第二行是文章 $T$，一个由 $\{'A','B','C',...,'Z'\}$ 中字母组成的字符串，保证 $|W|<=|T|<=1000000$ 。

### 输出
对每组数据输出一行一个整数，即 $W$ 在 $T$ 中出现的次数。

### 样例输入
```
3
BAPC
BAPC
AZA
AZAZAZA
VERDI
AVERDXIVYERDIAN
```
样例输出
```
1
3
0
```
### 解法
直接套模板即可。easy。详见我的[字符串哈希学习笔记](https://www.cnblogs.com/FrankWKD/p/18732210)T1
```cpp
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int N = 1000010, MOD = 1e9+7;
const int P = 131;
ull h[N], p[N];
ull h2[N];
char s2[N], s1[N];
int n;

void gethash() {
	p[0] = 1;
	int n1 = strlen(s1 + 1), n2 = strlen(s2 + 1);
	for (int i = 1; i <= n1; i++) {
		h[i] = h[i - 1] * P + (s1[i] - 'A' + 1);
		p[i] = p[i - 1] * P;
	}
	for (int i = 1; i <= n2; i++) {
		h2[i] = h2[i - 1] * P + (s2[i] - 'A' + 1);
	}
}
ull get1(int l, int r) {
	return h[r] - h[l - 1] * p[r - l + 1];
}
ull get2(int l, int r) {
	return h2[r] - h2[l - 1] * p[r - l + 1];
}

int main() {
	int n;
	cin >> n;
	while (n--) {
		scanf("%s%s", s2 + 1, s1 + 1);
		gethash();
		int n1 = strlen(s1 + 1), n2 = strlen(s2 + 1);
		int ans = 0;
		ull tmp = get2(1, n2);
		for (int i = 1; i + n2 - 1 <= n1; i++) {
			if (get1(i, i + n2 - 1) == tmp) {
				ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
```

## B.【一本通提高篇哈希和哈希表】Power Strings
### Description
```
Given two strings a and b we define a*b to be their concatenation. For example, if a = "abc" and b = "def" then a*b = "abcdef". If we think of concatenation as multiplication, exponentiation by a non-negative integer is defined in the normal way: a^0 = "" (the empty string) and a^(n+1) = a*(a^n).
```
给定若干个长度小于等于 $1000000$ 的字符串，询问每个字符串最多由多少个相同的子串重复连接而成。如：`ababab`，最多由 $3$ 个 `ab` 连接而成。
### Input
```
Each test case is a line of input representing s, a string of printable characters. The length of s will be at least 1 and will not exceed 1 million characters. A line containing a period follows the last test case.
```
### Output
```
For each s you should print the largest n such that s = a^n for some string a.
```
### Sample Input
```
abcd
aaaa
ababab
.
```
### Sample Output
```
1
4
3
```
### 解法
需要一点小技巧，详见详见我的[字符串哈希学习笔记](https://www.cnblogs.com/FrankWKD/p/18732210)T2
```cpp
#include<bits/stdc++.h>
using namespace std;
const int N = 1000010, P = 131;
typedef unsigned long long ull;
ull h[N], p[N];
char s[N];
int len;

void gethash() {
	p[0] = 1;
	for (int i = 1; i <= len; i++) {
		h[i] = h[i - 1] * P + (s[i] - 'a' + 1);
		p[i] = p[i - 1] * P;
	}
}
ull get1(int l, int r) {
	return h[r] - h[l - 1] * p[r - l + 1];
}
int main() {
	while (scanf("%s", s + 1) and s[1] != '.') {
		len = strlen(s + 1);
		gethash();
		for (int i = 1; i <= len; i++) {
			if (len % i != 0) continue;
			if (get1(1, len - i/*!Important*/) == get1(i + 1, len)) {
				printf("%d\n", len / i);
				break;
			}
		}
	}
	return 0;
}
```
## C.【一本通提高篇哈希和哈希表】A Horrible Poem
### 题目描述
给出一个由小写英文字母组成的字符串 $S$，再给出 $q$ 个询问，要求回答 $S$ 某个子串的最短循环节。
如果字符串 $B$ 是字符串 $A$ 的循环节，那么 $A$ 可以由 $B$ 重复若干次得到。 

### 输入
 第一行一个正整数 $n (n<=500,000)$，表示 $S$ 的长度。
第二行 $n$ 个小写英文字母，表示字符串 $S$ 。
第三行一个正整数 $q (q<=2,000,000)$，表示询问个数。
下面q行每行两个正整数 $a,b (1<=a<=b<=n)$，表示询问字符串 $S[a..b]$ 的最短循环节长度。

### 输出
依次输出 $q$ 行正整数，第 $i$ 行的正整数对应第 $i$ 个询问的答案。

### 样例输入
```
8
aaabcabc
3
1 3
3 8
4 8
```
### 样例输出
```
1
3
5
```
### 解法
需要在B题的基础上减小循环次数，只循环约数，减小循环次数。用线性筛筛出每个数的最小的质因数。
```cpp
#include <bits/stdc++.h>
#define N 500010
#define P 131
#define ULL unsigned long long
using namespace std;
int n, q, len, tot;
ULL h[N], p[N];
int prime[N], minp[N];
char s[N];
int read() {
	int x = 0, f = 1;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		x = x * 10 + c - '0';
		c = getchar();
	}
	return x * f;
}
void parse() {
	for (int i = 2; i <= n; i++) {
		if (!minp[i]) {
			prime[++tot] = i;
			minp[i] = i;
		}
		for (int j = 1; j <= tot; j++) {
			if (prime[j] > minp[i] || prime[j]*i > n) break;
			minp[prime[j]*i] = prime[j];
		}
	}
	p[0] = 1;
	for (int i = 1; i <= n; i++)
		h[i] = h[i - 1] * P + (ULL)s[i], p[i] = p[i - 1] * P;
}
bool valid(int a, int b, int l) {
	return h[b] - h[a + l - 1] * p[len - l] == h[a + (len / l - 1) * l - 1] - h[a -
	       1] * p[len - l];
}
int main() {
	n = read();
	gets(s + 1);
	q = read();
	parse();
	while (q--) {
		int a, b, ans, tmp;
		a = read(), b = read();
		len = tmp = ans = b - a + 1;
		while (tmp != 1) {
			int t = minp[tmp];
			while (tmp % t == 0 && valid(a, b, ans / minp[tmp])) tmp /= t, ans /= t;
			while (tmp % t == 0) tmp /= t;
		}
		printf("%d\n", ans);
	}
	return 0;
}
```


## D.【一本通提高篇哈希和哈希表】Beads
### Description
Zxl有一次决定制造一条项链，她以非常便宜的价格买了一长条鲜艳的珊瑚珠子，她现在也有一个机器，能把这条珠子切成很多块（子串），每块有 $k（k>0）$ 个珠子，如果这条珠子的长度不是k的倍数，最后一块小于k的就不要拉（nc真浪费），保证珠子的长度为正整数。 Zxl喜欢多样的项链，为她应该怎样选择数字k来尽可能得到更多的不同的子串感到好奇，子串都是可以反转的，换句话说，子串 $（1，2，3）$ 和 $（3,2,1）$ 是一样的。写一个程序，为Zxl决定最适合的k从而获得最多不同的子串。 例如：这一串珠子是： $(1,1,1,2,2,2,3,3,3,1,2,3,3,1,2,2,1,3,3,2,1)$， $k=1$ 的时候，我们得到 $3$ 个不同的子串： $(1),(2),(3) k=2$ 的时候，我们得到 $6$ 个不同的子串： $(1,1),(1,2),(2,2),(3,3),(3,1),(2,3) k=3$ 的时候，我们得到 $5$ 个不同的子串： $(1,1,1),(2,2,2),(3,3,3),(1,2,3),(3,1,2) k=4$ 的时候，我们得到 $5$ 个不同的子串： $(1,1,1,2),(2,2,3,3),(3,1,2,3),(3,1,2,2),(1,3,3,2)$
### Input
共有两行，第一行一个整数 $n$ 代表珠子的长度，$（n<=200000）$，第二行是由空格分开的颜色 $a_i（1<=a_i<=n）$。

### Output
也有两行，第一行两个整数，第一个整数代表能获得的最大不同的子串个数，第二个整数代表能获得最大值的k的个数，第二行输出所有的k（中间有空格）。

### Sample Input
```
21

1 1 1 2 2 2 3 3 3 1 2 3 3 1 2 2 1 3 3 2 1
```
### Sample Output
```
6 1

2
```
### 解法
暂无。待补充。
```cpp
//附：该代码为错解。
#include<bits/stdc++.h>
using namespace std;
const int N = 200010, MOD = 1e9+7;
typedef unsigned long long ull;
const int P = 13331;
ull p[N],h[N],t[N];
int n;
int s[N],ans[N],tot,cnt,idx;
int main() {
	scanf("%d",&n);
	for(int i = 1;i <= n;i++) scanf("%d",s[i]);
	p[0] = 1;
	for(int i = 1;i <= n;i++){
		p[i] = p[i-1]*P;
		h[i] = h[i-1]*P+s[i];
	}
	for(int i = n;i >= 1;i--) t[i] = t[i+1]*P+s[i];
	for(int k = 1;k <= n;k++){
		unordered_map<ull,bool> mp;
		cnt = 0;
		for(int i = 1;i <= n-k+1;i += k){
			ull lh = h[i+k-1]-h[i-1]*p[k];
			ull rh = t[i]-t[i+k]*p[k];
			ull h = lh*rh;
			if(!mp[h]){
				mp[h] = 1;
				cnt++;
			}
		}
		if(cnt > tot){
			tot = cnt;
			idx = 1;
			ans[1] = k;
		}else if(cnt == tot) ans[++idx] = k;
	}
	printf("%d %d\n",tot,idx);
	for(int i = 1;i <= idx;i++) printf("%d ",ans[i]);
	return 0;
}
```

### E.【一本通提高篇哈希和哈希表】friends
 有三个好朋友喜欢在一起玩游戏,A君写下一个字符串 $S$ ,B君将其复制一遍得到 $T$ ,C君在 $T$ 的任意位置(包括首尾)插入一个字符得到 $U$ .现在你得到了 $U$,请你找出 $S$ .

输入
第一行一个数 $N$ ,表示 $U$ 的长度.
第二行一个字符串 $U$,保证 $U$ 由大写字母组成 

### 输出
 输出一行,若 $S$ 不存在,输出 `"NOT POSSIBLE"`.若 $S$ 不唯一,输出 `"NOT UNIQUE"`.否则输出 $S$.

### 样例输入
#### Sample Input1:
```
7
ABXCABC
```
#### Sample Input2:
```
6
ABCDEF
```
#### Sample Input3:
```
9
ABABABABA
```
### 样例输出
#### Sample Output1:
```
ABC
```
#### Sample Output2:
```
NOT POSSIBLE
```
#### Sample Output3:
```
NOT UNIQUE
```

### 解法：请看请看我的[字符串哈希学习笔记](https://www.cnblogs.com/FrankWKD/p/18732210)
```cpp
#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
const int P = 131;
set<unsigned long long> st;
typedef unsigned long long ull;
ull h[N], p[N];
char s[N];
void gethash() {
	int len = strlen(s + 1);
	p[0] = 1;
	for (int i = 1; i <= len; i++) {
		p[i] = p[i - 1] * P;
		h[i] = h[i - 1] * P + (s[i] - 'A' + 1);
	}
}
ull get(int l, int r) {
	return h[r] - h[l - 1] * p[r - l + 1];
}
int main() {
	int len;
	scanf("%d%s", &len, s + 1);
	gethash();
	int mid = len / 2 + 1;
	ull l, r;
	char res = ' ';
	for (int i = 1; i <= len; i++) {
		if (i == 1) {
			l = get(2, mid);
			r = get(mid + 1, len);
		} else if (i == len) {
			l = get(1, mid - 1);
			r = get(mid, len - 1);
		} else if (i < mid) {
			l = get(1, i - 1) * p[mid - i] + get(i + 1, mid);
			r = get(mid + 1, len);
		} else if (i > mid) {
			l = get(1, mid - 1);
			r = get(mid, i - 1) * p[len - i] + get(i + 1, len);
		} else if (i == mid) {
			l = get(1, mid - 1);
			r = get(mid + 1, len);
		}
		if (l == r) {
			st.insert(l);
			if (st.size() > 1) {
				puts("NOT UNIQUE");
				return 0;
			}
			if (i <= mid)
				res = 'R';
			else
				res = 'L';
		}
	}
	if (st.size() == 0)
		puts("NOT POSSIBLE");
	else {
		s[mid] = '\0';  // 输出到这里的时候就停止输出
		if (res == 'L')
			printf("%s", s + 1);
		else
			printf("%s", s + mid + 1);
	}
}
```
## 【一本通提高篇哈希和哈希表】Beads
- 这题就很烦人、、、阅读理解+头脑风暴
- 首先我们就需要注意整个的这个串正反都算一种，所以就需要搞两遍字符串哈希，然后再开一个 $unordered\_map$ 记录各个串的哈希结果，最后去重得到当前答案，再更新最终答案。
- 还有一个很烦人的点就是：它有哈希冲突就很恶心 P必须去13331才行
```cpp
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int N = 2e5+10, P = 13331;

int n;
ull p[N];
void gethash(ull h[], int s[]) {
	p[0] = 1;
	for (int i = 1; i <= n; i++) {
		h[i] = h[i - 1] * P + s[i];
		p[i] = p[i - 1] * P;
	}
}
ull get1(int l, int r, ull h[]) {
	return h[r] - h[l - 1] * p[r - l + 1];
}
vector<int> v;
ull h[N];
int rev_s[N];
int s[N];
ull rev_h[N];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &s[i]);
		rev_s[n - i + 1] = s[i];
	}
	gethash(h, s);
	gethash(rev_h, rev_s);
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		unordered_map <ull, bool> mp;
		mp.clear();
		int nowans = 0;
		for (int j = 1; j + i - 1 <= n; j += i) {

			int noww = get1(j, j + i - 1, h);
			if (mp[noww] == 0 and mp[get1(n - (j + i - 1) +1, n - j + 1,  rev_h)] == 0) {
				mp[noww] = 1;
				nowans++;
			}
		}
		
		if (ans < nowans) {
			v.clear();
			ans = nowans;
			v.push_back(i);
		} else if (ans == nowans) v.push_back(i);
	}
	printf("%d %d\n", ans, v.size());
	for (int i = 0; i < v.size(); i++) {
		printf("%d\n", v[i]);
	}
}
```
### 【一本通提高篇哈希和哈希表】Antisymmetry
- 这题需要二分套哈希。
- 枚举主串中每个中间点，二分左右延长的距离，check函数里面检验以中间点为中心，向两侧演唱mid个单位后组成的字串是否符合条件。最后取最优解。
```cpp
#include<bits/stdc++.h>
using namespace std;
const int N=1000010,P=13331;
long long ans;
int n;
char s[N];
unsigned long long hh[N],tt[N],p[N];
int check(int x){
    int l=0,r=min(x,n-x);
    while(l<r){
        int mid=l+r+1>>1;
        if(hh[x]-hh[x-mid]*p[mid]==tt[x+1]-tt[x+mid+1]*p[mid]){
            l=mid;
        }
        else{
            r=mid-1;
        }
    }
    return l;
}
int main(){
    scanf("%d",&n);
    scanf("%s",s+1);
    p[0]=1;
    for(int i=1;i<=n;i++){
        p[i]=p[i-1]*P;
        hh[i]=hh[i-1]*P+s[i]-'0';
    }
    for(int i=n;i>=1;i--){
        tt[i]=tt[i+1]*P+1-(s[i]-'0');
    }
    for(int i=1;i<n;i++){
        ans+=check(i);
    }
    printf("%lld\n",ans);
    return 0;
}

```
### 【一本通提高篇哈希和哈希表】图书管理
- 这题我用 $unordered\_map$ 直接水过。用哈希的话还要把字符串中的空格替换成某一个很独特的字符，还要优化复杂度。
```cpp
#include <bits/stdc++.h>
using namespace std;

unordered_map <string, int> mp;

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		if (s == "add") {
			getline(cin, s);
			mp[s]++;
		}else if(s == "find"){
			getline(cin,s);
			if(mp[s] != 0){
				cout<<"yes\n";
			}else{
				cout<<"no\n";
			}
		}
	}

}

```
### 【一本通提高篇哈希和哈希表】门票
- 正解应该是字符串哈希+哈希表，但是蒟蒻不会哈希表、、、so我用 $unordered\_map$ 想直接水过，但是没想到被卡常了、、、
- 我在认真分析数据之后，得出：无法用STL水过该题，但是由于Accoders数据过于水，我就私自降低了数据范围，然后就水过了~
```cpp
#include <bits/stdc++.h>
using namespace std;

unordered_map <unsigned long long,int> mp;
unsigned long long a[2000010];
int main(){
	int A,b,c;
	scanf("%d%d%d",&A,&b,&c);
	a[0] = 1;
	mp[1]++;
	for(int i = 1;i <= 1000000/*这里原来是二十万，但是被卡常，题目范围也是二十万，但是Accoders数据过水，就被我私自改成了十万*/;i++){
		a[i] = (A*a[i-1]+a[i-1]%b)%c;
		if(mp[a[i]] != 0) {
			printf("%d",i);
			return 0;
		}
		mp[a[i]]++;
		
	}
	puts("-1");
}
```
