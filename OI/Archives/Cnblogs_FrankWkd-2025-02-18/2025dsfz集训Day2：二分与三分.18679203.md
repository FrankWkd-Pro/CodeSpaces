# DAY2：二分与三分
$$Designed\ By\ FrankWkd\ -\ Luogu@Lwj54joy,uid=845400$$
特别感谢 此次课的主讲 - Kwling
## 二分概述
 - 二分法，在一个单调有序的集合或函数中查找一个解，每次分为左右两部分，判断解在那个部分并调整上下界，直到找到目标元素，每次二分都将舍弃一般的查找空间，因此效率很高。

## 二分常见模型
- 二分答案  
    最小值最大（或是最大值最小）问题，这类双最值问题常常选用二分法求解，也就是确定答案后，配合贪心，$DP$ 等其他算法检验这个答案是否合理，将最优化问题转化为判定性问题。例如，将长度为 $n$ 的序列 $a_i$ 分为最多 $m$ 个连续段，求所有分法中每段和的最大值的最小是多少？

- 二分查找  
用具有单调性的布尔表达式求解分界点，比如在有序数列中求数字 $x$ 的排名。

- 代替三分(?存疑)  
有时，对于一些单峰函数，我们可以用二分导函数的方法求解函数的极值，这时通常将函数的定义域定义为整数域求解比较方便，此时 $d_x$ 可以直接去整数 $1$ 。

## 二分使用范围：
- 必须具备单调性或者是二段性

 

参考leetcode暑假打卡活动2019——week1中

视频链接：传送门

写二分的过程：

　　1、确定二分边界

　　2、编写二分的代码框架

　　3、设计一个check（性质）

　　4、判断一下区间如何更新

　　5、如果更新方式是 L = Mid ， R = Mid - 1 ，那么在算mid时要加1
## 二分查找

- 手写二分【模版】
  - 记得将无序数组变得有序！
  - 记得考虑无解的情况。
  - ```cpp
    #include <bits/stdc++.h>
	using namespace std;
	int target,n;
	int a[1010001]; 
	int main(Designer = 洛谷@Lwj54joy，uid=845400){
		cin>>n>>target;
		for(int i = 1;i <= n;i++){
			cin>>a[i];
		}
		int l = 1,r = n;
		while(l <= r){
			int mid = l+r>>1;
			if(a[mid] < target) l = mid+1;
			else r = mid-1;
		}
		if(a[l] != target) cout<<-1<<endl;
		else cout<<l<<endl;
		
	}
    ```
- 函数二分【模版】
  - 直接用`lower_bound`求左边界，超级短。
  - ```cpp
    #include <bits/stdc++.h>
	using namespace std;
	
	int n,target;
	int a[1010001]; 
	int main(Designer = 洛谷@Lwj54joy，uid=845400){
		cin>>n>>target;
		for(int i = 1;i <= n;i++) cin>>a[i];
		if(binary_search(a+1,a+1+n,target) == true){
			int answer = lower_bound(a+1,a+1+n,target)-a;
			cout<<answer<<endl;
		}
		
	}
    ```
## 二分题目解法&思路

### $T1$ 
 - [x] [洛谷P2249 |【深基13.例1】查找](https://www.luogu.com.cn/problem/P2249)  
**思路：** 直接二分套模版
```cpp
#include <bits/stdc++.h>
	using namespace std;
	
	int n;
	int target,times;
	int a[1010001]; 
	int main(Designer = 洛谷@Lwj54joy，uid=845400){
		scanf("%d%d",&n,&times);
		for(int i = 1;i <= n;i++){
			scanf("%d",&a[i]);
		}
		while(times--){
			scanf("%d",&target);
			int l = 1,r = n;
			while(l <= r){
				int mid = l+r>>1;
				if(a[mid] < target) l = mid+1;
				else r = mid-1; 
			}
			if(a[l] != target) printf("-1 ");
			else printf("%d ",l);
		}
		
	}
```
### $T2$ 
 - [x] [AccodersP2046 |【一本通提高篇二分与三分】数列分段II](http://www.accoders.com/problem.php?cid=5015&pid=0)
 - [x] [洛谷P1182 |	数列分段 Section II](https://www.luogu.com.cn/problem/P1182)  
**思路：** 其实和`数列分段I`相比就多了个二分答案，判断过程都是一样的,需要吸氧（O2）
```cpp
#include <bits/stdc++.h>
using namespace std;

int n,l = INT_MIN,r,m;
int a[1010001]; 

bool check(int mid){
	int tot = 0;
	int times = 1;
	for(int i = 1;i <= n;i++){
		if(tot+a[i] <= mid) tot += a[i];
		else tot = a[i],times++;
	}
		return times <= m;
	}
	
	int main(Designer = 洛谷@Lwj54joy，uid=845400){
		cin>>n>>m;
		for(int i = 1;i <= n;i++){
			cin>>a[i];
			l = max(l,a[i]);
			r += a[i];
		}
		while(l <= r){
			int mid = l+r>>1;
			if(check(mid)) r = mid-1;
			else l = mid+1;
		}
		cout<<l<<endl;
		
	}
```
### $T3$ 
 - [x] [AccodersP1902 |【一本通基础分治】河中跳房子](http://www.accoders.com/problem.php?cid=5015&pid=1)  
**思路：** 二分房子之间的距离
```cpp
	#include <bits/stdc++.h>
	using namespace std;
	int L,n,m;
	int a[2101010];
	int ans;
	inline bool check(int mid){
		int times = 0,ip = 0;
		for(int i = 1;i <= n+1;i++){
			if(a[i]-a[ip] < mid){
				times++;
				if(times > m) return false;
			}else ip = i;
		}
		return times <= m;
	}
	int main(Designer = 洛谷@Lwj54joy，uid=845400){
		cin>>L>>n>>m;	
		a[n+1] = L;
		int l = 1,r = L;
		for(int i = 1;i <= n;i++){
			cin>>a[i];
			l = min(l,a[i]-a[i-1]);
		}
		l = min(l,L-a[n]);
		while(l <= r){
			int mid = l+r>>1;
			if(check(mid)){
				l = mid+1;
			}else r = mid-1;
		}
		cout<<l-1<<endl;
		
	}
```
### $T4$ 
 - [x] [AccodersP2043 |【一本通提高篇二分与三分】愤怒的牛](http://www.accoders.com/problem.php?cid=5015&pid=2)  
**思路：** 很经典的二分答案，与跳石头类似，二分每个牛棚之间的最短距离，枚举判断答案是否合法
```cpp
#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[2101010];
int ans;
inline bool check(int mid){
	int dis = a[1],mm = 1;
	for(int i = 2;i <= n;i++){
		if(a[i]-dis >= mid){
			mm++;
			dis = a[i];
		}
	}
	return mm >= m;
}
int main(Designer = 洛谷@Lwj54joy，uid=845400){
	cin>>n>>m;
	int l = 1,r = -99;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i = 1;i <= n;i++){
		l = min(l,a[i]-a[i-1]);
	}
	r = a[n]-a[1];
	while(l <= r){
		int mid = l+r>>1;
		if(check(mid)){
			l = mid+1;
		}else r = mid-1;
	}
	cout<<l-1<<endl;
	
}
```
### $T5$ 
 - [x] [AccodersP2044 |【一本通提高篇二分与三分】Best Cow Fences](http://www.accoders.com/problem.php?cid=5015&pid=3)
 - [x] [洛谷P10450 | [USACO03MAR] Best Cow Fences G](https://www.luogu.com.cn/problem/P10450)   
**思路：** 依然是二分答案，但由于扯上了浮点数，所以还要维护精度，这样操作就麻烦了起来，二分出平均数，枚举，记录每个数与平均数的差值，求一个和，如果这个和 $≥$ $0$ ，那么这个答案就是合法的，只要这个答案对一个区间合法即可，因为题目中说的是是否存在，有一个合法，那就是存在，其他就是精度处理问题了
```cpp
#include <bits/stdc++.h>
using namespace std;
int a[101010],n,L;
double b[101010];
int main(Designer = 洛谷@Lwj54joy，uid=845400){
	cin>>n;
	cin>>L;
	int maxx = 0;
	for(int i = 1;i <= n;i++) cin>>a[i],maxx = max(maxx,a[i]);
	double l = 0,r = maxx*1.0,mid;
	while(r-l > 1e-5){
		mid = (l+r)/2;
		for(int i = 1;i <= n;i++) 
		b[i] = (b[i-1]+a[i]*1.0-mid)*1.0;
		double ans = 0;
		bool fl = 0;
		for(int i = L;i <= n;i++){
			ans = min(ans,b[i-L]);
			if(b[i]-ans >= 0.0){
				fl = 1;
				break;
			}
		}
		if(fl == 1) l = mid;
		else r = mid;
	}
	cout<<(int)(r*1000)<<endl;
}
```
### $T6$ 
 - [x] [AccodersP2047 |【一本通提高篇二分与三分】扩散](http://www.accoders.com/problem.php?cid=5015&pid=6)  
 - [x] [洛谷P1661 | 扩散](https://www.luogu.com.cn/problem/P1661)  
**思路：**  
一想到大数据的联通块，绝对是并查集。  
那么，题中联通的定义也就转化成了：这些点具有相同的公共祖先。即：  

    $F[find(i)] == k$

    其中， $k$ 为常量， $i$ 为 $1-n$ 中的任意值。  
    那么，仔细想想就能想得到，直接二分扩散时间。因为每个点都在扩散，那么两点之间的曼哈顿距离必须小于等于扩散时间乘 $2$ 才能保证两点在扩散中相遇。
    在 $check$ 函数中，我们直接暴力枚举每个点，如果在 $mid$ 时间及以前能够相遇，就在并查集中合并二者。最后，如果所有的点拥有相同的公共祖先，即 $F[find(i)] == k$ ，就可以返回 $true$ 了。
```cpp
#include <bits/stdc++.h>
using namespace std;
struct node{
    int x,y;
}a[1010101];
int f[1010101][2];
int n;

int find(int x){
    if(f[x][0] != x) return f[x][0] = find(f[x][0]);
    return x;
}

void merge(int x,int y){
    f[find(x)][0] = f[find(y)][0];
    f[find(y)][1] += f[find(x)][1];
}

bool check(int x){
    for(int i = 1;i <= n;i++){
        for(int j = i+1;j <= n;j++){
            if(abs(a[i].x-a[j].x)+abs(a[i].y-a[j].y) <= x*2 and find(i) != find(j)) merge(i,j);
        }
    }
    int k = find(1);
    for(int i = 2;i <= n;i++){
        if(find(i) != k) return false;
    }
    return true;
}

int main(Designer = 洛谷@Lwj54joy，uid=845400){
    cin>>n;
    for(int i = 1;i <= n;i++){
        cin>>a[i].x>>a[i].y;
    }
    int l = 0,r = 1e9;
    while(l <= r){
        for(int i = 1;i <= n;i++) f[i][0] = i,f[i][1] = 1;
        int mid = l+r>>1;
        if(check(mid)) r = mid-1;
        else l = mid+1;
    }
    cout<<l<<endl;
}
```
## 三分
- 三分算法（Ternary Search Algorithm）是一种用于在单峰函数中寻找极值的优化算法。它通过将搜索区间分为三个部分并比较函数在两个划分点的取值，逐步缩小搜索范围来确定极值的位置。（求解带曲线的多次函数）

 - 三分算法的基本思路如下：

    1. 初始化搜索区间，通常是整个定义域的区间。

    2. 将搜索区间分为三个部分，通常采用两个划分点将整个区间分成三等份。

    3. 计算两个划分点的函数取值。

    4. 比较两个划分点的函数取值，如果其中一个划分点的函数值更大（或更小），则极值在该划分点的同侧。

    5. 根据比较结果更新搜索区间，将较小（或较大）的划分点所在的区间作为新的搜索区间。

    6. 重复步骤3到步骤5，直到搜索区间足够小，或达到一定的迭代次数。

    7. 返回搜索区间的中点作为极值的近似位置。

三分算法的时间复杂度为 $O(logN)$ ，其中 $N$ 为搜索区间的长度。它的优势在于可以在单峰函数中快速找到极值的位置，但不适用于非单调函数或多峰函数的寻优问题。
## 三分题目解法&思路
### $T1$ 
 - [x] [洛谷P1883 |【模板】三分 | 函数](https://www.luogu.com.cn/problem/P1883)   
    **思路：**  
    观察题目图像得 $F(x)$ 函数是一个下凸函数。即对于任意的 $x1<x2<x3$ ，  
    不存在 $F(x1)<F(x2)>F(x3)$ ，根据这个定义，我们可以通过三分法求该函数的最值。
    
    随便画出二次函数的一段（二次函数是一个特殊的下凸函数），  
    我们发现一个下凸函数其上四个点无非有以下几种情况：
     
    设下凸函数上四个点横坐标分别为 $x1<x2<x3<x4$ ，  
    并且我们已经确定该函数的最小值在 $[x1,x4]$ 之间
    
    若F(x1)<F(x2)，则函数的最小值的x的取值范围一定在[x1,x2]之间，因为根据定义，  
    若有 $F(x1)<F(x2)$ ，必有 $F(x1)<F(x2)<F(x3)<F(x4)$ ；
    
    若 $F(x3)>F(x4)$ ，同理可得，函数最小值的取值范围一定是在 $[x3,x4]$ 之间。  
    
    若 $F(x1)>F(x2)\ \&\ F(x2)<F(x3)$ ，  
    则函数的最小值的 $x$ 的取值范围一定在 $[x1,x3]$ 之间，  
    因为下凸函数有且仅有一个低谷，并且下凸函数的最小值在低谷中。
    
    若 $F(x4)>F(x3)\ \&\ F(x3)<F(x2)$，  
    同理，函数最小值的取值范围一定在 $[x2,x4]$ 之间。
     
    最后就只剩下一种情况了，此时函数最小值的取值范围一定在 $[x2,x3]$ 之间。
```cpp
#include <bits/stdc++.h>
	using namespace std;
	int n;
	double a[101010],b[101010],c[101010];
	double f(double x){
		double mx = -1e9;
		for(int i = 1;i <= n;i++) mx = max(mx,a[i]*x*x+b[i]*x+c[i]);
		return mx;
	}
	int main(Designer = 洛谷@Lwj54joy，uid=845400){
		int T;
		cin>>T;
		while(T--){
			scanf("%d",&n);
			for(int i = 1;i <= n;i++) scanf("%lf%lf%lf",&a[i],&b[i],&c[i]);
			double l = 0,r = 1000;
			while(r-l>1e-11){
				double m1 = l+(r-l)/3,m2 = r-(r-l)/3;
				if(f(m1) <= f(m2)) r = m2;
				else l = m1;
			}
			printf("%.4lf\n",f(r));
		}
	}
```
### $T2$ 
 - [x] [AccodersP2045 |【一本通提高篇二分与三分】曲线](http://www.accoders.com/problem.php?cid=5015&pid=4)  
**思路：** 由于函数 $S$ 是开口向上的二次函数(当 $a=0$ 时，是一次函数)，由 $S$ 的定义可知，$S$ 或者是一个先单调减、后单调增的下凸函数，或者是一个单调函数，$F(x)=max(S_x)$ 也满足单调性。选用三分法很容易求得某个区间内的最小值。
```cpp
#include <bits/stdc++.h>
	using namespace std;
	int n;
	double a[101010],b[101010],c[101010];
	double f(double x){
		double mx = -1e9;
		for(int i = 1;i <= n;i++) mx = max(mx,a[i]*x*x+b[i]*x+c[i]);
		return mx;
	}
	int main(Designer = 洛谷@Lwj54joy，uid=845400){
		int T;
		cin>>T;
		while(T--){
			scanf("%d",&n);
			for(int i = 1;i <= n;i++) scanf("%lf%lf%lf",&a[i],&b[i],&c[i]);
			double l = 0,r = 1000;
			while(r-l>1e-11){
				double m1 = l+(r-l)/3,m2 = r-(r-l)/3;
				if(f(m1) <= f(m2)) r = m2;
				else l = m1;
			}
			printf("%.4lf\n",f(r));
		}
	}
```
### $T3$ 
 - [x] [AccodersP2048 |【一本通提高篇二分与三分】灯泡](http://www.accoders.com/problem.php?cid=5015&pid=5)
 - [x] [洛谷P5931 | [清华集训2015]灯泡](https://www.luogu.com.cn/problem/P5931)   
**思路：**  
首先可以分两种情况:  
（1）有影子在墙上  
（2）没有影子在墙上  
没有影子在墙上的时候，通过计算可以得出当光线照在墙角的时候最大。  
设人到墙的距离为 $x$  
这个时候我们可以得到 $x$ 的上界 $h * D / H$ （相似）  
这个时候就可以合并到第一种情况。  
第一种情况可以推出影子长度 $L = x + (D * h - x * H) / (D - x)$  
不需要化简，只要在程序中可以算出就行了。  
有某个 $x$ 是最大的。  
果然，有最值。
```cpp
	#include <bits/stdc++.h>
	using namespace std;
	int t;
	double hb,h,d;
	double f(double x){
		double l = hb-(d*(hb-h)/x);
		return d-x+l;
	}
	int main(Designer = 洛谷@Lwj54joy，uid=845400){
		cin>>t;
		while(t--){
			cin>>hb>>h>>d;
			double l = d-(h*d/hb),r = d;
			while(r-l >= 1e-5){
				double m1 = l+(r-l)/3,m2 = r-(r-l)/3;
				if(f(m1) < f(m2)) l = m1;
				else r = m2;
			}
			printf("%.3lf\n",f(r));
		}	
	}
```
# $\huge Thanks.$
---
---
### 感谢阅读，若有问题或错误，欢迎评论（或私信我）。
### 2025 Designed By @洛谷[Lwj54joy，uid=845400](https://www.luogu.com.cn/user/845400)