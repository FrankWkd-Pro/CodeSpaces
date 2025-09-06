## DAY4: BFS及其优化
$$Designed\ By\ FrankWkd\ -\ Luogu@Lwj54joy,uid=845400$$
特别感谢 此次课的主讲 - Kwling
## BFS
 - 广度优先搜索（Breadth - First - Search）是一种图形数据结构的遍历算法。它从给定的起始顶点开始，首先访问起始顶点的所有邻接顶点，然后再依次访问这些邻接顶点的邻接顶点，以此类推，一层一层地向外扩展，直到遍历完整个图或者找到目标顶点。
 - $BFS$ 的空间优化：使用循环队列来存储元素，能最大限度地压缩空间（虽然一般用不到）
## BFS应用
  - **联通块相关问题**
  - **（迷宫）矩阵问题**
    - 将一个点作为迷宫中的一个点
  - **特殊的最短路问题**
  - **状态转换型问题**
    - 将一个状态对应迷宫中的一个点
## BFS优化方法
 - 双向广度优先搜索 $(Bidirectional BFS)$
   - 原理：  单向的 $BFS$ 是从起始节点开始一层一层地向外扩展，直到找到目标节点。而双向 $BFS$ 同时从起始节点和目标节点开始进行广度优先搜索。这样可以大大减少搜索的空间和时间复杂度，尤其是在起始节点和目标节点距离较远的情况下。
 - 启发式搜索与 $BFS$ 结合（如 $A^*$ 算法）
    - 原理：$BFS$ 是一种盲目搜索算法，它在搜索过程中没有利用任何关于目标位置的信息。$A^*$ 算法是一种启发式搜索算法，它在 $BFS$ 的基础上，通过一个启发函数来估计从当前节点到目标节点的代价。
    - 启发函数一般形式为 $f(n) = g(n)+h(n)$ ，其中 $g(n)$ 是从起始节点到当前节点 $n$ 的实际代价，$h(n)$ 是从当前节点 $n$ 到目标节点的估计代价。在搜索过程中，优先扩展 $f(n)$ 值较小的节点。
- 利用位运算优化存储和访问（在某些特定场景下）  
   - 原理：在一些图的表示中，如果节点数量有限且相对较小，可以使用位运算来优化存储。例如，对于一个有 $n$ 个节点的图，用一个整数的二进制位来表示每个节点是否被访问。如果第 $i$ 位为 $1$，则表示第 $i$ 个节点被访问，为 $0$ 则表示未访问。
同样，在邻接矩阵表示的图中，位运算可以用于快速判断两个节点之间是否有边。
## BFS题目思路&解法
### $T1$
 - [x] [AccodersP2065 | 【一本通提高篇广搜的优化技巧】山峰和山谷](http://www.accoders.com/problem.php?cid=5018&pid=0)  
**思路：** 直接开 $BFS$ ，用两个 $bool$ 类型的变量 $s,t$ 记录是否有比它高的山峰/比它低的山谷，如果 $s=false$ ,表示没有比它高的山峰，即代表它就是山峰。$t$ 同理。
```cpp
#include <bits/stdc++.h>
using namespace std;
int a[1010][1010];
bool f[1010][1010]; 
struct node{
	int x,y;
};
queue <node> q;
int feng,gu,n;
bool h,l;
int dx[9] = {0,-1,-1,-1,0,1,1,1,0};
int dy[9] = {0,-1,0,1,1,1,0,-1,-1};
void bfs(int xxx,int yyy){
	f[xxx][yyy] = 1;
	q.push({xxx,yyy});
	while(!q.empty()){
		node t = q.front();
		q.pop();
		for(int i = 1;i <= 8;i++){
			int xx = t.x+dx[i],yy = t.y+dy[i];
			if(xx >= 1 and xx <= n and yy >= 1 and yy <= n)
				if(a[xx][yy] > a[t.x][t.y]) h = 1;
				else if(a[xx][yy] < a[t.x][t.y]) l = 1;
				else if(a[xx][yy] == a[t.x][t.y] and !f[xx][yy]){
					f[xx][yy] = 1;
					q.push({xx,yy});
				}
		}
	}
}

int main(){
	cin>>n;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			cin>>a[i][j];
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			if(!f[i][j]){
				h = l = 0;
				bfs(i,j);
				if(!h) feng++;//周围没有比我高的了 
				if(!l) gu++;//周围没有比我低的了 
			}
		}
	}
	cout<<feng<<" "<<gu<<endl;
}
```
### $T2$
 - [x] [AccodersP9084 | 武士风度的牛](http://www.accoders.com/problem.php?cid=5018&pid=1)  
**思路：** 经典 $BFS$ 题，暴力就行，在 $queue$ 数组里再开一列用于记录从起点走到终点的步数。 **注意：此题先输入列，再输入行**
```cpp
#include<bits/stdc++.h>
using namespace std;
int t,tx,ty;
char a[1010][1010];
bool f[1005][1005];
int dx[9]={0,1,1,2,2,-1,-1,-2,-2};
int dy[9]={0,2,-2,1,-1,2,-2,1,-1};
struct node{
	int aa,bb,cc;
};	
int n,m;
int bfs(int tx,int ty){
	queue<node> q;
	q.push({tx,ty,0});
	f[tx][ty]=1;
	while(!q.empty()){
		int x=q.front().aa,y=q.front().bb,st = q.front().cc;
		if(a[x][y] == 'H') return st;
		q.pop();
		for(int i=1;i<=8;i++){
			int xx=x+dx[i],yy=y+dy[i];
			if(xx>=1 && xx<=n && yy>=1 && yy<=m && !f[xx][yy] and a[xx][yy] != '*'){
				q.push({xx,yy,st+1});
				f[xx][yy]=1;
				if(a[xx][yy] == 'H') return st+1;
			}
		}
	}
	return -1;
}

int main(){

	cin>>m>>n;
	int s,t;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			cin>>a[i][j];
			if(a[i][j] == 'K') s = i,t = j;
		}
	}
	cout<<bfs(s,t)<<endl;
	return 0;
}
```
### $T3$
 - [x] [AccodersP1912 |【一本通基础广度优先搜索】迷宫问题](http://www.accoders.com/problem.php?cid=5018&pid=2)  
**思路：** 经典 $BFS$ 题，暴力就行，在 $queue$ 数组里再开一列用于记录此点从哪一个点走来。
```cpp
#include <iostream>
#include <cstring> 
using namespace std;
int h[37][3],b[26];   
int xx[4]={-1,1,0,0},yy[4]={0,0,-1,1};
bool a[6][6];    //矩阵+标记数组 
int main()
{
    memset(a,true,sizeof(a));
    int tmp;
    for(int i=0;i<5;i++)    //输入处理，从0,0开始 
    for(int j=0;j<5;j++)
    {
        cin>>tmp;
        if(tmp==1) a[i][j]=false;   
    }
    int t=0,w=1,x,y;        //入队初始化 
    h[1][1]=0,h[1][2]=0;
    a[0][0]=false;
    bool boo=true;
    do
    {
        t++;
        for(int i=0;i<4;i++)
        {
            x=h[t][1]+xx[i];
            y=h[t][2]+yy[i];
            if(x>=0&&x<5&&y>=0&&y<5&&a[x][y])
            {
                w++;
                h[w][1]=x;
                h[w][2]=y;
                h[w][0]=t;       //记录路径上一步下标 
                a[x][y]=false;
                if(x==4&&y==4) // 到达终点 
                {
                    boo=false;
                    break;
                }
            }
        }
    }while(t<w&&boo);
    int k=0;    //记录路径在h队列里的下标 
    while(w>=1)
    {
        k++;
        b[k]=w;
        w=h[w][0];
    }
    for(int i=k;i>=1;i--)   //逆序输出正序的路径 
        cout<<"("<<h[b[i]][1]<<", "<<h[b[i]][2]<<")"<<endl;
    return 0;
}
```
### $T4$
 - [x] [AccodersP1520 |【算法进阶 搜索广度优先搜索】矩阵距离](http://www.accoders.com/problem.php?cid=5018&pid=3)  
**思路：**
本题可以看做一道有多个起始状态的 $flood-fill$ 。我们把矩阵 $A$ 中每一个 $1$ 都看做起点，整个矩阵的所有位置都可以通行，对于每个位置，在从任何一个起点出发都可以的情况下，求到达该位置所需要的最少步数（也就是距离该位置最近的期待你的距离）
在这种具有多个等价的起始状态的问题中、我们只需要在 $BFS$ 开始方前把这些起始状态全部插入队列，根据 $BFS$ 逐层搜索的性质， $BFS$ 的过程就相当于每个起点先扩展 $1$ 层，再扩展 $2$ 层， $3$ 层，以此类推。所以当每个位置 $(x,y)$ 第一次被访问时，就相当于距离它最近的那个起点扩展到了它，此时从那个起点到 $(x,y)$ 经历的步数就是最短距离 $B[x][y]$ 。
```cpp
#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
typedef pair<int, int> PII;
const int N = 1010, M = N * N;

int n, m;
char g[N][N];
PII q[M];
int dist[N][N];

int dx[] = {-1, 0, 1, 0}; // 上右下左
int dy[] = {0, 1, 0, -1}; // 上右下左

void bfs() {
    memset(dist, -1, sizeof dist);
    int hh = 0, tt = -1;
    // 将所有位置是1的位置，也就是哈密尔顿距离为0的入队列
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (g[i][j] == '1') {
                dist[i][j] = 0;   // 标识距离为0，一是为了显示最终的结果，二来也有防止走回头路的作用
                q[++tt] = {i, j}; // 入队列
            }

    while (hh <= tt) {
        PII t = q[hh++];
        for (int i = 0; i < 4; i++) {
            int x = t.x + dx[i], y = t.y + dy[i];
            if (x < 1 || x > n || y < 1 || y > m) continue;
            if (~dist[x][y]) continue;
            dist[x][y] = dist[t.x][t.y] + 1;
            q[++tt] = {x, y};
        }
    }
}

int main() {
    cin >> n >> m;

    // 放过0行和0列,这个+1用的妙，一行行读入，每一行从下标1的列号开始
    // 原理就是读入到 g[i]这一行数据的地址中，并且需要偏移一个位置的地址,联想一下 scanf("%d",&a);的含义进行记忆理解
    for (int i = 1; i <= n; i++) cin >> g[i] + 1;
    // 宽搜
    bfs();

    // 输出结果矩阵
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            printf("%d ", dist[i][j]);
        puts("");
    }
    return 0;
}

```
### $T5$
 - [x] [AccodersP2060 |【一本通提高篇广搜的优化技巧】 魔板](http://www.accoders.com/problem.php?cid=2335&pid=1)
 - [x] [洛谷P2730	| [USACO3.2] 魔板 Magic Squares](https://www.luogu.com.cn/problem/P2730)  
**思路：** 用 $BFS$ 遍历所有情况，用map（unordered_map也行，会更快）记录这个魔板状态是否出现过。
```cpp
#include<bits/stdc++.h>
using namespace std;
const int ten[10]={1,10,100,1000,10000,100000,1000000,10000000};
struct node{int key,step,previd,way;}k[100000];
inline int A(int k){return (k/10000)+(k%10000)*10000;}
inline int B(int k){
	int ll=k/10000,rr=k%10000;
	ll=(ll%10)*1000+ll/10;
	rr=(rr%10)*1000+rr/10;
	return ll*10000+rr;
}
inline int C(int k){
	int a=k/ten[7]%10;
	int b=k/ten[6]%10;
	int c=k/ten[5]%10;
	int d=k/ten[4]%10;
	int e=k/ten[3]%10;
	int f=k/ten[2]%10;
	int g=k/ten[1]%10;
	int h=k/ten[0]%10;
	return a*ten[7]+f*ten[6]+b*ten[5]+d*ten[4]+e*ten[3]+g*ten[2]+c*ten[1]+h;
}
map<int,int> st;
char ans[2009];
int cnt=0;
void show(int id){
	if(k[id].previd==-1)return;
	show(k[id].previd);
	ans[++cnt]=(char)k[id].way;
}
void bfs(int sx,int fx){
	int ff=1,tt=0;
	k[++tt]={sx,0,-1,-1};
	st[sx]=114514;
	while(ff<=tt){
		int key=k[ff].key,previd=ff,step=k[ff++].step+1;
		int a=A(key),b=B(key),c=C(key);
		if(st[a]!=114514){
			st[a]=114514;
			k[++tt]={a,step,previd,(int)'A'};
			if(a==fx){
				printf("%d\n",step);
				show(tt);
				return;
			}
		}
		if(st[b]!=114514){
			st[b]=114514;
			k[++tt]={b,step,previd,(int)'B'};
			if(b==fx){
				printf("%d\n",step);
				show(tt);
				return;
			}
		}
		if(st[c]!=114514){
			st[c]=114514;
			k[++tt]={c,step,previd,(int)'C'};
			if(c==fx){
				printf("%d\n",step);
				show(tt);
				return;
			}
		}
	}
}
int main(){
	st.clear();
	int t=0,x,lable[10];
	for(int i=1;i<=8;i++)scanf("%d",&lable[i]);
	t=lable[1]*ten[7]+lable[2]*ten[6]+lable[3]*ten[5]+lable[4]*ten[4]+lable[8]*ten[3]+lable[7]*ten[2]+lable[6]*ten[1]+lable[5]*ten[0];
	if(t==12348765)puts("0"),exit(0);
	bfs(12348765,t);
	for(int i=1,it=1;i<=cnt;i++,it++){
		putchar(ans[i]);
		if(it==60)it=0,puts("");
	}
	return 0;
} 
```
### $T6$
 - [x] [AccodersP3176 | NOIP 2017 棋盘](http://www.accoders.com/problem.php?cid=5018&pid=6)
 - [x] [洛谷P3956 | [NOIP2017 普及组] 棋盘](https://www.luogu.com.cn/problem/P3956)  
**思路：** 跑 $BFS$ ,建立一个 $ans$ 数组，其中，$ans[i][j]$ 表示从 $1,1$ 到 $i,j$ 的最小花销，跑 $BFS$ 的时候每次遇到合法的点就更新一下 $ans$ 数组的值。
```cpp
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int N = 1010;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

struct node {
	int x, y, color, magic, money;
	//color：当前点的颜色
	//magic：是否站在使用了魔法的点上
	//money：当前花销
};

int m, n, color[N][N], ans[N][N];
//color：存储点的颜色
//ans：为记忆化搜索而生的存储每个点花销的数组


void bfs() {
	queue<node> q;
	q.push({1, 1, color[1][1], 0, 0});//起点入队
	ans[1][1] = 0;//花销为零
	while (!q.empty()) {//跑BFS
		node p = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int x1 = p.x + dx[i], y1 = p.y + dy[i];
			if (x1 < 1 || x1 > m || y1 < 1 || y1 > m || (p.magic && color[x1][y1] == 0/*如果站在了使用魔法的点上，就不能使用魔法*/))//最优性剪枝
				continue;
			node next = {x1, y1, 0, 0, 0};
			int cost; //这一次花费的金币数
			if (color[x1][y1] > 0) {
				// 第一种：下一个点有颜色
				if (color[x1][y1] == p.color) cost = 0;
				else cost = 1;//花1块钱走到x1,y1
				// 没有使用魔法，下一个点的颜色就是color[x1][y1]
				next.magic = 0;
				next.color = color[x1][y1];
			} else {
				// 第二种：下一个点没有颜色
				cost = 2;
				next.magic = 1;
				next.color = p.color;
				// 使用过魔法，下一个点的颜色为当前点的颜色时最优
			}
			next.money = cost + p.money;// 加上之前的金币数
			if (next.money < ans[x1][y1]) {//最优性剪枝（记忆化）
				ans[x1][y1] = next.money;//更新最小花销
				q.push(next);//入队
			}
		}
	}
}

int main() {
	cin >> m >> n;
	for (int i = 1; i <= n; i++) {
		int x, y, c;
		cin >> x >> y >> c;
		// 0就表示没有颜色了
		color[x][y] = c + 1;
	}
	memset(ans, 0x3f3f3f3f, sizeof(ans));
	bfs();
	cout << (ans[m][m] == 0x3f3f3f3f ? -1 : ans[m][m]) << endl;
	return 0;
}
```
### $T7$
 - [x] [AccodersP2059 |【一本通提高篇广搜的优化技巧】电路维修](https://www.luogu.com.cn/problem/P4667)
 - [x] [洛谷P4667 | [BalticOI 2011 Day1] Switch the Lamp On 电路维修](https://www.luogu.com.cn/problem/P4667)    
**思路：** $BFS$ + 最优化剪枝 + 双端队列：因为转弯的情况比不转弯的情差，所以得出转弯的情况时放到队尾，遇到不转弯的情况时放到队头，可以先判断。（$Priority\_queue$ 应该也差不多）
```cpp
#include<bits/stdc++.h>
using namespace std;
int dx[4] = {1, -1, -1, 1};
int dy[4] = {1, 1, -1, -1};
char a[5] = "\\/\\/";
int ix[4] = {0, -1, -1, 0};
int iy[4] = {0, 0, -1, -1};
deque <int> x;
deque <int> y;
char mp[505][505]; //存地图
int vis [505][505]; //记录最短步数
int l, c; //l:line行数，c:column列数
void dfs() {
	memset(vis, 0x3f, sizeof(vis)); //初始化
	x.push_back(0);  //起点入队
	y.push_back(0);
	vis[0][0] = 0;
	while (!x.empty()) { //广搜板子
		int xx = x.front();
		int yy = y.front();
		x.pop_front();
		y.pop_front();
		for (int i = 0; i < 4; i++) {
			int dnx = xx + dx[i];
			int dny = yy + dy[i];
			int inx = xx + ix[i];
			int iny = yy + iy[i];
			if (dnx >= 0 && dnx <= l && dny >= 0 && dny <= c) { //最优化剪枝
				if (a[i] != mp[inx][iny]) { //看看地图的电线状态和往这个方向走的电线状态是否一致
					int t = vis[xx][yy] + 1; //不一致就要转向，步数+1
					if (t < vis[dnx][dny]) { //如果比原来的步数小，就入队
						x.push_back(dnx); //转向肯定不如不转向好，所以要后搜，从队尾入队
						y.push_back(dny);
						vis[dnx][dny] = t;
					}
				} else { //如果一致就不用转向
					int t = vis[xx][yy]; //步数不变
					if (t < vis[dnx][dny]) { //步数比原来的小才能入队
						x.push_front(dnx); //不用转向肯定更好，要先搜，从队首入队
						y.push_front(dny);
						vis[dnx][dny] = t;
					}
				}
			}
		}

	}
	cout << vis[l][c] << endl;
}
int main() {
	cin >> l >> c;
	for (int i = 0; i < l; i++) cin >> mp[i];
	if ((l + c) % 2 == 1) //如果终点横纵坐标和是奇数
		cout << "NO SOLUTION"; //无解
	else dfs();
}
```