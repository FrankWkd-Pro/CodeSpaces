# DAY3: DFS搜索与剪枝
$$Designed\ By\ FrankWkd\ -\ Luogu@Lwj54joy,uid=845400$$
特别感谢 此次课的主讲 - Kwling
##  深搜
 - 深度优先搜索（DFS）是一种遍历或搜索树或图的算法，它从一个根节点开始，尽可能深地搜索每个分支，直到找到解为止。在搜索讨程中，为了提高效率，减少不必要的搜索，通常会采用各种剪枝优化策略。
## 剪枝基本思想
 - 在深度优先搜索中，我们通常会遍历图或树的所有节点和边，直到找到解或者遍历完所有节点。然而，某些情况下，我们知道某些路径不会导致有效的解，可以提前停止进一步的搜索，这就是剪枝。通过合理的剪枝策略，我们可以避免不必要的递归和计算极大地提高算法的效率
## 剪枝方法：
 - 最优化剪枝
   - 对应问题：求最优策略或最优答案类题目
   - 如果当前答案比之前记录的已有答案还差的话，就直接减掉。
 - 优化搜索顺序
   - 在一些搜索问题中，搜索树的各个层次、各个分支之间的顺序不是固定的。不同的搜索顺序会产生不同的搜索树形态，其规模大小也相差甚远。
   - 大部分情况下，我们应该优先搜索分支较少的节点，(说白了就是先搜小的分支，因为先搜大的浪费时间，详见[P1223 排队接水](https://www.luogu.com.cn/problem/P1223))
 - 可行性剪枝
   - 在搜索过程中，及时对当前状态进行检查，如果发现分支已经无法到达递归边界，就执行回溯。   
     （某些题目条件的范围限制是一个区间，此时可行性剪枝也被称为 **"上下界剪枝"** ）
 - 记忆化搜索
   - 可以记录每个状态的搜索结果，在重复调历一个状态时直接检索并返回。（就好像我们对图进行深度优先遍历时，标记一个节点是否已经被访问过。
 - 例题：
 - [x] [洛谷P10483 | 小猫爬山](https://www.luogu.com.cn/problem/P10483)

## 剪枝题目思路&代码
### $T1$
 - [x] [AccodersP1862 |【一本通基础搜索与回溯】红与黑](http://www.accoders.com/contest.php?cid=5017&pid=0)  
**思路：** 一道 $DFS$ 经典例题，类似迷宫问题，非常简单，**要注意输入格式是先列后行！**
```cpp
#include <bits/stdc++.h>
using namespace std;
char a[1010][1010];
int n,m;
int ans = 1;
bool f[1010][1010];
void dfs(int x,int y){
    int dx[5] = {0,0,-1,0,1};
    int dy[5] = {0,1,0,-1,0};
    for(int i = 1;i <= 4;i++){
        int xx = x+dx[i],yy = y+dy[i];
        if(xx >= 1 && xx <= m && yy >= 1 && yy <= n && f[xx][yy] == false){
            if(a[xx][yy] == '.'){
                f[xx][yy] = true;
                dfs(xx,yy);
                ans++;
            }
        }
    }
}
int main(Designer = 洛谷@Lwj54joy，uid=845400){
	while(1){
		ans = 1;
		memset(f,false,sizeof(f));
	    cin>>n>>m;
	    if(n == 0 and m == 0) return 0;
	    int x,y;
	    for(int i = 1;i <= m;i++){
	        for(int j = 1;j <= n;j++) {
	            cin>>a[i][j];
	            if(a[i][j] == '@') x = i,y = j;
	        }
	    }
	    dfs(x,y);
	//  for(int i = 1;i <= n;i++){
	//      for(int j = 1;j <= m;j++){
	//          if(f[i][j] && a[i][j] == '.') ans++;
	//      }
	//  }
	    cout<<ans<<endl;
	}
}
```
### $T2$
 - [x] [AccodersP1865 |【一本通基础搜索与回溯】马走日](http://www.accoders.com/problem.php?cid=5017&pid=1)  
**思路：**  $DFS$ 经典例题，暴力就行，**千万注意数据范围是 $0$ ~ $n-1$ ！**
```cpp
#include <bits/stdc++.h>
using namespace std;
int n,m;
int ans;
bool f[1010][1010];
void dfs(int x,int y,int st){
    int dx[15] = {0,1,2,2,1,-1,-2,-2,-1};
    int dy[15] = {0,2,1,-1,-2,-2,-1,1,2};
    if(st == n*m) {ans++;return ;}
    for(int i = 1;i <= 8;i++){
        int xx = x+dx[i],yy = y+dy[i];
        if(xx >= 0 && xx < n && yy >= 0 && yy < m && f[xx][yy] == false){
            f[xx][yy] = true;
            dfs(xx,yy,st+1);
            f[xx][yy] = false;
        }
    }
}
int main(Designer = 洛谷@Lwj54joy，uid=845400){
	int T;
	cin>>T;
	while(T--){
		memset(f,0,sizeof(f));
		ans = 0;
	    cin>>n>>m;
	    int x,y;
	    cin>>x>>y;
	    f[x][y] = 1;
	    dfs(x,y,1);
	    cout<<ans<<endl;
	}
}
```
### $T3$
 - [x] [AccodersP2512 | 【算法进阶 搜索深度优先搜索】小猫爬山](http://www.accoders.com/problem.php?cid=5017&pid=2)
 - [x] [洛谷P10483 | 小猫爬山](https://www.luogu.com.cn/problem/P10483)  
**思路：**  猫猫不可以劈开！猫猫不可以劈开！！猫猫不可以劈开！！！

    如果你看了讨论区，你会发现有一种做法，先加上所有猫的体重然后除以缆车的载重。但是很明显这样有时候猫就会被切开。

    所以正解是 DFS，我们可以把每一辆车上的目前总重量记录下来，然后对于每一只猫枚举每一辆车，要么蹭上一辆车继续 $DFS$ ，要么自己新开一辆车 dfs。也可以再加一个最优性剪枝（即如果当前车数大于已知最优解就直接结束）。我这里还用了一个从大到小排序的优化，因为越小的越容易蹭车，不用开新车嘛。
```cpp
#include<bits/stdc++.h>
using namespace std;
int n,m,a[101],ans,sum[101];
void dfs(int u,int v){
	if(v>=ans) return;
	if(u==n){
		ans=v;
		return;
	}
	for(int i=0;i<v;i++){
		if(sum[i]+a[u]<=m){
			sum[i]+=a[u];
			dfs(u+1,v);
			sum[i]-=a[u];
		}
	}
	sum[v]=a[u];
	dfs(u+1,v+1);
	sum[v]=0;
}
int main(Designer = 洛谷@Lwj54joy，uid=845400){
	cin>>n>>m;
	ans=n;
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n,greater<int>());
	dfs(0,0);
	cout<<ans;
	return 0;
}
```
### $T4$
 - [x] [洛谷P1784 | 数独](https://www.luogu.com.cn/problem/P1784)
 - [ ] [AccodersP2513 |【算法进阶 搜索深度优先搜索】Sudoku](http://www.accoders.com/problem.php?cid=5017&pid=3)
 - [x] [洛谷P1048 | Sudoku](https://www.luogu.com.cn/problem/P10481)  
**思路：**  方阵序号 $=($ 行数 $-1)3\times3+($ 列数 $-1)\div3+1$  
    - **注意！** 行数列数要减 $1$ ，因为 $3$ 的整数倍数除以 $3$ 会比原方阵大 $1$ ，不能满足上述需求。详见[洛谷题解 P1784【数独】](https://www.luogu.com.cn/article/oip0e522)
```cpp
#include <bits/stdc++.h>
using namespace std;
bool is_run;
int sd[11][11];//数独方阵定义 
bool p[11][11],l[11][11],fz[11][11];//行（排），列，方阵。 
void _out(){//输出
    is_run = 0;
	for(int i=1;i<=9;i++){	
  		for(int j=1;j<=9;j++)
			cout<<sd[i][j];
		cout<<endl;
	}
}
void dfs(int x,int y){//深搜
    if(is_run == 0) return ;
	if(sd[x][y]!=0)//如果原来这个位置有数字，跳过。 
		if(x==9&&y==9){
		    _out();//全部填完，输出
		    is_run = 0;
		    return ;
		}else if(y==9)dfs(x+1,1);//当列数为9，搜索下一排。 
		else dfs(x,y+1);//深搜搜下一列
	else//原来的地方没有数字就填充
		for(int i=1;i<=9;i++)
			if((!p[x][i])&&(!l[y][i])&&(!fz[(x-1)/3*3+(y-1)/3+1][i])){//判断是不是重复了
				sd[x][y]=i;//填充 
				p[x][i]=l[y][i]=fz[(x-1)/3*3+(y-1)/3+1][i]=true;//打上标记
				if(x==9&&y==9){
				    _out();//全部填完，输出
				    is_run = 0;
				    return ;
				}else if(y==9)dfs(x+1,1);//填完本行（列），开始搜下一行
				else dfs(x,y+1);//搜下一列 
				sd[x][y]=0; //恢复标记。（回溯） 
				p[x][i]=l[y][i]=fz[(x-1)/3*3+(y-1)/3+1][i]=false;//恢复标记（回溯）
			}
}
int main(Designer = 洛谷@Lwj54joy，uid=845400){
    int T;
    cin>>T;
    while(T--){
        is_run = true;
        memset(sd,0,sizeof(sd));
        memset(p,0,sizeof(p));
        memset(l,0,sizeof(l));
        memset(fz,0,sizeof(fz));
        for(int i=1;i<=9;i++){
    		for(int j=1;j<=9;j++){
    			char tt;
    			cin>>tt;
    			int t = tt-'0';
    			if(t!=0) p[i][t]=l[j][t]=fz[(i-1)/3*3+(j-1)/3+1][t]=true;
    			//填充的不是0的话，表示原来有数字了。打上标记。	
    			sd[i][j]=t;//填充进数独 
    		}	
        }
	    dfs(1,1);//搜
    }
	
	return 0;
}
```

### $T5$
 - [ ] [洛谷P1120 | 小木棍](https://www.luogu.com.cn/problem/P1120)
 - [ ] [AccodersP2514 |【算法进阶 基本数据结构 剪枝】木棒](http://www.accoders.com/problem.php?cid=5017&pid=4)  
**思路：**  
```cpp

```
### $T6$
 - [ ] [AccodersP2517 |【算法进阶 搜索迭代加深】Addition Chains](http://www.accoders.com/problem.php?cid=5017&pid=5)
 - [ ] [洛谷UVA529 | Addition Chains](https://www.luogu.com.cn/problem/UVA529)  
**思路：**  
```cpp

```
### $T7$
 - [x] [洛谷P1731 | 生日蛋糕](https://www.luogu.com.cn/problem/P1731)
 - [ ] [洛谷T148457 | 生日蛋糕数据加强版](https://www.luogu.com.cn/problem/T148457)  
**思路：**  果断DFS，所以怎么去搜呢？

    我们先要解决一个问题：表面积怎么算？数学好的同学已经看出来了，就是每一层的侧面积（S=2pi*r*h）加上最下面一层的底面积（S=pi*r^2），消去pi就好了

    首先建立整体的框架：dfs函数从下往上搜，标记当前的层数、已使用过的总表面积和体积（这个是便于剪枝）、下方一层的半径和高度（因为上面一层需要使用）。从第M层开始搜，到第0层时判断已使用体积是否等于总体积。

    整体框架出来了，但这么打肯定TLE。所以我们要去剪枝。  
    因为蛋糕要上小下大，我们假设第一层（最上面一层）的半径为1，高度为1（不能再小了），那么第二层高度就要为 $2$ ，半径也至少为 $2$，以此类推，那么我们自然可以得出自上而下前 $n$层的最小体积、最小表面积。那么我们每次 $DFS$ 时就可以判断：

    - 如果当前已使用总体积+上方层数的最小体积>输入要求的体积，就直接剪掉；

    - 如果当前已使用总表面积+上方层数的最小表面积>最优解，就直接剪掉（最优化剪枝）。

    - 应用上述剪枝可以跑过 $7$ 个点（ $3$ 个 $TLE$ ）  
    因为我们只对表面积和体积进行了分别判断，而这二者明显是有内在联系的。

    体积 $V=pi\times r\times r\times h$ ，侧面积 $S=2\times pi\times r\times h$ ，可推证出若体积一定，半径越大表面积就越小（相对）

所以我们可以假设剩余的体积全部以当前层的半径做成蛋糕，因为当前的半径的最大的，所以得出的表面积是最小的，根据这个“最小表面积”判断表面积是否超过最优解，超出则剪掉（最优化剪枝）
```cpp
#include<cstdio>
#include<cmath>
#include<algorithm>
#define oo 2147483647
using namespace std;
int NN,M,N,ans=oo;
int ss[21],sv[21];
inline void dfs(int t,int S,int V,int lR,int lH)//层数，已用总面积，已用总体积，上一层半径 ，上一层高度
{
    if (t==0)
    {
        if (V==N) ans=min(ans,S);
        return ;
    }
    if (V+sv[t]>N) return ;//分别对应上述3个剪枝，其中2、3是最优化剪枝 
    if (S+ss[t]>ans) return ;
    if (S+2*(N-V)/lR>ans) return ;
    for (int r=lR-1;r>=t;r--)
    {
        if (t==M) S=r*r;
        int maxh=min((N-V-sv[t-1])/(r*r),lH-1);
        for (int h=maxh;h>=t;h--)
        {
            dfs(t-1,S+2*r*h,V+r*r*h,r,h);
        }
    }
}
int main()
{
    scanf("%d %d",&N,&M);
    for (int i=1;i<=M;i++)
    {
        ss[i]=2*i*i;//计算出每一层的最小侧面积 
        ss[i]+=ss[i-1];//要求前缀和 
        sv[i]=i*i*i;//最小体积 
        sv[i]+=sv[i-1];//要求前缀和 
    }
    dfs(M,0,0,sqrt(N),N);//第一层的高度最小为1，所以半径最大就是根号N 
    if (ans==oo) printf("0");
    else printf("%d",ans);
    return 0;
}
```
### $T8$
 - [AccodersP2055 |【一本通提高篇深搜的剪枝技巧】埃及分数](http://www.accoders.com/problem.php?cid=2336&pid=5)
 - [洛谷P1763 | 埃及分数](https://www.luogu.com.cn/problem/P1763)
**思路：** 参考[此题解](https://www.luogu.com.cn/article/9qy8qni9)
```cpp
todo
```
### $T9$
- [ ] [洛谷P1074 | [NOIP2009]靶形数独](https://www.luogu.com.cn/problem/P1074)  
**思路：**  
```cpp
todo
```
# $\huge Thanks.$
---
---
### 感谢阅读，若有问题或错误，欢迎评论（或私信我）。
### 2025 Designed By @洛谷[Lwj54joy，uid=845400](https://www.luogu.com.cn/user/845400)