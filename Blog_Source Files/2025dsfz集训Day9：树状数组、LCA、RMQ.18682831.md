# Day8 I：树状数组
$$Designed\ By\ FrankWkd\ -\ Luogu@Lwj54joy,uid=845400$$
$$特别感谢 此次课的主讲.图源侵删$$
后记：关于本文的所有题目，请吸氧($O2$)+开 $long\ long$
## 关于树状数组
- 顾名思义就是一个结构为树形结构的数组，于二叉树的结构类似但又不同，它是在二叉树的结构上删除了一些中间节点.
- 树状数组可以解决大部分区间上面的修改以及查询的问题，例如：

	- 1.单点修改，单点查询，
	- 2.区间修改，单点查询，
	- 3.区间查询，区间修改，
- 换言之，线段树能解决的问题，树状数组大部分也可以，但是并不一定都能解决，因为线段树的扩展性比树状数组要强.

- 有人会问了既然线段树的问题能够用树状数组解决而且线段树还比树状数组扩展性强，那为什么不直接用线段树呢？
	- 树状数组的作用就是为了简化线段树.基于某些简单的问题，我们没必要用到功能性强但实现复杂的线段树.
- 优点：修改和查询操作复杂度于线段树一样都是logN,但是常数比线段树小，并且实现比线段树简单
- 缺点：扩展性弱，线段树能解决的问题，树状数组不一定能解决.
##### 树状数组结构
 ![image](https://img2024.cnblogs.com/blog/3594125/202501/3594125-20250121084911626-638603632.png)

设黑色框内数组为 $A[1]\to A[8]A[1]→A[8]$

那么可以得到以下式子：

$$C[1] = A[1]$$

$$C[2] = A[1] + A[2]$$

$$C[3] = A[3]$$

$$C[4] = A[1] + A[2] + A[3] + A[4]$$

$$C[5] = A[5]$$ 

$$C[6] = A[5] + A[6]$$

$$C[7] = A[7]$$

$$C[8] = A[1] + A[2] + A[3] + A[4] + A[5] + A[6] + A[7] + A[8];$$

我们便可以得到 $C[i] = A[i - 2^k+1] + A[i - 2^k+2] + ... + A[i]$

在这里，$k$ 为 $i$ 的二进制中从最低位到高位连续零的长度

那么，如何求出二进制中从最低位到高位连续零的长度呢？

我们需要找最低位的 $1$！！！

如何找最低位的 $1$ 呢？

我们需要引入 $lowbit$

<details>
<summary>点击查看 $lowbit$ 模版</summary>

```cpp
inline int lowbit(int x){
	return x&(-x);
}
```
</details>

$\&$ 运算，即与运算，即按位比较都是 $1$ 则为 $1$，否则为 $0$。

$lowbit$ 的原理简单说一下：

在计算机中二进制是以补码存储的。对于 $x(x>0)$,他的补码就是他的本身. 而 $[−x]$ 补为 $[x]$ 补连同符号位取反加一之后的结果 所以 $[-x]$ 补 $\&[x]$ 补刚好就是最低位 $1$ 的结果

总结一下规律：$x\&(-x)$，当 $x$ 为 $0$ 时结果为 $0$ ； $x$ 为奇数时，结果为 $1$ ； $x$ 为偶数时，结果为 $x$ 中 $2$ 的最大次方的因子。用处呢就是找最低位的 $1$ 的位置。
（其实树状数组就是个特殊的前缀和数组）

## 树状数组操作
### 加点

<details>
<summary>点击查看代码</summary>

```cpp
void update(int pos,int num){
	while(pos<=n){
		tree[pos]+=num;
		pos+=pos&-pos;
	}
}
```
</details>

### 查询

<details>
<summary>点击查看代码</summary>

```cpp
long long query(int pos){
	long long res = 0;
	while(pos){
		res += tree[pos];
		pos -= pos&-pos;
	}
	return res;
}
```
</details>

## 例题
- [x] [AccodersP2145 |【一本通提高篇树状数组】修改数列元素，求子数列的连续和](http://www.accoders.com/problem.php?cid=5027&pid=0) (树状数组模版)

<details>
<summary>点击查看代码</summary>

```cpp
#include <bits/stdc++.h>
using namespace std;
int n,m,a[100015],tree[100015];
void update(int pos,int num){
	while(pos<=n){
		tree[pos]+=num;
		pos+=pos&-pos;
	}
}
long long query(int pos){
	long long res = 0;
	while(pos){
		res += tree[pos];
		pos -= pos&-pos;
	}
	return res;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
		update(i,a[i]);
	}
	for(int i = 1;i <= m;i++){
		int op;
		cin>>op;
		if(op == 0){
			int l,r;
			cin>>l>>r;
			cout<<query(r)-query(l-1)<<"\n";
		}else{int pos,x;
			cin>>pos>>x;
			update(pos,x);
			
		}
	}
}
```
</details>


- [x] [AccodersP2147 |【一本通提高篇树状数组】校门外的树](http://www.accoders.com/problem.php?cid=5027&pid=2)(板子)

<details>
<summary>点击查看代码</summary>

```cpp
#include <bits/stdc++.h>
using namespace std;
long long n,m,x[100015],y[1010101],tree[100015];
void update(int pos,int num){
	pos++;
	while(pos<100005){
		tree[pos]+=num;
		pos+=pos&-pos;
	}
}
long long query(int pos){
	long long res = 0;
	pos++;
	while(pos){
		res += tree[pos];
		pos -= pos&-pos;
	}
	return res;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(long long i = 1;i <= n;i++){
		cin>>x[i]>>y[i];
		cout<<query(x[i])<<"\n";
		update(x[i],1);
	}
}
```
</details>


- [x] [AccodersP2147 |【一本通提高篇树状数组】校门外的树](http://www.accoders.com/problem.php?cid=5027&pid=2)
<details>
<summary>点击查看代码</summary>

```cpp
#include <bits/stdc++.h>
using namespace std;
long long cnt,n,m,x[100015],y[1010101];
struct tree{
	int c[101010];
	void update(int pos,int num){
		while(pos<=n){
			c[pos]+=num;
			pos+=pos&-pos;
		}
	}
	long long query(int pos){
		long long res = 0;
		while(pos){
			res += c[pos];
			pos -= pos&-pos;
		}
		return res;
	}
}t1,t2;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memset(t1.c,0,sizeof t1.c);
	memset(t2.c,0,sizeof t2.c);
	cin>>n>>m;
	int k;
	for(int i = 1;i<= m;i++){
		cin>>k;
		int l,r;
		if(k == 1){
			cin>>l>>r;
			t1.update(l,1);
			t2.update(r,1);
			cnt++;
			
		}else{
			cin>>l>>r;
			cout<<cnt-t1.query(n)+t1.query(r)-t2.query(l-1)<<"\n";
		}
	}
}
```
</details>

- [x] [AccodersP2148 |【一本通提高篇树状数组】清点人数](http://www.accoders.com/problem.php?cid=5027&pid=3)
<details>
<summary>点击查看代码</summary>

```cpp
#include <bits/stdc++.h>
using namespace std;
int tree[1000005],k;
int n,m;
void update(int pos,int num){
	while(pos<=n){
		tree[pos]+=num;
		pos+=pos&-pos;
	}
}
long long query(int pos){
	long long res = 0;
	while(pos){
		res += tree[pos];
		pos -= pos&-pos;
	}
	return res;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i = 1;i<= m;i++){
		char s;
		cin>>s;
		int l,r;
		
		if(s == 'A'){
			cin>>l;
			cout<<query(l)<<"\n";
		}else if(s == 'B'){
			cin>>l>>r;
			update(l,r);
		}else{
			cin>>l>>r;
			update(l,-r);
		}
	}
}
```
</details>

# $LCA$ 与 $RMQ$

- $RMQ$ 全称 $Range Maximum/Minimum Query$

- 做法很多，比较优秀的是 $ST$ 表。$Sparse Table$，稀疏表

## $ST$ 表
- $st$ 表是用来解决可重复贡献问题的一种数据结构。
- 考虑设 $st[i][j]$ 表示 $i$ 到 $i+(2^j)-1$ 这段区间的最大值。
- 那么可以转移： $st[i][j]=max(st[i][j-1],st[i+2^(j-1)][j-1])$
- 区间查询：设 $k=log(r-l+1)$ 向下取整。那么区间最大值即为
 $max(st[l][k],st[r-(2^k)+1][k])$
- 时间复杂度：预处理 $O(nlogn)$，查询 $O(1)$。
- 空间复杂度 $O(nlogn)$。
- 其他可重复贡献问题也可解决。

## 优化
- 一个小但复杂的优化：$Four\ Russian$（四毛子）

  - 考虑将序列每 $B$ 个分成一块，总块数 $\frac{n}{B}$。

  - 对于每块求出最小值，得到一个长度为 n/B 的数组，对这个数组做 st 表。

    再对每个块内分别做 st 表。

  - 查询：可分成两个左右的散块和中间一段整块，三次 st 表查询。

  - 分析复杂度：预处理为 $O(\frac{n}{B}log\frac{n}{B}+\frac{n}{B}×BlogB)$，在 $B$ 取 $log\ n$ 时可得到理论最优复杂度为预处理 $O(nloglogn)$，查询 $O(1)$，空间也为 $O(n loglogn)$。

- 然而虽然预处理很优秀，但是每次查询需要三个 $st$ 表，常数很大。且由于代码不好写，并且一般的算法竞赛并没有很高的复杂度要求，因此很不常用。(嘻嘻)

## 基于状压的线性 $RMQ$ 算法

- 对于一个特殊情况的进一步优化：$+1-1RMQ。$

  也即：序列相邻元素差值为 $1$ 或 $-1$ ，求 $RMQ $。

- 我们注意到 $B=logn$ 时瓶颈在于块内 $st$ 表处理。

- 而由于差为 $1$ 或 $-1$，且每次对散块的询问都是一个长度不超过 $B=logn$ 的序列，在序列头元素固定的情况下，这样的序列只有 $∑_{i=1}^{log⁡n}2^i$ 种，这个值为 $O(n)$ 。我们可以对每种情况预处理此时最小值-头元素的结果，这个可以直接递推。于是我们就做到了 $O(n)$ 预处理，$O(1)$ 查询的 $RMQ$ 算法，仅限于 $+1-1$ 序列。

- 重新回到平凡情况，我们审视一下四毛子算法。

- 对于每个块真的需要 都做 $st$ 表吗？其实如果询问的 $l,r$ 不在同一个块内，我们可以直接预处理每个块的前缀、后缀最小值来做到 $O(n)$ 预处理 $O(1)$ 查询。

- 关键就在于如果询问的 $l,r$ 在同一个块内如何去做。

- 考虑使用单调栈：预处理的时候从 $1$ 到 $n$ 枚举 $r$，处理每个 $r$ 的单调递增栈。那么 $l$ 到 $r$ 的最小值就是栈中第一个在 $l$ 后的位置。

  - 我们可以用一个二进制整数去存储以 $r$ 为右端点，长度为 $logn$ 的一个后缀里面每个数是否在单调栈内。那么查询就只要询问一个二进制数的最低的1。使用 $\_\_builtin\_ctz$ 即可 $O(1)$ 查询（或者 $log.lowbit$）。

此方法即基于状压的线性 $RMQ$ 算法。
其实讲了这么多实际上用的还是平凡的 $RMQ$…

## LCA
- $LCA$：最近公共祖先（$Lowest\ Common\ Ancestor$）
### 求LCA
- 如何求两点的最近公共祖先？

  - 朴素求法：每次选择深度较大的那个点向上跳到父亲，不断重复直到两个点重合，即为LCA。

- 复杂度：预处理 $VBN MN M  O(n)$，单次询问 $O(n)$。

### 倍增
-  倍增法：最经典的求 $LCA$ 的方法。

- 和 $ST$ 表中的倍增类似，我们设 $f[u][i]$ 表示节点 $u$ 的 $2^i$ 级祖先。$1$ 级祖先即为父亲。

  - 转移：$f[u][i]=f[f[u][i-1]][i-1]$。

- 有了这个就可以 $O(log n)$ 求某个点的 $k$ 级祖先：将 $k$ 二进制分解。

- 求 $LCA$：首先将两个点跳到深度相等。然后从大到小枚举 $i$，如果 $f[u][i]$ 和 $f[v][i]$ 不相等就将两个点都向上跳成 $f[u][i]$ 和 $f[v][i]$。这样最终 $f[u][0]$ 就是答案。
  - 时间复杂度：预处理 $O(nlogn)$，单次询问 $O(logn)$

  - 空间复杂度：$O(nlogn)$。
### DFS
用 $dfs$ 序求 $lca$：假设询问的点为 $x,y$。

不妨设 $x$ 的 $dfs$ 序在 $y$ 前面。$dfn[x]<dfn[y]$

求出 $dfs$ 序在 $[ dfn[x]+1, dfn[y] ]$ 内的结点中深度最小的那个，设为 u，则答案为 
 $fa[u]$。

要特判 $x==y $。

求深度最小值可用 $RMQ$ 来求，复杂度为 $O(nlogn) – O(1)$。

单次 $O(1)$，**非常优秀。**

- 当然也可以用 $+1-1RMQ$ 做到 $O(n)-O(1)$


### 离线 tarjan LCA
**使用并查集。**

首先离线，$dfs$ 整棵树，在回溯某个结点的时候将他合并到他父亲的并查集上。

在回溯点 $u$ 时枚举其中一个结点为 $u$ 的所有询问 $(u,v)$，如果 $v$ 已经被回溯过，那么 $v$ 所在的并查集即为答案。

时间复杂度：$O(mα(m+n)+n)$。优点是复杂度优秀，缺点是需要离线。
