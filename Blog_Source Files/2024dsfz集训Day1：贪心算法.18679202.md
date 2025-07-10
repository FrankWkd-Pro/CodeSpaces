# DAY1：贪心算法
$$Designed\ By\ FrankWkd\ -\ Luogu@Lwj54joy,uid=845400$$
特别感谢 此次课的主讲 - Kwling
## 经典模型：
- **硬币问题：**  
  **找零钱问题：**  
  有 $100$ 元、$50$ 元、$20$ 元、$10$ 元、$5$ 元和 $1$ 元这些面值的钱  
  -  求凑出 $𝑥$ 元的最多张数和最少张数，要求第 $𝑖$ 种面值的钱不能用超过 $𝑎_𝑖$ 张  
  -  多组询问，$𝑇 ≤ 10^5,𝑎_𝑖 ≤ 10^9, 𝑥 ≤ 10^9$ 。  
  
  **解题思路：**
  1. 首先，我们需要将货币面值存储在一个数组中，按照从大到小的顺序排列，即 $\{100, 50, 20, 10, 5, 1\}$ 。
  2. 对于求最多张数的情况：
  - 从最小面值开始，尽可能多地使用该面值的货币，直到达到使用该面值的上限 $a_i$ 或凑够所需金额 $x$ 。
  - 重复此过程，逐步使用更大面值的货币，直到凑够 $x$ 元或无法再凑出。
  3. 对于求最少张数的情况：
  - 从最大面值开始，尽可能多地使用该面值的货币，直到达到使用该面值的上限 $a_i$ 或凑够所需金额 $x$ 。
  - 重复此过程，逐步使用更小面值的货币，直到凑够 $x$ 元或无法再凑出。

- **部分背包**  
  例如：
 - [x] [洛谷P2240 |【深基12.例1】部分背包问题](https://www.luogu.com.cn/problem/P2240)  
**解法：** 对于所有物品，按性价比排序再按一定顺序计算可得结果。

- **区间问题**
  1. **选择若干不相交区间问题**  
      - **例题：** 
      - [x] [Accoders P2032 |【一本通提高篇贪心】 活动安排](http://www.accoders.com/problem.php?cid=2338&pid=0)
      - [x] [Accoders P1873 |【一本通基础贪心】活动选择](http://www.accoders.com/problem.php?cid=2354&pid=4)

      - **思路：** 以结束时间为第一关键字排序，依次考虑各个活动，如果没有和已经选择的活动冲突，就选，否则就不选。
  2. **区间覆盖或线段覆盖问题**
      - **例题：** 
      - [x] [洛谷P1803 | 凌乱的yyy / 线段覆盖](https://www.luogu.com.cn/problem/P1803)
      - [x] [AccodersP2039 |【一本通提高篇贪心】线段](http://www.accoders.com/problem.php?cid=2338&pid=7)  
  
      - **思路：** 最左边的线段放什么最好？  
      显然放右端点最靠左的线段最好，从左向右放，右端点越小妨碍越少。  
      其他线段放置按右端点排序，贪心放置线段，即能放就放。（类似若干不相交区间问题）
  3. **区间分段问题**
      - **例题：**
      - [x] [Accoders P2038 |【一本通提高篇贪心】 数列分段](http://www.accoders.com/problem.php?cid=2338&pid=6)

      - [x] [洛谷P1181 | 数列分段 Section I](https://www.luogu.com.cn/problem/P1181)
      - **思路：** 这个应该算是最简单最基础的贪心了，甚至都不用排序，从前往后扫，一旦和大于 $m$ ，再分新的一段。

 - **顺序问题**  
  - [x] [Accoders P2037 |【一本通提高篇贪心】 数列极差](http://www.accoders.com/problem.php?cid=2338&pid=5)  
**解法：** 可以发现，按照小数到大数的顺序跑题目里的公式可以得到最大值，按照大数到小数的顺序可以得到最小值。  
    那我们直接用堆来维护顺序，一个大根堆，一个小根堆，每次弹堆顶的两个数参与运算，运算完毕后再 $push$ 进堆即可。

----
## 一般解题步骤
1. 建立数学模型来**描述问题**（把问题简化成学过的知识，术语，或者算法）；
2. 把求解的问题**分成若干个子问题**（大事化小）；
3. 对每一子问题求解，得到**子问题的局部最优解**（小事化了）；
4. 把子问题的局部最优解**合成**原来问题的一个解（合并所有答案得到最终答案）。

## 范围及证明
### 决定一个贪心算法是否能找到全局最优解的条件：

  1. ${\color{Blue}\large \mathcal{有最优子结构}}$：很好理解，就是指一个问题的最优解**包含其子结构的最优解**，和动态规划上理解是一样的。

  2. ${\color{Blue}\large \mathcal{有最优贪心选择属性}}$：而贪心选择性是指所求问题的整体最优解可以通过一系列可以**通过一系列局部最优的选择来达到**。他总是作出**当前**最好的选择，该选择可以依赖于之前的选择，但绝**不依赖**于**将来的选择**和**子问题的选择**，这是他与动态规划的重要区别。

     一般我们证明一个题目可以用贪心就是证明上面两点均满足。

  - **反证法：** 如果交换方案中任意两个元素/相邻的两个元素后，答案不会变得更好，那么可以推定目前的解已经是最优解了。

  - **归纳法：** 先算得出边界情况（例如 $n=1$ ）的最优解 $F_1$ ，然后再证明：对于每个 $n$ ，$F_{n+1}$ 都可以由 $F_n$ 推导出结果。  
    归纳法例题： 
 - [x] [AccodersP11297 | 机器人跳跃问题](http://www.accoders.com/problem.php?cid=5033&pid=3)

## 题目解法&思路

### $T1$ 
 - [x] [AccodersP2032 |【一本通提高篇贪心】活动安排](http://www.accoders.com/problem.php?cid=5014&pid=0)  
**思路：** 我们按照活动的结束时间进行升序排序，因为一个活动结束的越早，就越不容易与其他活动起冲突，从前往后枚举时判断一下就行了
```cpp
#include <bits/stdc++.h>
using namespace std;

struct node{
	int x,y;
}a[101010];
int n;
bool cmp(node xx,node yy){
	return xx.y < yy.y;
}
int main(Designer = 洛谷@Lwj54joy，uid=845400){
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>a[i].x>>a[i].y;
	}
	sort(a+1,a+1+n,cmp);
	int ans = 1,ls;
	ls = a[1].y;
	for(int i = 2;i <= n;i++){
		if(a[i].x >= ls) ans++,ls = a[i].y;
	}
	cout<<ans<<endl;
} 
```
### $T2$ 
 - [x] [AccodersP2033 |【一本通提高篇贪心】种树](http://www.accoders.com/problem.php?cid=5014&pid=1)
 - [x] [LuoguP9836 | 种树](https://www.luogu.com.cn/problem/P9836)  
**思路** ：依然是按照路段的结束位置进行升序排序，以便于我们从前往后按顺序枚举，枚举每一个路段时，从路段的开头枚举到结尾，由于一个位置只能种一棵树，所以只要这个位置有树，这个路段要求的树的数量就-1，具体看代码
```cpp
#include <bits/stdc++.h>
using namespace std;
bool f[101010];
struct node{
    int x,y,z;
}a[101010];
int n;
bool cmp(node xx,node yy){
    return xx.y < yy.y;
}
int h;
int main(Designer = 洛谷@Lwj54joy，uid=845400){
    cin>>n>>h;
    for(int i = 1;i <= h;i++){
        cin>>a[i].x>>a[i].y>>a[i].z;
    }
    sort(a+1,a+1+h,cmp);
    int ans = 0;
    for(int i = 1;i <= h;i++){
        int lim = a[i].z;
        for(int j = a[i].x;j <= a[i].y and lim;j++){
            if(f[j]) lim--;
        }
        if(lim != 0){
            for(int j = a[i].y;j >= a[i].x and lim;j--){
                if(f[j]) continue;
                ans++;
                f[j] = true;
                lim--;
            }
        }
    }
    cout<<ans<<endl;
} 
```
### $T3$ 
 - [x] [AccodersP2034 |【一本通提高篇贪心】喷水装置](http://www.accoders.com/problem.php?cid=5014&pid=2)  
**思路** ：因为喷洒范围是圆，所以我们要利用勾股定理来求出这个有效范围 贪心忽然成了数学题，我们可以求出一个喷头有效范围的最左端和最右端，按照最左端进行升序排序，以便不会漏下没覆盖到的区域，从左到右一个一个检查，还要考虑能不能喷到上下边缘。具体看代码
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

struct node {
    double l, r;
    bool operator<(const node& W) const {
        return l < W.l;
    }
};


int main(Designer = 洛谷@Lwj54joy，uid=845400){
    int T;
    std::cin >> T;
    while (T--) {
        int cnt = 0;
        int n;
        double l, w;
        std::cin >> n >> l >> w;
        std::vector<node> a;
        double w2 = w / 2.0;
        for (int i = 0; i < n; ++i) {
            double x, y;
            std::cin >> x >> y;
            if (y <= w / 2) {
                continue;
            }
            node temp;
            temp.l = x - std::sqrt(y * y - w * w / 4);
            temp.r = x + std::sqrt(y * y - w * w / 4);
            a.push_back(temp);
        }
        std::sort(a.begin(), a.end());
        double s = 0, e = l;
        int i = 0, ans = 0;
        bool t = false;
        while (s < e) {
            double vis = -2e9;
            size_t j;
            for (j = i; j < a.size(); ++j) {
                if (a[j].l <= s) {
                    vis = std::max(vis, a[j].r);
                } else {
                    break;
                }
            }
            if (s < e && vis < s) {
                std::cout << -1 << "\n";
                t = true;
                break;
            }
            ans++;
            s = vis;
            i = j;
        }
        if (!t) std::cout << ans << "\n";
    }
    
}
```
### $T4$ 
 - [x] [AccodersP2035 |【一本通提高篇贪心】加工生产调度](http://www.accoders.com/problem.php?cid=5014&pid=3)
 - [x] [洛谷P1248 | 加工生产调度](https://www.luogu.com.cn/problem/P1248)  
**思路** ：$\mathbf{{\color{Red} {\scriptsize 【请先确保您已经对题面足够熟悉再阅读思路】} } }$ 第一个产品在 $A$ 加工时，没有其他产品在 $B$ 加工，所要选 $a$ 小的充当最后一个物品，在 $B$ 加工时，没有其他产品在 $A$ 加工，以要选 $b$ 小的，对于其他产品，如果该产品的 $a$ 比 $b$ 小，那么把这产品放到前面去，它越早离开 $A$ 工厂，其他产品就能越早进入 $A$ 工厂；如 $b$ 比 $a$ 小，那就往后放，它越早离开 $B$ 工厂，其他产品就能越早入 $B$ 工厂。为什么这么排呢？因为一个物品必须先进入 $A$ 工厂，在进 $B$ 工厂，我们先尽快让所有产品进入 $A$ 工厂，再尽快让所有产品离 $B$ 工厂，这就是我们的贪心策略。
```cpp
#include <bits/stdc++.h>
using namespace std;
struct node{
	int w,id;
}e[1010];
int a[1010],b[1010],n;
bool cmp(node xx,node yy){
	return xx.w < yy.w;
}
int main(Designer = 洛谷@Lwj54joy，uid=845400){
	cin>>n;
	for(int i = 1;i <= n;i++) cin>>a[i];
	for(int i = 1;i <= n;i++) cin>>b[i];
	for(int i = 1;i <= n;i++) e[i] = {min(a[i],b[i]),i};
	sort(e+1,e+1+n,cmp);
	int q[1010] = {0},l = 0,r = n+1;
	for(int i = 1;i <= n;i++)
		if(e[i].w == a[e[i].id]) q[++l] = e[i].id;
		else q[--r] = e[i].id;
	int ta = 0,tb = 0;
	for(int i = 1;i <= n;i++){
		ta += a[q[i]];
		tb = max(ta,tb);
		tb += b[q[i]];
	}
	cout<<tb<<endl;
}
```
### $T5$ 
 - [x] [AccodersP2036 |【一本通提高篇贪心】智力大冲浪](http://www.accoders.com/problem.php?cid=5014&pid=4)
 - [x] [洛谷P1230 | 智力大冲浪](https://www.luogu.com.cn/problem/P1230)  
**思路** ：我们按照每个游戏所扣除的钱降序排序，因为所扣除的钱越大，对答案的影响就越大，我们让每个游戏都在Deadline前一个时间单位做，那它之前的时间就可以分配给其他游戏了，如果它找到可以占用的时间点，那就在数组中标记一下此时间点已被占用，如果它找不到可以占用的时间，那就只能扣钱了。
```cpp
#include <bits/stdc++.h>
using namespace std;

struct node{
	int t,w;
	bool operator<(const node &W) const{
		return w>W.w;
	}
}a[1010];
bool st[1010];
int n,m;
int main(Designer = 洛谷@Lwj54joy，uid=845400){
 	cin>>m>>n;
 	for(int i = 1;i <= n;i++) cin>>a[i].t;
 	for(int i = 1;i <= n;i++) cin>>a[i].w;
	sort(a+1,a+1+n);
	for(int i = 1;i <= n;i++){
		bool flag = false;
		for(int k = a[i].t;k >= 1;k--){
			if(!st[k]){
				flag = true;
				st[k] = 1;
				break;
			}
		}
		if(!flag) m -= a[i].w;
		
	}
	cout<<m<<endl;
} 
```
### $T6$ 
 - [x] [AccodersP2037 | 【一本通提高篇贪心】数列极差](http://www.accoders.com/problem.php?cid=2338&pid=5)    
**思路** ：可以发现，按照小数到大数的顺序跑题目里的公式可以得到最大值，按照大数到小数的顺序可以得到最小值。  
    那我们直接用堆来维护顺序，一个大根堆，一个小根堆，每次弹堆顶的两个数参与运算，运算完毕后再 $push$ 进堆即可。
```cpp
#include <bits/stdc++.h>
using namespace std;
int a[1110100];
int n;
struct cmp1{
	bool operator()(int x,int y){
		return x < y;
	}
};
struct cmp2{
	bool operator()(int x,int y){
		return x > y;
	}
};
int main(Designer = 洛谷@Lwj54joy，uid=845400){
	priority_queue<int,vector<int>,cmp1> q1;	//大根堆
	priority_queue<int,vector<int>,cmp2> q2;    //小根堆 
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
		q1.push(a[i]);
		q2.push(a[i]); 
	} 
	while(q1.size() >= 2){
		int xx = q1.top();	
		q1.pop();
		int yy = q1.top();
		q1.pop();
		q1.push(yy*xx+1);
	}
	while(q2.size() >= 2){
		int xx = q2.top();	
		q2.pop();
		int yy = q2.top();
		q2.pop();
		q2.push(yy*xx+1);
	}
	cout<<q2.top() - q1.top()<<endl;
}
```
### $T7$ 
 - [x] [AccodersP2038 |【一本通提高篇贪心】数列分段](http://www.accoders.com/problem.php?cid=2338&pid=6)
**思路** ：这个应该算是最简单最基础的贪心了，甚至都不用排序，从前往后扫，一旦和大于 $m$ ，再分新的一段
```cpp
#include <bits/stdc++.h>
using namespace std;

int a[101010];
int n,m;
int main(Designer = 洛谷@Lwj54joy，uid=845400){
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	int ans = 1,kkk = 0;
	for(int i = 1;i <= n;i++){
		if(kkk+a[i] <= m) kkk += a[i];
		else kkk = a[i],ans++;
	}
	cout<<ans<<endl;
}
```
### $T8$ 
 - [x] [AccodersP2039 |【一本通提高篇贪心】线段](http://www.accoders.com/problem.php?cid=2338&pid=7)
 - [x] [洛谷P1803 | 凌乱的yyy / 线段覆盖](https://www.luogu.com.cn/problem/P1803)  
**思路：** 跟 $T1$ 除了题面不同外，基本一模一样，按照每条线段的右端点升序排序，扫一遍即可
```cpp
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;

struct node{
	int x,y;
}a[1010010];
int n;
bool cmp(node xx,node yy){
	return xx.y < yy.y;
}
int main(Designer = 洛谷@Lwj54joy，uid=845400){
	cin>>n;
	for(int i = 1;i <= n;i++){
		scanf("%d%d",&a[i].x,&a[i].y );
	}
	sort(a+1,a+1+n,cmp);
	int ans = 1,ls;
	ls = a[1].y;
	for(int i = 2;i <= n;i++){
		if(a[i].x >= ls) ans++,ls = a[i].y;
	}
	cout<<ans;
} 
```
### $T9$ 
 - [x] [AccodersP2041 |【一本通提高篇贪心】钓鱼](http://www.accoders.com/problem.php?cid=2338&pid=9)  
**思路：** 该题的难点主要在最后可在任意湖边停住，而且不能往回走，在一个湖钓鱼时的效率还会越来越少。  
常规的思路看来是不行的了，题目好多动态未知的量，唯有我们更换角度，**“化动为静”**：即然最后不知道停在哪个湖，那就分类讨论呗。  
把停在每个湖的最优解全部求出，在最后取个最优解不就行了吗？  
发现当我们知道主人公最后停在哪个湖后，她的路径也就唯一确定了（例如佳佳最后停在了第i个湖，那么她的路径一定是 $1->2->3->......->i$ ），同时她的纯钓鱼时间可由总空闲时间减去行程时间唯一确定。  
考虑从哪个湖钓鱼一个 $5$ 分钟，就相当于在路径 $1->2->3->......->i$ 中的一个节点上“堆”上一个标记表示在这个湖又钓了 $5$ 分钟的鱼，显然这里可用贪心策略，每次标记目前为止五分钟钓鱼数目最大的那个湖，并使当前记录答案的 $sumi+=$ 在那个湖又钓的鱼数。最后比较所有的 $sumi(i=1,2,...,n)$ 取最大的输出就行了。
```cpp
#include <bits/stdc++.h>
using namespace std;
int n,leisure,fish[200],trip[1010],delta[1010];
struct node{
	int id,key;
	bool operator < (const node &rhs)const{
		return key<rhs.key;
	}
};
int main(Designer = 洛谷@Lwj54joy，uid=845400){
	cin>>n>>leisure;
	leisure *= 12;
	node t;
	int answer = -1;
	for(int i = 1;i <= n;i++){
		cin>>fish[i];
	}
	for(int i = 1;i <= n;i++){
		cin>>delta[i];
	}
	for(int i = 1;i < n;i++){
		cin>>trip[i];
		trip[i] += trip[i-1];
	}
	int lt,ans;
	for(int i = 1;i <= n;i++){
		lt = leisure-trip[i-1],ans = 0;
		priority_queue<node> q;
		for(int j = 1;j <= i;j++) q.push({j,fish[j]});
		for(int j = 1;j <= lt;j++){
			t=q.top();
			q.pop();
			if(t.key < 0) break;
			ans += t.key;
			q.push({t.id,t.key-delta[t.id]});
		}
		answer = max(answer,ans);
	}
	cout<<answer<<endl;
}
```
### $T1$ 
 - [x] [AccodersP2042 |【一本通提高篇贪心】糖果传递](http://www.accoders.com/problem.php?cid=2338&pid=10)  
**思路：** 先以第1号小朋友为起点，算出每个小朋友需要向他后边的小朋友传递的糖果数量。  
考虑如果以第i+1号小朋友为起点，则传递数量为其他传递数量与第i号小朋友向后传递数量的差值。  
那么选传递数量的中位数，就可以得到最小传递数量。
```cpp
#include <bits/stdc++.h>
using namespace std;

int a[1010101];
long long c[1010101];
long long sum,n;
int main(Designer = 洛谷@Lwj54joy，uid=845400){
	cin>>n;
	for(int i = 1;i <= n;i++){
		scanf("%d",&a[i]);
		sum += a[i];
	}
	long long ave = sum/n;
	for(int i = n;i >= 1;i--) c[i] = c[i+1]+ave-a[i];
	c[1] = 0;
	sort(c+1,c+1+n);
	long long ans = 0;
	for(int i = 1;i <= n;i++){
		ans += abs(c[i]-c[(n+1)/2]);
	}
	cout<<ans<<endl;
}
```
# $\huge Thanks.$
---
---
### 感谢阅读，若有问题或错误，欢迎评论（或私信我）。
### 2025 Designed By @洛谷[Lwj54joy，uid=845400](https://www.luogu.com.cn/user/845400)