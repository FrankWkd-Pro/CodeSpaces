#### 2024B层次十一集训 10.3日 数据结构专题模拟
# 考试总结
#### FrankWKD Updated AT 2024/10/3 13:21

----
----
## 概述
总分：$140/400$  
Rank：$24/87$  
期望排名：$15/87$  
评价：♣♣♣♣♧
#### [$转载的题解$](https://www.cnblogs.com/xiezheyuan/p/test20220416.html)
#### [$源码下载$](https://www.luogu.com.cn/team/85621#file)
----

## $T1-Sequence$
- ### [$T1-Sequence传送门$](http://47.93.29.13/problem.php?cid=4893&pid=0)  
- [x] 已改？   
Score：$TLE$ $|$ $10/100$   
总结：考试的时候没思路，应该是道单调栈
- ### $T1-ExampleCode$
```cpp
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define sint long long
#define endl '\n'
using namespace std;
sint a[300010], l[300010], r[300010], ll[300010], x[300010], n, top, top2, st[300010], st2[300010];
long long ans;

int main() {
	freopen("data.in", "r", stdin);
	freopen("user.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		r[i] = n + 1;
		x[i] = n + 1;
	}
	for (int i = 1; i <= n; ++i) {
		while (top && a[st[top]] > a[i]) {
			r[st[top--]] = i;
		}
		l[i] = st[top];
		st[++top] = i;
	}
	for (int i = 1; i <= n; ++i) {
		while (top2 && a[st2[top2]] < a[i]) {
			x[st2[top2--]] = i;
		}
		ll[i] = st2[top2];
		st2[++top2] = i;
	}
	for (int i = 1; i <= n; i++) {
		ans -= (r[i] - i) * (i - l[i]) * a[i];
		ans += (x[i] - i) * (i - ll[i]) * a[i];
	}
	cout << ans << endl;
	return 0;
}


```
----
## $T2-Homework$
- ### [$T2-Homework传送门$](http://47.93.29.13/problem.php?cid=4893&pid=1)
- [x] 已改？   
Score：$AC$ $|$ $100/100$  
总结：花了1.5h才想好，看起来DP的题，我用的爆改链表+并查集，这道题乍一看真的好唬人，其实就是简简单单贪心罢了。
- ### $T2-ExampleCode$
```cpp
/*
By: FrankWKD
From: Self
Date: 2024/10/03
Note: -T1-fileIO
*/
#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
int n;
long long ans;
int f[100010];//times

struct node {
	int d, p;
} s[100010];

bool cmp(node x, node y) {
	return x.p > y.p;
}

int find(int x) {
	if (f[x] < 0)//未被标记过
		return x;
	f[x] = find(f[x]);//找到根
	return f[x];
}

/*
5
d p
2 10
1 7
4 6
3 5
5 5

f: 0 1 2 3 4 5 6 7 8 9 10
   * * * * * * * * * * *
ans: 0
i:   1
*/
int main() {
	freopen("homework.in", "r", stdin);
	freopen("homework.out", "w", stdout);
	memset(f, -1, sizeof(f));
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> s[i].d >> s[i].p;
	}
	sort(s + 1, s + n + 1, cmp);//降序排序按分数
	for (int i = 1; i <= n; i++) {
		int x = find(s[i].d);//如果被标记过就返回根，否则返回s[i].d
		if (x > 0) {
			ans += s[i].p;
			f[x] = x - 1;//方便查看是否有空缺的位置
		}
	}
	cout << ans;
	return 0;
}
```
----
## $T3-Sort$
- ### [$T3-Sort传送门$](http://47.93.29.13/problem.php?cid=4893&pid=2)  
- [x] 已改？    
Score：$WA$ $|$ $30/100$  
_**总结**：开始很顺利，就是找逆序对，简单找找规律就出来了，结果出分没过，提交好几遍才知道我把$%lld$改成了$%d$，嘤嘤嘤
- #### $T3-ExampleCode$
```cpp
/*
By: FrankWKD
From: Self
Date: 2024/10/03
Note: -T3-fileIO
*/
//#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
int a[1001000], tmp[1000100], n;
long long ans;

void m(int a[], int l, int r) {
	if (l >= r)
		return;
	int mid = l + r >> 1;
	m(a, l, mid);
	m(a, mid + 1, r);
	int i = l, j = mid + 1, k = 0;
	while (i <= mid and j <= r) {
		if (a[i] <= a[j])
			tmp[k++] = a[i++];
		else
			tmp[k++] = a[j++], ans += mid - i + 1;
	}
	while (i <= mid)
		tmp[k++] = a[i++];
	while (j <= r)
		tmp[k++] = a[j++];
	i = l;
	for (int j = 0; j < k; j++) {
		a[i++] = tmp[j];
	}
}

int main() {
	freopen("sort.in", "r", stdin);
	freopen("sort.out", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	m(a, 0, n - 1);
	printf("%lld", ans);
	return 0;
}
```
----
## $T4-Light$
- ### [$T4-Light传送门$](http://47.93.29.13/problem.php?cid=4893&pid=3)  
- [ ] 已改？  
Score：$WA$ $|$ $0/100$  
_**总结**_：这道题0思路，看了邻居的代码之后发现是三分+模拟优化，到最后还是没做出来
- ### $T4-ExampleCode$
```cpp

```

#### 2024B层次十一集训 10.4日 CSP-J模拟测试1

# 考试总结
#### FrankWKD Updated AT 2024/10/04 13:01

----
----
## 概述
总分：$220/400$  
Rank：$32/152$  
期望排名：$11/152$  
评价：♣♣♣♣♧
#### [$题目/参考解法下载$](https://www.luogu.com.cn/team/85621#file)
----

## $T1-徐老师的广度优先搜索$
- [x] 已改？   
Score：$AC$ $|$ $100/100$   
- ### $总结：$
  就是纯找规律，加上一点点等差数列求和公式，记得开long long  
- ### $做法：$
  - 直接拆成2个等差数列再套公式
  - 把整个区域看成旋转后的正方形再套公式求和
  
- ### $T1-ExampleCode$
```cpp
//Date: 2024/10/04
//#pragma GCC optimize(2)
//#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("data.in", "r", stdin);
	freopen("user.out", "w", stdout);
	unsigned long long n;
	cin >> n;
	n--;
	unsigned long long a = (2 + n * 2) * (n + 1) / 2;
	unsigned long long b = 2 * n * n / 2;
	cout << a + b;
}
```
## $T2-徐老师的仓管系统$
- [ ] 已改？   
Score：$TLE$ $|$ $20/100$   
- ### $总结：$
  千万不要用cincout！这道题就是卡缓冲区的纯模拟，蒟蒻用了map映射结果喜提TLE
- ### $做法：$
  直接开1e6数组开桶排，下表记录编号，用0或1记录状态，模拟就行
- ### $T2-ExampleCode$
```cpp

```
## $T3-徐老师的求和方案$
- [x] 已改？   
Score：$AC$ $|$ $100/100$   
- ### $总结：$
  这道题吧，一言难尽，是一道大模拟。这道题只有加法就没什么技术含量，要是加了别的就得用栈了。
- ### $做法：$
  需要加二进制优化，复杂度是 $O(2^n) $(n为数字位数)，递归出所有情况之后求解，注意前导零。
- ### $T3-ExampleCode$
```cpp
//Date: 2024/01/04
//#pragma GCC optimize(2)
//#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

ull n;
string s;

struct node {
	bool is_light = false;
} a[100];
ull top = 1;
ull b[10101001];

inline void calc() {
	ull nums[1001], t = 1;
	memset(nums, 0, sizeof(nums));
	for (ull i = 0; i < s.size(); i++) {
		if (a[i].is_light == false) {
			nums[t] = nums[t] * 10 + (s[i] - '0');
		} else {
			nums[++t] = s[i] - '0';
		}
	}
	for (ull i = 1; i <= t; i++) {
		b[top] += nums[i];
	}
//	cout << b[top] << endl;
	top++;

}

inline void fun(ull i) {
	if (i > s.size()) {
		calc();
		return ;
	} else {
		if (s[i] != '0') {
			a[i].is_light = true;
			fun(i + 1);
		}
		a[i].is_light = false;
		fun(i + 1);
	}
}

int main() {
	freopen("data.in", "r", stdin);
	freopen("user.out", "w", stdout);
	cin >> s;
	fun(1);
	ull mi = 1e19, ma = 0, tot = 0;
	for (ull i = 1; i < top; i += 2) {
//		cout << b[i] << " ";
		mi = min(mi, b[i]);
		ma = max(ma, b[i]);
		tot += b[i];
	}
	cout << top / 2 << endl;
	cout << ma << " " << mi << " " << tot << endl;
}
```
## $T4-徐老师的羊腿高塔$
- [ ] 已改？   
Score：$WA$ $|$ $0/100$   
- ### $总结：$
  场上没思路，就连算法都没想出来，这个数据相比T2简直就是超级加倍啊，复杂度必须小于 $O(n log_2 n)$ 才行。
- ### $做法：$
  需要保证
- ### $T4-ExampleCode$
  暂无
## 2025年东师附中B层集训测试1考试总结
#### Designed By Lwj54joy AT 2025-01-13
## 概述
总分：$164/400$   
改题分数：$400/400$  
Rank：$11/44$  
期望排名：$10/44$  
评价：$80/100$
### [$比赛Link[Accoders]$](http://www.accoders.com/contest.php?cid=5033)
----

## $T1-饮料换购$
- [x] 已改？   
Score：$AC$ $|$ $100/100$   
- ### $总结：$
  数据范围很水，暴力就能过，但是要留下换之后剩下的瓶盖，再加上换完的水留下的瓶盖，就是换一轮瓶盖之后剩下的瓶盖数。（如果能借还会更麻烦）
- ### $做法：$
  - 瓶盖数就是水的数量加上换剩下的瓶盖数。
  - 重复上一步直到瓶盖数小于3即可。
  
- ### $T1-ExampleCode$
```cpp
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;

int main(Designer = 洛谷@Lwj54joy，uid=845400){
	int n;
	cin>>n;
	int ans = 0;
	ans = n;
	while( n >= 3){
		ans += n / 3;
		n = n/3+n%3;
		
	}
	cout<<ans<<endl;
}
```
## $T2-买不到的数目$
- [x] 已改？   
Score：$WA$ $|$ $38/100$   
- ### $总结：$
  这题我写的是普通DP，是能AC的，因为数据最大1000，但是测试数据跑到long long那里去了TxT，这回合数据妥妥地背锅。
- ### $做法：$
  经过一堆公式推出 $ans = (a-1)\times(b-1)-1$ 。$O(1)$ 直接出结果。
- ### $T2-ExampleCode$
```cpp
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
int f[10101010];
int main(Designer = 洛谷@Lwj54joy，uid=845400){
	long long a,b;
	cin>>a>>b;
	cout<<(a-1)*(b-1)-1;
}
```
## $T3-费解的开关$
- [x] 已改？   
Score：$WA$ $|$ $17/100$
- ### $总结：$
  这道题考试的时候没思路，写了个DFS递归还挂了，想了好长时间也没想出怎么优化复杂度，当时暴力的复杂度是 $O(25^6\times600)$ 直接挂。这种奇怪的题大多需要优化，例如翻硬币，要么是降复杂度，要么是加公式，要么是套数据结构（出现少）。需要多练。
- ### $做法：$
  将矩阵的第一行暴力枚举，剩下的都可以根据“矩阵所有数都代表‘开’的状态，即 $1$ ”求出结果。最后遍历一遍整个矩阵，求出修改的次数就是答案。精确复杂度是 $O((2^5+5\times4+5^2)\times600)$ 。
- ### $T3-ExampleCode$
```cpp
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
const int N = 60;
char g[N][N], bg[N][N];
int dx[5] = {-1, 0, 1, 0, 0}, dy[5] = {0, 1, 0, -1, 0};
void turn(int x, int y) {
	for (int i = 0; i < 5; i++) {
		int a = x + dx[i], b = y + dy[i];
		if (a < 0 || a >= 5 || b < 0 || b >= 5)continue;
		g[a][b] ^= 1;
	}
}
int main(Designer = 洛谷@Lwj54joy，uid=845400){
	int T;
	scanf("%d", &T);
	while (T--) {
		for (int i = 0; i < 5; i++)scanf("%s", bg[i]);
		int res = 10;
		for (int op = 0; op < 32; op++) {
			int cnt = 0;
			memcpy(g, bg, sizeof(g));
			for (int i = 0; i < 5; i++)
				if (op >> i & 1) {
					turn(0, i);
					cnt++;
				}

			for (int i = 0; i < 4; i++)
				for (int j = 0; j < 5; j++)
					if (g[i][j] == '0') {
						turn(i + 1, j);
						cnt++;
					}

			bool success = true;
			for (int i = 0; i < 5; i++)
				if (g[4][i] == '0')success = false;
			if (success && res > cnt)res = cnt;
		}
		if (res > 6)res = -1;
		printf("%d\n", res);
	}
	
}
```
## $T4-	机器人跳跃问题$
- [x] 已改？   
Score：$WA$ $|$ $9/100$   
- ### $总结：$
  以为是类似跳房子的二分答案，结果题解出来二分答案公式推导了半天，最简单的做法是逆推，题面的最大最小很有迷惑性，我想都不想就直接搞起了二分。其实简单分析分析就知道是逆推。逆推忘了、、
- ### $做法：$
  因为要求能量值最小且中途非负，直接设到终点后能量值为 $0$ ，那么我们用 $E_i$ 表示到达第 $i$ 个建筑后的能量值，那么 $E_n = 0$ 。由题面的两个公式易得： $E_{i+1} = 2E_i - H_{i+1}$ ，那就能得出 $E_{n-1}$ 的值，从而一步步逆序得出 $E_1$ 的值，就是结果。
- ### $T4-ExampleCode$
```cpp
#include <bits/stdc++.h>
using namespace std;
long long a[1000010],n;
int main(Designer = 洛谷@Lwj54joy，uid=845400){
	cin>>n;
	for(long long i = 1;i <= n;i++){
		cin>>a[i];
	}
	long long  ans = 0;
//	0+H(n+1) = 2*E(n)
	for(long long i = n;i >= 1;i--){
		ans = (ans+a[i])/2;
	}
	cout<<ans+1<<endl;
}
```
----
----
# 2025年东师附中B层集训测试2考试总结
###### Designed By Lwj54joy AT 2025-01-13
## 概述
总分：$251/400$ 
改题分数：$400/400$
Rank：$13/44$  
期望排名：$10/44$  
评价：75/100
#### [$比赛Link[Accoders]$](http://www.accoders.com/contest.php?cid=5034)
----

## $T1-移动距离$
- [x] 已改？   
Score：$AC$ $|$ $100/100$   
- ### $总结：$
  数据范围很水，暴力就能过，但是我用的是数学，仔细分析一下就能得出来。
- ### $做法：$
  这题纯模拟。我们读入 $m$ 和 $n$ 之后，如果 $n$ 更大，可以把 $m$ 和 $n$ 的值互换。接着我们可以求出 $n$ 和 $m$ 对应的坐标。当我们求出 $n$ 的坐标 $kx$ 和 $ky$ ， $m$ 的坐标 $x$ 和 $y$ 之后，最短距离只需用 $|kx-x|+|ky-y|∣kx−x∣+∣ky−y∣$ 就行了。
- ### $T1-ExampleCode$
```cpp
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=10010;
signed main(Designer = 洛谷@Lwj54joy，uid=845400){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
     
    int w,m,n;
    cin>>w>>m>>n;
    int xm=(m+w-1)/w;
    int xn=(n+w-1)/w;
    //AC
    m-=(xm-1)*w; n-=(xn-1)*w;
    //AC
    int ym,yn;
    //get_ym
    if(xm%2==1) ym=m;
    else ym=w-m+1;
    //get_yn
    if(xn%2==1) yn=n;
    else yn=w-n+1;
    //AC
    cout<<abs(xn-xm)+abs(yn-ym);
    return 0;
}
```
## $T2-错误票据$
- [x] 已改？   
Score：$AC$ $|$ $100/100$   
- ### $总结：$
  这题直接`map`就能过，不能用`getline`！会多读入一个换行出`bug`！
- ### $做法：$
  用map映射，最后统计中间的重复和空缺，因为两边没有，记得标记开始下标。
- ### $T2-ExampleCode$
```cpp
#include <bits/stdc++.h>
using namespace std;
int a[101010];
int main(){
	int minn = 9999999,maxx = -1;
	int n;
	cin>>n;
	int t;
	while( cin >> t ){
		a[t]++;
		maxx = max(maxx,t);
		minn = min(minn,t);
	}
	for(int i = minn;i <= maxx;i++){
		if(a[i] == 0) cout<<i<<" ";
	}
	for(int i = minn;i <= maxx;i++){
		if(a[i] == 2) cout<<i<<" ";
	}
	
}
```
## $T3-雷达设备$
- [x] 已改？   
Score：$WA$ $|$ $18/100$
- ### $总结：$
  这道题考试的时候没思路，其实是贪心之区间选点。
- ### $做法：$
  首先这是一道贪心题。

  第一个，雷达肯定是坐标轴上的点，这样视野才最开阔。

  根据光路可逆（大雾），岛能看到你，你也就能看到岛。

  所以 说我们先处理出每个岛 $(x,y)(x,y)$ 能看到的坐标轴的范围：
  设 $len=\sqrt{d^2-y^2}$
  //勾股定理

  这个岛能看到的范围就是 $[ x-len , x+len ][x−len,x+len]$ 。

  这样我们就得到了 $n$ 个区间，要保证每个区间内有一个雷达。

  这就是 区间选点 问题。参见蓝皮书（信息学奥赛一本通 · 提高篇）
- ### $T3-ExampleCode$
```cpp
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;

const int MaxN=1005;
struct segment {
	double l,r;
}a[MaxN];
int n;
double d;
int num[MaxN];

inline double calc(double y){
	return sqrt(d*d-y*y);
}

inline void init(){
	scanf("%d%lf",&n,&d); 
	for(register int i=1;i<=n;i++) {
		double x,y;
		scanf("%lf%lf",&x,&y);
		if(y>d) { //如果y太大了，说明在哪放都无济于事
			printf("-1"); 
			exit(0);
		}
		double len=calc(y); 
		a[i].l=x-len; 
		a[i].r=x+len;
		num[i]=1; //这一行和前两行的意思：[l,r]要求有一个点
	}
}

bool cmp(segment x,segment y){
	return x.r<y.r;
}

inline void work(){
	int ans=0; 
	sort(a+1,a+1+n,cmp); //先排序，按右端点
	for(int i=1;i<=n;i++) { //看每一条区间
		double nowr=a[i].r; //这一条区间的右端点。因为放右端点的话就有更大几率影响其他的区间
		if(num[i]<=0) continue; //如果没需求了，就直接跳过
		num[i]--; //需求减一
		for(register int j=i+1;j<=n;j++) { //看后面相交的区间
			if(a[j].l<=nowr) { 
				num[j]--; //同样需求减一
			}
		}
		ans++; //代价加一
	}
	printf("%d",ans);
}

int main(Designer = 洛谷@Lwj54joy，uid=845400){
	init(); //初始化出区间
	work(); //贪心
}
```
## $T4-	Knight Moves$
- [x] 已改？   
Score：$TLE$ $|$ $33/100$   
- ### $总结：$
  就是BFS板子题，我打了半个点DFS妥妥TLE
- ### $做法：$
  直接使用BFS遍历整个矩阵就行。多组数据记得清零 $vis$ $(bool$ 数组 $)$
- ### $T4-ExampleCode$
```cpp
#include<bits/stdc++.h>
using namespace std;
int t,n,a[1005][1005],tx,ty,ex,ey;
bool st[1005][1005];
int dx[9]={0,1,1,2,2,-1,-1,-2,-2};
int dy[9]={0,2,-2,1,-1,2,-2,1,-1};

int bfs(){
	for(int i=0;i<=300;i++)
		for(int j=0;j<=300;j++)
			a[i][j]=1e9,st[i][j]=0;
	queue<pair<int,int> > q;
	q.push({tx,ty});
	a[tx][ty]=0,st[tx][ty]=true;
	while(!q.empty()){
		int x=q.front().first,y=q.front().second;
		q.pop();
		if(x==ex && y==ey)return a[x][y];
		for(int i=1;i<=8;i++){
			int xx=x+dx[i],yy=y+dy[i];
			if(xx>=0 && xx<n && yy>=0 && yy<n && !st[xx][yy]){
				q.push({xx,yy});
				a[xx][yy]=min(a[xx][yy],a[x][y]+1),st[xx][yy]=1;
				if(xx==ex && yy==ey) return a[xx][yy];
			}
		}
	}
	return 1145141919810;
}

int main(Designer = 洛谷@Lwj54joy，uid=845400){
	cin>>t;
	while(t--){
		cin>>n>>tx>>ty>>ex>>ey;
		cout<<bfs()<<endl;
	}
	return 0;
}
```
----
----