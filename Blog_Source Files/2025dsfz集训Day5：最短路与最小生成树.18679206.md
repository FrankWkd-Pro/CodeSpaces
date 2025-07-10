# DAY5 I : 最小生成树
$$Designed\ By\ FrankWkd\ -\ Luogu@Lwj54joy,uid=845400$$
特别感谢 此次课的主讲 - Kwling
## 生成树及最小生成树
 - 生成树是从一张无向连通图中选取一些边构成一张新图,使得这张图是是一棵树
 - 最小生成树即是让上述的生成树的边权和最小同时，最小生成树也会有一些性质
     - 在最小生成树上，两个点路径上经过的边权最小值即是这个点在原图中所有路径中可能经过边的边权最小值
     - 对于原图中所有合法的最小生成树，他们的边权构成是相同的。
     - 最小生成树是瓶颈生成树的充分不必要条件，即最小生成树一定是瓶颈生成树，而瓶颈生成树不一定是最小生成柄瓶颈生成树为在原图的所有生成树中，最大的边权最小
 - 模版：
     - [x] [AccodersP2023 |【一本通图 最小生成树】最短网络(agrinet)](http://www.accoders.com/problem.php?cid=5020&pid=0)  
## Kruskal算法
### $Kruskal$ 算法的正确性
 - Kruskal 是一种含心算法，即从未选边中选取一条边权最小的边、满足选取该边后，原图不出环
 - 那么想要找到这条边，我们需要同时判断两个东西：
     - 当前的最小边权的边
     - 这条边所连接的两个点的连通性
 - 那又如何判断呢？
     - 对于第一个问题，我们考虑可以用并查集来维护两个点之间的连通性，
即如果两个点在并查集内部有共同祖先，那么即说明这两个点是联通的
     - 对于第二个问题，我们可以对原图的边进行排序，然后按顺序判断是否
满足条件 1 即可
### 证明
 - 对于正确性，我们考虑当前待加入的边 $e$
    -  如果它属于最终的正确的生成树，那么显然正确
    -  如果它不属于最终的正确的生成树，那么我们加入后一定会有一个环，考虑这个环上不是点 e 的任意一条边 $e’$
        - 如果 $e’$ 的边权大于 $e$，那么我们构建最小生成树的时候应该会先加入 $e$ 后加入 $e’$，那么含有 $e$ 的生成树就是比正确的生成树更优的，这显然与事实不符
        - 如果 $e’$ 的边权小于 $e$，那么我们在加入 $e$ 之前肯定已经加入 $e’$ 了。因为 $e’$ 具有任意性，所以在想要加入 $e$ 这条边的时候，这条边的两个端点已经联通，自然不会加入 $e$ 这条边
### 模版
 - [x] [AccodersP2023 |【一本通图 最小生成树】最短网络(agrinet)](http://www.accoders.com/problem.php?cid=5020&pid=0)  
 - [x] [洛谷P1546 | [USACO3.1] 最短网络 Agri-Net](https://www.luogu.com.cn/problem/P1546)  
```cpp
#include <bits/stdc++.h>
using namespace std;
int n;
int a[1010][1010];//邻接矩阵
struct link{
	int u,v,w;
	bool operator < (const link &ret) const{//重载运算符
		return w<ret.w;//从大到小
	}
}e[1101010];
int cnt,ans,tot;//分别代表：边数，最小生成树的权值和，已经加入树中的边数
int f[1010101];//并查集数组
int find(int x){//寻找并查集的根
	if(x != f[x]) return f[x] = find(f[x]);//路径压缩
	return x;
}
int main(){
	scanf("%d",&n);
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			scanf("%d",&a[i][j]);
			if(i < j) e[++cnt] = {i,j,a[i][j]};//输入+将边数据加入数组
		}
	}
	for(int i = 1;i <= n;i++) f[i] = i;//初始化并查集
	sort(e+1,e+cnt+1);//排序（按边长）
	for(int i = 1;i <= cnt;i++){
		int u = e[i].u,v = e[i].v,w = e[i].w;//可以去掉
		int fu = find(u),fv = find(v);//寻找祖先
		if(fu!= fv){//如果不联通（如果联通时合并会形成环）
			f[fu] = fv;//相当于并查集中的Merge函数
			tot++;//边数++
			ans += w;//树的权值总长加上w
		}
		if(tot == n-1) break;//如果已经形成了树，直接break，输出。
	}
	cout<<ans<<endl;
}
```
## Prim算法
$其实大部分能用Prim作的题都能用Kruskal\ AC$
### 简介
 - 如果说 $Kruskal$ 是找满足条件的边，那么 $Prim$ 就是找满足条件的点。
 - 即在目前没有加入连通块的点中，选取一个距离连通块最近的点加入连通块
 - 那么想要找到这个点，我们需要思考三个东西：
   - 现在有哪些没有加入连通块的点
   - 这些点距离连通块的距离是多少
   - 距离最近的点是什么
### 做法
 - 事实上，我们发现，我们其实只需要考虑和当前连通块有连边的那些点，因为其它点想要到达连通块一定需要经过那些有连边的点和那些边也就是说，我们只需要保存当前和连通块有连边的点就行了同时，我们也就是只需要在每次加入新的点之后，更新一下这个点连接的点和他们到连通块的距离即可。
 - 这样，我们只需要用一个堆来存储所有和连通块有边相连的点即可然后每次取出距离连通块最近的点，然后向堆中加入其相邻的点，或者更新相邻点到当前连通块的距离。
### 模版
 - [x] [AccodersP2024 | 【一本通图 最小生成树】 局域网](http://www.accoders.com/problem.php?cid=5020&pid=1)
 - [x] [洛谷P280 | 局域网](https://www.luogu.com.cn/problem/P2820)
```cpp
#include <bits/stdc++.h>
using namespace std;
#define P pair<int,int>
struct edge{
	int to,len;
};
int n,m,ans,tot,cnt;
vector<edge> e[1110101];
int dis[1101010];//当前点到联通块的距离
bool vis[1101010];

void prim(int rt){
	priority_queue <P,vector<P>,greater <P> > q;
	dis[rt] = 0;
	q.push(P(dis[rt],rt));
	while(!q.empty()){
		int u = q.top().second,w = q.top().first;
		q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		ans += w;
		for(auto v:e[u]){
			if(dis[v.to] > v.len){
				dis[v.to] = v.len;
				q.push(P(dis[v.to],v.to));
			}
		}
	}
}
int main(){
	memset(dis,0x3f3f3f3f,sizeof dis);
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		e[u].push_back({v,w});
		e[v].push_back({u,w});
		tot += w;
	}
	prim(1);
	cout<<tot-ans<<endl;
}
```
## 题目思路&解法
### $T1$
 - [x] [洛谷P3366 |【模板】最小生成树](https://www.luogu.com.cn/problem/P3366)
 - [x] [洛谷P1546 | [USACO3.1] 最短网络 Agri-Net](https://www.luogu.com.cn/problem/P1546)
 - [x] [AccodersP2023 |【一本通图 最小生成树】最短网络(agrinet)](http://www.accoders.com/problem.php?cid=5020&pid=0)  
**思路：** 纯板子，$Kruskal$ 算法
```cpp
#include <bits/stdc++.h>
using namespace std;
int n;
int a[1010][1010];
struct link{
	int u,v,w;
	bool operator < (const link &ret) const{
		return w<ret.w;//从大到小
	}
}e[1101010];
int cnt,ans,tot;
int f[1010101];
int find(int x){
	if(x != f[x]) return f[x] = find(f[x]);
	return x;
}



int main(){
	scanf("%d",&n);
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			scanf("%d",&a[i][j]);
			if(i < j) e[++cnt] = {i,j,a[i][j]};
		}
	}
	for(int i = 1;i <= n;i++) f[i] = i;
	sort(e+1,e+cnt+1);
	for(int i = 1;i <= cnt;i++){
		int u = e[i].u,v = e[i].v,w = e[i].w;
		int fu = find(u),fv = find(v);
		if(fu!= fv){
			f[fu] = fv;
			tot++;
			ans += w;
		}
		if(tot == n-1) break;
	}
	cout<<ans<<endl;
}
```
### $T2$
 - [x] [AccodersP2024 |【一本通图 最小生成树】 局域网](http://www.accoders.com/problem.php?cid=5020&pid=1)
 - [x] [洛谷P2820 | 局域网](https://www.luogu.com.cn/problem/P2820)  
**思路：** 纯板子，按理来说是道 $Prim$ 算法的题，$Kruskal$ 也能过
```cpp
#include <bits/stdc++.h>
using namespace std;
#define P pair<int,int>
struct edge{
	int to,len;
};
int n,m,ans,tot,cnt;
vector<edge> e[1110101];
int dis[1101010];//当前点到联通块的距离
bool vis[1101010];

void prim(int rt){
	priority_queue <P,vector<P>,greater <P> > q;
	dis[rt] = 0;
	q.push(P(dis[rt],rt));
	while(!q.empty()){
		int u = q.top().second,w = q.top().first;
		q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		ans += w;
		for(auto v:e[u]){
			if(dis[v.to] > v.len){
				dis[v.to] = v.len;
				q.push(P(dis[v.to],v.to));
			}
		}
		
	}
}

int main(){
	memset(dis,0x3f3f3f3f,sizeof dis);
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		e[u].push_back({v,w});
		e[v].push_back({u,w});
		tot += w;
	}
	prim(1);
	cout<<tot-ans<<endl;
	
}
```
### $T3$
 - [x] [Accoders2025 |【一本通图 最小生成树】 繁忙的都市](http://www.accoders.com/problem.php?cid=5020&pid=2)
 - [x] [洛谷P2330 | [SCOI2005] 繁忙的都市](https://www.luogu.com.cn/problem/P2330)  
**思路：** 这题把 $T1$ 改改就能过，板子。
```cpp
#include <bits/stdc++.h>
using namespace std;
//Kruskal
int f[101010];
struct node{
	int x,y,z;
}a[1010101];
int n,m,ans = -1,cnt,tot;
int find(int x){
	if(f[x] != x)  return f[x] = find(f[x]);
	return x;
}
bool cmp(node xx,node yy){
	return xx.z < yy.z;
}
int main(){
	cin>>n>>m;
	for(int i = 1;i <= m;i++){
		++cnt;//不能与下一句合并！！！会WA，有警告：[警告] operation on 'cnt' may be undefined [-Wsequence-point]
		cin>>a[cnt].x>>a[cnt].y>>a[cnt].z;
	}
	sort(a+1,a+cnt+1,cmp);
	for(int i = 1;i <= n;i++){
		f[i] = i;
	}
	for(int i = 1;i <= cnt;i++){
		if(find(a[i].x) != find(a[i].y)){
			ans = max(ans,a[i].z);
			tot++;
			f[find(a[i].x)] = f[find(a[i].y)];
		}
		if(tot == n-1) break;
	}
	cout<<tot<<" "<<ans<<endl;
}
```
### $T4$
- [x] [AccodersP2026 |【一本通图 最小生成树】联络员(liaison)](http://www.accoders.com/problem.php?cid=5020&pid=3)  
**思路：** 此题需要先将必须加入的边加入并查集（树）中，然后再遍历**所有**其他边，如果能加入且两点未联通，直接加入，答案加对应值。必须加入所有街区！
```cpp
#include <bits/stdc++.h>
using namespace std;
//Kruskal
int f[101010];
struct node{
	int x,y,z;
}a[1010101];
int n,m,ans,cnt,tot;
int find(int x){
	if(f[x] != x)  return f[x] = find(f[x]);
	return x;
}
bool cmp(node xx,node yy){
	return xx.z < yy.z;
}
int main(){
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		f[i] = i;
	}
	for(int i = 1;i <= m;i++){
		int p,x,y,z;
		cin>>p>>x>>y>>z;
		if(p == 1){
			f[find(x)] = f[find(y)];
			tot++;
			ans += z;
		}else{
			cnt++;
			a[cnt].x = x;
			a[cnt].y = y;
			a[cnt].z = z;
		}
	}
	sort(a+1,a+cnt+1,cmp);
	
	for(int i = 1;i <= cnt;i++){
//		if(tot == n-1) break;
		if(find(a[i].x) != find(a[i].y)){
			ans += a[i].z;
			tot++;
			f[find(a[i].x)] = find(a[i].y);
		}
//		if(tot == n-1) break;
	}
	cout<<ans<<endl;
}
```
### $T5$
 - [x] [AccodersP2027 |【一本通图 最小生成树】 连接格点](http://www.accoders.com/problem.php?cid=5020&pid=4)  
**思路：** 这题需要将二维的矩阵转化为由一维数据结构存储的图，然后跑 $Kruskal$ 。需要注意的点很多。并查集要在最开始的时候排序，因为输入的时候会使用并查集的合并。
```cpp
#include <bits/stdc++.h>
using namespace std;
int f[5000010];
struct node{
	int x,y,z;
}e[5010100];
int a[1100][1100];
int n,m,k=0,o,p,q,r;
int ans;
int fe(int i,int j){
	return m*(i-1)+j;
}
int find(int x){
	return f[x] == x ? x : f[x] = find(f[x]);
}
bool cmp(node i,node j){
	return i.z < j.z;
}
void kruskal(){
	sort(e+1,e+k+1,cmp);//一定要注意排序！
	for(int i = 1;i <= k;i++){
		if(find(e[i].x) != find(e[i].y)){
			f[find(e[i].x)] = find(e[i].y);
			ans += e[i].z;
		}
	}
}
int main(){
	
	cin>>n>>m;//n行m列
	for(int i = 1;i <= n*m;i++){
		f[i] = i;
	}
	while(cin>>o>>p>>q>>r){
		f[find(fe(o,p))] = f[find(fe(q,r))];
	}
	for(int i = 1;i < m;i++){
		for(int j = 1;j <= n;j++){//注意：fe函数的格式为：fe(行,列)！！注意i、j顺序！！！
			k++;
			e[k].x = fe(j,i);
			e[k].y = fe(j,i+1);
			e[k].z = 2;
		}
	}
	for(int i = 1;i < n;i++){
		for(int j = 1;j <= m;j++){
			k++;
			e[k].x = fe(i,j);
			e[k].y = fe(i+1,j);
			e[k].z = 1;
		}
	}
	kruskal();
	cout<<ans<<endl;
	return 0;
}
```
### $T6$
 - [x] [AccodersP2098 |【一本通提高篇最小生成树】新的开始](http://www.accoders.com/problem.php?cid=5020&pid=5)  
**思路：** 先把“在 $i$ 点建设发电站”操作转化成“建点 $n+1$，将 $i$ 点与 $n+1$ 点连接，边权为建设发电站的费用”，然后求点 $1$ 到点 $n+1$ 的最小生成树。使用 $Kruskal$ 算法。
```cpp
#include <bits/stdc++.h>
using namespace std;
int n;
struct node{
	int u,v,w;
}a[1010101];
bool cmp(node xx,node yy){
	return xx.w < yy.w;
}
int f[1010101];
int cnt,ans,tot;
int find(int x){
	if(f[x] != x) return f[x] = find(f[x]);
	return x;
}
int main(){
	cin>>n;
	for(int i = 1;i <= n+1;i++) f[i] = i;
	for(int i = 1;i <= n;i++){
		int v;
		scanf("%d",&v);
		a[++cnt] = {i,n+1,v};//将发电站的建造费用转化成边权
		
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			int w;
			cin>>w;
			if(i < j) {
				a[++cnt] = {i,j,w};
			}
		}
	}
	sort(a+1,a+cnt+1,cmp);
	int tot = 0;
	for(int i = 1;i <= cnt;i++){
		int fu = find(a[i].u),fv = find(a[i].v);
		if(fu != fv){
			f[fu] = fv;
			ans += a[i].w;
			tot++;
		}
		if(tot >= n) break;
	}
	cout<<ans<<endl;
}
```
### $T7$
 - [x] [AccodersP2101 |【一本通提高篇最小生成树】Tree](http://www.accoders.com/problem.php?cid=5020&pid=6)  
**思路：** 因为边权越大，这个边就越不容易被选上；边权越小，越容易被选上。那么我们就先将白色的边的边权全部加上一个 $w$ ，再二分这个 $w$ 的数值，因为根据前面的结论能够得出这个 $w$ 与被选上的白色边的数量是具有单调性的，就可以二分。
```cpp
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>

#define int long long  // 将 int 类型重定义为 long long 类型
#define inf 0x3f3f3f3f  // 定义一个较大的常量 inf，可用于表示无穷大
using namespace std;
const int N = 100000;
int n, m, need;
int tot, ans = inf;  // tot 用于计数，ans 存储最终结果，初始化为 inf
struct node {
    int u, v, w, col;
    bool operator<(const node &ret) const {
        if (w == ret.w)  // 当边的权重相等时
            return col < ret.col;  // 根据颜色进行比较，颜色小的在前
        return w < ret.w;  // 按照边的权重升序排序
    }
} e[N + 10];
int fa[N + 10];
// 初始化并查集
void init() {
    tot = 0;  // 初始化 tot 为 0
    for (int i = 1; i <= n; i++) fa[i] = i;  // 每个节点的父节点初始化为自身
}
// 查找节点 x 的父节点，并进行路径压缩
int getfa(int x) {
    if (fa[x] == x) return x;
    return fa[x] = getfa(fa[x]);  // 路径压缩，将节点的父节点更新为根节点
}
// 计算最小生成树
int mst() {
    int ret = 0, num = 0;  // ret 存储最小生成树的边权和，num 存储已添加的边的数量
    init();  // 调用初始化函数
    sort(e + 1, e + m + 1);  // 对边进行排序
    for (int i = 1; i <= m; i++) {
        int u = e[i].u, v = e[i].v, w = e[i].w, col = e[i].col;
        int fu = getfa(u), fv = getfa(v);
        if (fu!= fv) {  // 如果两个节点不在同一个集合中
            fa[fu] = fv;  // 合并集合
            if (!col) tot++;  // 如果边的颜色为 0，tot 加 1
            ret += w;  // 边权累加到 ret
            num++;  // 边的数量加 1
        }
        if (num == n - 1) break;  // 当添加了 n-1 条边时，生成树构建完成，退出循环
    }
    return ret;
}
signed main() {
    scanf("%lld%lld%lld", &n, &m, &need);
    for (int i = 1; i <= m; i++) scanf("%lld%lld%lld%lld", &e[i].u, &e[i].v, &e[i].w, &e[i].col), e[i].u++, e[i].v++;  // 输入边的信息，并将节点编号加 1
    int l = -300, r = 300;
    while (l < r) {
        int mid = (l + r) >> 1;  // 计算中间值
        for (int i = 1; i <= m; i++) if (!e[i].col) e[i].w += mid;  // 对颜色为 0 的边的权重进行调整
        int sum = mst();  // 计算最小生成树
        if (tot >= need) ans = sum - need * mid;  // 当 tot 大于等于 need 时更新答案
        if (tot < need) r = mid;  // 根据 tot 的大小调整左右边界
        else l = mid + 1;
        for (int i = 1; i <= m; i++) if (!e[i].col) e[i].w -= mid;  // 恢复颜色为 0 的边的权重
    }
    printf("%lld\n", ans);  // 输出最终结果
    return 0;
}
```
### $T8$
 - [x] [AccodersP2103 |【一本通提高篇最小生成树】次小生成树](http://www.accoders.com/problem.php?cid=5020&pid=7)
 - [x] [洛谷P4180 | [BJWC2010] 严格次小生成树](https://www.luogu.com.cn/problem/P4180)  
**思路：** 先跑一遍 $Kruskal$ 算法求出最小生成树，然后再用 $DFS$ + 倍增求一条边，将这条边替换掉最小生成树中的一条边，使得其不会损坏树的结构，且带来冗余的边权最小。
```cpp
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<vector>
#define inf 100000000000000
#define int long long
using namespace std;
const int N = 4e5;
// 节点数和边数
int n, m;
// 存储最终答案，初始化为无穷大
int ans = inf;
// 边的结构体，存储边的两个端点 u 和 v，边的权重 w，以及该边是否在最小生成树中（flag）
struct link{
    int u, v, w;
    bool flag;
    // 重载小于运算符，用于边的排序，按照边的权重升序排序
    bool operator<(const link& ret) const{
        return w < ret.w;
    }
} edge[N + 10];
// 存储图的邻接表节点信息，存储邻接节点 to 和边的长度 len
struct node{
    int to, len;
};
// 邻接表
vector<node>e[N + 10];
// 存储每个节点的父节点，用于倍增法
int fa[N + 10][20];
// 存储每个节点到父节点路径上的最大边权，用于倍增法
int maxs[N + 10][20];
// 存储每个节点到父节点路径上的次大边权，用于倍增法
int mins[N + 10][20];
// 存储每个节点的深度
int deep[N + 10];
// 存储最小生成树的边权和
int sum;
// 并查集数组，用于判断节点的父节点
int f[N + 10];
// 并查集的查找操作，用于找到节点 x 的根节点
int getfa(int x){
    if (f[x] == x)
        return x;
    // 路径压缩，将节点的父节点更新为根节点
    return f[x] = getfa(f[x]);
}
// 计算最小生成树
void mst(){
    int cnt = 0;
    // 初始化并查集，每个节点的父节点为自身
    for (int i = 1; i <= n; i++)
        f[i] = i;
    // 对边按照权重进行排序
    sort(edge + 1, edge + m + 1);
    for (int i = 1; i <= m; i++){
        int u = edge[i].u, v = edge[i].v, w = edge[i].w;
        // 找到节点 u 和 v 的根节点
        int fu = getfa(u), fv = getfa(v);
        if (fu!= fv){
            // 合并两个集合，更新父节点
            f[fu] = fv;
            cnt++;
            // 更新最小生成树的边权和
            sum += w;
            // 标记该边在最小生成树中
            edge[i].flag = 1;
            // 将边加入邻接表中
            e[u].push_back({ v, w });
            e[v].push_back({ u, w });
        }
        // 当最小生成树的边数达到 n-1 时，结束
        if (cnt >= n - 1)
            break;
    }
}
// 深度优先搜索，用于预处理倍增数组
void dfs(int u, int father){
    // 计算当前节点的深度
    deep[u] = deep[father] + 1;
    for (int i = 1; i <= 19; i++){
        // 倍增更新父节点
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
        // 倍增更新最大边权
        maxs[u][i] = max(maxs[u][i - 1], maxs[fa[u][i - 1]][i - 1]);
        if (maxs[u][i - 1]!= maxs[fa[u][i - 1]][i - 1]){
            // 如果两条路径上的最大边权不同，更新次大边权
            mins[u][i] = min(maxs[u][i - 1], maxs[fa[u][i - 1]][i - 1]);
            mins[u][i] = max(mins[u][i], mins[u][i - 1]);
            mins[u][i] = max(mins[u][i], mins[fa[u][i - 1]][i - 1]);
        }else
            // 如果两条路径上的最大边权相同，更新次大边权
            mins[u][i] = max(mins[u][i - 1], mins[fa[u][i - 1]][i - 1]);
    }
    // 遍历邻接节点
    for (auto v : e[u]){
        if (father == v.to) continue;
        // 更新邻接节点的父节点和初始边权信息
        fa[v.to][0] = u;
        maxs[v.to][0] = v.len;
        mins[v.to][0] = -inf;
        // 继续递归搜索
        dfs(v.to, u);
    }
}

// 计算最近公共祖先
int lca(int x, int y){
    // 保证 x 的深度大于等于 y 的深度
    if (deep[x] < deep[y]) swap(x, y);
    for (int i = 19; ~i; i--){
        if (deep[fa[x][i]] >= deep[y]) x = fa[x][i];
        if (x == y) return x;
    }
    for (int i = 19; ~i; i--)
        if (fa[x][i]!= fa[y][i]) x = fa[x][i], y = fa[y][i];
    return fa[x][0];
}

// 获取从节点 x 到节点 top 路径上不等于 w 的最大边权
int get_val(int x, int top, int w){
    int ret = -inf;
    for (int i = 19; ~i; i--)
        if (deep[fa[x][i]] >= deep[top]){
            if (w!= maxs[x][i]) ret = max(ret, maxs[x][i]);
            else ret = max(ret, mins[x][i]);
            x = fa[x][i];
        }
    return ret;
}

signed main(){
    // 输入节点数和边数
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= m; i++)
        // 输入边的信息，并将边标记为不在最小生成树中
        scanf("%lld%lld%lld", &edge[i].u, &edge[i].v, &edge[i].w), edge[i].flag = 0;
    // 计算最小生成树
    mst();
    // 从根节点开始深度优先搜索，预处理倍增数组
    dfs(1, 0);
    for (int i = 1; i <= m; i++){
        int u = edge[i].u, v = edge[i].v, w = edge[i].w;
        bool flag = edge[i].flag;
        if (flag) continue;
        // 计算 u 和 v 的最近公共祖先
        int l = lca(u, v);
        // 获取从 u 到 lca 路径上不等于 w 的最大边权
        int maxs_u = get_val(u, l, w);
        // 获取从 v 到 lca 路径上不等于 w 的最大边权
        int maxs_v = get_val(v, l, w);
        // 更新次小生成树的答案
        ans = min(ans, sum - max(maxs_u, maxs_v) + w);
    }
    // 输出次小生成树的边权和
    printf("%lld\n", ans);
    return 0;
}
```
### $T9$
- [x] [AccodersP2102 |【一本通提高篇最小生成树】最小生成树计数](http://www.accoders.com/problem.php?cid=5020&pid=8)
- [x] [洛谷P4208 | [JSOI2008] 最小生成树计数](https://www.luogu.com.cn/problem/P4208)
**思路1：**
 - 这道题需要用到最小生成树的两个性质
   - 1 一个图的所有最小生成树中的每种边权的边的数量都是一样的
   - 2 无论某个边权的边的选择方式是如何的，图的联通性不变
 - 也就是说，只要我们每种边权选出固定数量条，且满足不出环的条件，就能构成最小生成树  
   由乘法原理可知，我们只需要知道每种边权可行的选择方案，然后将这些方案数乘起来就行

 - 我们按照 Kruskal 的顺序从小往大加边，由于不同边权的边的数量很少，我们可以暴力 dfs 出我们选了那些边  
   由于性质 2 的存在，使得对于小的边权加完之后，大的边的加边方式不会被影响
  
 - 因为要统计某个边权的边的加法，dfs 过程中需要反悔操作，也就是把上一步合并的连通块断开  
  所以并查集不能使用路径压缩，也就是直接连接这两个点

**思路2：**  
 - 由于最小生成树种每种边权的边的数量是一样的，我们考虑对于某一个边权，先把别的边权的边加上，然后再回头加这个边权的边  
   由于性质 2，当前图的连通性是固定的，连通块内部的边没有意义，我们就可以把他们缩成一个点  
   而我们要做的，其实就是通过这个边权的边，把这些连通块变成的点连成一棵生成树

 - 现在，我们只需要统计每种边权所能构成的生成树数量

```cpp
#include<bits/stdc++.h>
using namespace std;
struct node {
	int x, y, z;
} a[1001], b[1001];
int n, m, i, t, f[1001], d[1001], c[1001], cnt, ans, xx, yy;
int find(int x) { //k算法
	if (f[x] == x) return x;
	f[x] = find(f[x]);
	return f[x];
}
void dfs(int now, int k, int x) { //now表当前位置，k表示加入边数，x表权值种类在d数组中位置
	if (now > b[x].y) { //如果搜过右端点
		if (k == d[x]) cnt++; //符合情况则+1
		return;
	}
	int p[101];
	for (int i = 1; i <= n; i++) p[i] = f[i]; //存储
	xx = find(a[now].x);
	yy = find(a[now].y);
	if (xx != yy) { //如果可以加入最小生成树
		f[xx] = yy;
		dfs(now + 1, k + 1, x);
	}
	for (int i = 1; i <= n; i++) f[i] = p[i]; //还原
	dfs(now + 1, k, x);

}
int cmp(node a, node b) {
	return a.z < b.z;
}
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) //输入
		scanf("%d %d %d", &a[i].x, &a[i].y, &a[i].z);
	sort(a + 1, a + 1 + m, cmp); //快排用于k算法及搜索同一权值
	for (int i = 1; i <= n; i++) //k算法初始化
		f[i] = i;
	a[0].z = -INT_MAX;
	t = 0;
	for (int i = 1; i <= m; i++)
		if (a[i].z == a[i - 1].z) { //搜索同一权值的左右位置，方便搜索
			b[t].y++;
			c[i] = t; //y表是右端点
		} else {
			t++;
			b[t].x = i;
			b[t].y = i;
			c[i] = t; //x表示左端点，t表示权值种数
		}
	cnt = 0;
	for (int i = 1; i <= m; i++) {
		xx = find(a[i].x);
		yy = find(a[i].y); //寻找最小生成树
		if (xx != yy) {
			f[xx] = yy;
			d[c[i]]++; //d存储该权值需要的边数
			cnt++;
		}
		if (cnt == n - 1) break; //最小生成树找到
	}
	if (cnt != n - 1) {
		printf("0");    //没找到
		exit(0);
	}
	for (int i = 1; i <= n; i++) f[i] = i; //初始
	ans = 1;
	for (int i = 1; i <= t; i++)
		if (d[i] > 0) {
			cnt = 0;
			dfs(b[i].x, 0, i); //搜索
			ans = (ans * cnt) % 31011; //乘法原理
			for (int j = b[i].x; j <= b[i].y; j++)  {// 更新
				xx = find(a[j].x);
				yy = find(a[j].y);
				if (xx != yy) {
					f[xx] = yy;
				}
			}

		}
	printf("%d\n", ans);
}
```
# DAY5：最短路
## Floyd算法
 - Floyd 是一种经典的用来求全源最短路的算法，具有特别好写的优点（
 - 当然，除了求最短路以外，$Floyd$ 还会有其它的应用
### 做法…
这个算法的过程其实就是不断在寻找中转点的过程，也就是新的中转点 $→$ 新的路径 $→$ 可能的新的最短路

 - 我们令 $e[k][i][j]$ 表示当前已经使用了编号为 $1 ∼ k$ 的点为中转点，点 $i$与点 $j$ 之间的最短路

 - 现在我们考虑如何更新下一个中转点 $k + 1$ 的情况
   对于新情况下的点 $i$ 和点 $j$，它们有两种选择：
    - 1 按照原来的方式走，即  
      $e[k + 1][i][j]$ = $e[k][i][j]$
    - 2 经过新的中转点，走一条全新的路径，即  
      $e[k + 1][i][j]$ = $e[k][i][k + 1]$ + $e[k][k + 1][j]$
 - 我们肯定是从这两种方式中选取最优解
于是我们就得到了求任意两点 $i$，$j$ 之间的最短路，即
   - $e[k + 1][i][j] = max(e[k][i][j], e[k][i][k + 1], e[k][k + 1][j])$

 - 时间复杂度为 $O(n^3)$
 - 空间复杂度为 $O(n^3)$
### 空间优化！
 - 我们观察整个算法流程会发现，我们其实没有必要保留 $1 ∼ k − 1$ 层的信息，因为他们其实都被整合到第 $k$ 层内了

 - 同时我们会发现，在更新第 $k + 1$ 层时，其所需的第 $k$ 层的信息并不会被覆盖
     - 1 对于 $e[k][i][j]$，本来当前就要更新它，不存在覆盖的问题
     - 2 对于 $e[k][i][k + 1]$ 和 $e[k][k + 1][j]$，如果被更新到了，也就只有两种可能：要么是通过 $1 ∼ k$ 的点中转，要么时 $i$ 或 $j$ 与 $k + 1$ 有直接
连边，不可能存在通过 $k + 1$ 中转的问题，也就不会被覆盖
 - 于是我们就可以把数组的最外层压掉，即  
    $e[i][j] = max(e[i][j], e[i][k + 1], e[k + 1][j])$
 - 注意，以上的操作**没有变动原有的三层循环**，也**没有变动他们的顺序**，单纯是空间上的优化
 - 时间复杂度 $O(n^3)$
 - 空间复杂度 $O(n^2)$

### 扩展
 - 除此之外，我们还可以利用这个思路解决最小环问题

 - 我们考虑一个环最少为三个点
   那么我们就可以把任意一个环拆成三部分，即 $i − j, i − k, j − k$ 寻找最小环，即让这三个部分的和最小

 - 对于 $Floyd$ 枚举的当前层，在没有以 $k$ 为中转点更新最短路之前，
$e[i][j]$, $e[i][k]$, $e[k][j]$ 三条路径恰好构成一个环
且由于这三个路径都是以 $1 ∼ k − 1$ 的点为中转点的情况下的最短路，
那么这个环也就是当前包含这三点的最小环

 - 对于每一个中转点 $k$，显然都可以有这个操作
随着 $Floyd$ 的进行，我们可以同时求出最短路和以 $k$ 为断点的包含 $i$, $j$
的最小环

 - 所有求出的环的最小值也就是全局的最小环
## Dijkstra算法
 - $Dijkstra$ 和 $SPFA$ 的核心都在于松弛操作，即
   $dis[v] = min(dis[v], dis[u] + w)$

 - 这个操作是显然的，新更新的节点 $u$ 也只有可能会直接影响其相连的点 $v$ 的最短路，我们尝试使用 $S → u → v$ 这一条新的路径更新点 $v$ 的最短路  
 - 感性理解下，相当于一层一层扩展，每一次松弛操作会将当前最短路的范围向外扩展一层
 - 因为后面的节点一定会被前面的节点更新，所以我们在松弛过程中也没有必要更新后面的节点

 - 设源点为 $s$，$dis_i$ 为当前源点到点 $i$ 的最短路
   - 我们考虑当前已经更新了集合 $E$ 中的点的最短路，现在已经更新了点 $e$的最短路，考虑如何更新其它点的最短路
   - 我们取出当前还未进行松弛过的点中离源点最近的点 $u$，然后对这个点进行松弛操作，每一个点只会松弛一遍
 - 时间复杂度 $O(n^2)$
### 正确性
 - 这种做法的正确性在**没有负边权的图**上是可以保证的
 - 我们考虑当前要进行松弛操作的点 $u$，和另一个还未进行松弛操作的点 $u′$，他们都和点 $v$ 之间有边
 - 那么在松弛 $v$ 之前，我们考虑源点到点 $v$ 之间最短路的情况，困扰我们的其实只有 $S → u → v，S → u′$，和 $S → u′ → v$ 这三条路经的关系
     - 1 如果 $S → u → v$ 这个路径最短，且小于 $S → u′$，由于这条到 $u$ 的路径已经是最短路，所以这条到 $v$ 的路径就是最短路。同时，更新过的 $S → v$ 会优先于 $S → u′$ 被松弛，$v$ 点的最短路因此固定
     - 2 如果 $S → u → v$ 这条路径长于 $S → u′$，那么就会在松弛点 $v$ 之前松弛点 $u′$，保留了从点 $u′$ 更新最优解的可能性

 - 这样我们就说明了 $Dijkstra$ 算法的正确性
### 缺点
（接[该算法的正确性]）
 - 在存在负边权的情况下，可能会在第一个条件出错，即 $S → u → v$ 要小于 $S → u′$，点 $v$ 的松弛会在点 $u′$ 之前
 - 但存在一种可能，$u′ → v$ 负边权的存在, 使得$S → u′ → v$ 的距离小于$S → u → v，$
 - 但由于点 $v$ 已经松弛，也就无法更新到更优的解
### 优化
 - 我们考虑如何优化这个算法
 - 其实，整个算法的瓶颈在于如何维护这个当前未松弛的，到源点距离最短的点
     - 维护这个东西，需要我们有一个容器，满足能够插入新的未松弛的点，
     - 快速查找当前最小的未松弛的点，将这个点从未松弛点的容器中删掉

 - 我们考虑用堆来维护这个东西

 - 做法：
   - 每次操作从堆中取出堆顶元素，判断该点是否已经松弛
   - 若没有进行松弛，则用它进行松弛操作，并将新的点加入堆
   - 最后将该点从堆中弹出
 - 时间复杂度为 $O(mlogm)$
## SPFA
[其实就是裸的 $BFS$ ]  
$SPFA$ 其实是针对 $Bellman–Ford$ 进行队列优化的算法，可以用来处理负
边权问题

 - 相较于 $Dijkstra$，$Bellman-Ford$ 采取的松弛策略是对整张图所有点进行
松弛，当在一次的操作中没有松弛成功的点时就停止  
  由于最短路的边数一定小于 $n − 1$，所以我们最多会做 $n − 1$ 轮松弛

 - 若一张图存在负环，即边权和为负数的环，那么这个环上的点的最短路每转一圈都会变优
 - 也就是说，整体的循环次数会多于 $n − 1  $  
  **我们利用这个性质来判断负环**

 - 而由于我们是对整张图进行松弛，所以也不会存在负边权影响更新的问
题，也就可以正常处理存在负边权的图
### 优化
 - 我们会发现，其实我们没有必要松弛所有的点  
   会被影响的点，只有一次松弛操作相连的点

 - 我们使用队列来存储每一次松弛过的点，这样可以优化整体的松弛次数同时我们保留了所有点的松弛机会，也就不存在 $Dijkstra$ 中 $u′$ 的情况(详情见 $Dijkstra$ 算法介绍)，我们仍然可以处理负边权图
### 缺点
 - 虽然在大部分情况下，$SPFA$ 跑的很快，  
   但是可以构造出数据（如网格图 + 菊花），可以造成**反复松弛的情况，**  
   从而使整体的复杂度降低到 $O(nm)$  
 - 所以应当慎用该算法
## 题目思路&解法
### $T1$
- [x] [AccodersP2004 |【一本通图 最短路径算法】 信使](http://www.accoders.com/problem.php?cid=5021&pid=0)  
**思路：**
 - 我们考虑其实每个点在第一次收到信息之后就会往下传播信息，后续再收到的信息也就没有意义  
 - 所以其实每一个点收到信息所需的时间就是源点到这个点的最短路
那么所有点都收到信息的时间就是源点到所有点的最短路的最大值
 - 注意判断无解情况，也就是没有最短路
```cpp
#include <bits/stdc++.h>
using namespace std;
const int N = 100000;
int n, m;
typedef pair< int, int > P;
struct node {
	int to, len;
};
int dis[1010101];
vector<node> e[N + 10];
bool vis[1010101];
void dijkstra(int s) {
	priority_queue < P, vector<P>, greater<P> > q;
	dis[s] = 0;
	q.push({dis[s],s});
	while(!q.empty()){
		int u = q.top().second;
		q.pop();
		if(vis[u]){
			continue;
		}
		vis[u] = 1;
		for(auto v:e[u]){
			if(dis[v.to] > dis[u]+v.len){
				dis[v.to] = dis[u]+v.len;
				q.push({dis[v.to],v.to});
			}
		}
	}
}

int main() {
	cin >> n >> m;
	memset(dis, 0x3f3f3f3f, sizeof dis);
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		e[u].push_back({v, w});
		e[v].push_back({u, w});
	}
	dijkstra(1);
	int ans = -1;
	for(int i = 1;i <= n;i++){
		ans = max(ans,dis[i]);
	}
	if(ans >= 0x3f3f00000){
		cout<<-2<<endl;
	}else{
		cout<<ans<<endl;
	}
}
```
### $T2$
- [ x] [AccodersP2003 |【一本通图 最短路径算法】香甜的黄油](http://www.accoders.com/problem.php?cid=5021&pid=1)
- [x] [洛谷P1828 | [USACO3.2] 香甜的黄油 Sweet Butter](https://www.luogu.com.cn/problem/P1828)

**思路：** 堆优化加前向星存边的 $dijkstra$.
思路比较显然，对于每一个点都跑一遍最短路，累计距离和，求最小值。
实现细节：对于 $dijkstra$ 我们可以传一个参数作为起点。堆可以用 $STL$ 自带的优先队列。代码中会有重载运算符的 $struct node$ 结构体。
  每次 $dijkstra$ 的时候，初始化一下，传入起点，更新完 $dis$ 数组后累计答案即可。不需要用邻接矩阵。
  注意前向星开两倍空间，数组别少开。
  实现过程与普通 $dijkstra$ 类似，但是用堆维护 $max/min$ 显然要更优。普通的 $dijkstra$ 可能会$ TLE$，堆优化还是有必要的。

```cpp
#include<bits/stdc++.h>
#define inf 2147483647
using namespace std;
int vis[500000],n,m,p;
int dis[500000],tot,ans=inf;
int head[500000],sum;
int id[500000];
struct edge{
	int next,to,dis;
}e[1000000];
struct node{
	int dis,pos;
	bool operator <(const node&x)const{//重载
		return x.dis<dis;
	}
};
priority_queue<node>q;
inline void add(int x,int y,int w){//加边 
	e[++tot].to=y;
	e[tot].next=head[x];
	head[x]=tot;
	e[tot].dis=w;
}
void dijkstra(int s){//堆优化dijkstra 
	for(int i=1;i<=p;++i)dis[i]=inf;
	memset(vis,0,sizeof(vis));
	dis[s]=0,q.push((node){0,s});
	while(!q.empty()){
		node tmp=q.top();
		q.pop();
		int x=tmp.pos;
		if(vis[x])continue;
		vis[x]=1;
		for(int i=head[x];i;i=e[i].next){
			int y=e[i].to;
			if(dis[y]>dis[x]+e[i].dis){
				dis[y]=dis[x]+e[i].dis;
				if(!vis[y])q.push((node){dis[y],y});
			}
		}
	}
}
int main(){
	scanf("%d%d%d",&n,&p,&m);
	for(int i=1;i<=n;++i)scanf("%d",&id[i]);
	for(int i=1;i<=m;++i){
		int a,aa,aaa; 
		scanf("%d%d%d",&a,&aa,&aaa);
		add(a,aa,aaa);
		add(aa,a,aaa); 
	}
	for(int i=1;i<=p;++i){
		dijkstra(i);
		sum=0;
		for(int j=1;j<=n;++j)sum+=dis[id[j]];
		ans=min(ans,sum);
	}printf("%d\n",ans);
	return 0;
}
```
### $T3$
- [ x] [AccodersP2002 |【一本通图 最短路径算法】最小花费	](http://www.accoders.com/problem.php?cid=5021&pid=2)
- [x] [洛谷P1576 ｜ 最小花费](https://www.luogu.com.cn/problem/P1576)
**思路：** 跑一遍 $Dijkstra+$堆优化，求出答案即可，类似 $Dij$ 板子
```cpp
#include <bits/stdc++.h>
using namespace std;
int n, m, A, B;
double dis[2010];
bool mark[2010];

struct Node {
	int Num;
	double dis;
	bool operator<(const Node &a) const {
		return a.dis > dis;
	}
};
struct node {
	int Num;
	double dis;
};
vector<node> G[2010];
inline void Dij() {//Dijkstra堆优化板子
	priority_queue<Node> q;
	Node temp;
	temp.Num = A;
	temp.dis = 1;
	q.push(temp);
	while (!q.empty()) { 
		int u = q.top().Num; 
		q.pop();
		if (mark[u] == 1) continue;
		mark[u] = 1;
		for (int i = 0; i < G[u].size(); i++) { 
			int v = G[u][i].Num;
			double l = G[u][i].dis;
			if (mark[v] == 0 && dis[v] < dis[u]*l) { 
				dis[v] = dis[u] * l;
				temp.Num = v;
				temp.dis = dis[v];
				q.push(temp);
			}
		}
	}
}
int main() {
	node temp;
	scanf("%d%d", &n, &m); 
	memset(dis, -0x3f, sizeof(dis)); //因为要求最长路，所以初始化为-inf
	for (int i = 1; i <= m; i++) {
		int x, y;
		double z;
		scanf("%d%d%lf", &x, &y, &z); 
		temp.Num = y;
		temp.dis = 1 - z / 100;
		G[x].push_back(temp);
		temp.Num = x;
		G[y].push_back(temp);
	}
	scanf("%d%d", &A, &B); 
	dis[A] = 1; //起始点到自己的距离要初始化为1，不能是0，否则等下与之相乘的数就会是0了
	Dij();//跑
	printf("%.8lf", 100 / dis[B]); 
	return 0;
}
```
### $T4$
- [ ] [AccodersP2005 | 最优乘车](http://www.accoders.com/problem.php?cid=5021&pid=3)
**思路：** 先建图 然后跑朴素 $Dijkstra$
```cpp
#include <bits/stdc++.h>
#define MAXN 510
#define MAX 0x3f3f3f3f
using namespace std;
int ori = 1, node;	//ori 起点   node 节点数
int a[5005];	//存输入
int dis[MAXN], g[MAXN][MAXN];
bool vis[MAXN];
void init() {		//初始化
	memset(vis, 0, sizeof(vis));
	memset(dis, 0, sizeof(dis));
	vis[ori] = 1;
	for (int i = 1; i <= node; ++i)		dis[i] = (i == ori ? 0 : g[ori][i]);
}
void Dijkstra() {	//朴素Dijkstra
	int k;
	init();
	for (int i = 1; i <= node - 2; ++i) {
		int m = MAX;
		for (int j = 1; j <= node; ++j) {
			if (dis[j] < m && vis[j] == 0) {
				m = dis[j];
				k = j;
			}
		}
		if (m == MAX)		break;
		vis[k] = 1;
		for (int j = 1; j <= node; ++j)
			if (dis[k] + g[k][j] < dis[j])
				dis[j] = dis[k] + g[k][j];
	}
	return ;
}
int main() {
	int edge;
	scanf("%d%d", &edge, &node);
	for (int i = 1; i <= node; ++i)
		for (int j = 1; j <= node; ++j)
			g[i][j] = MAX;
	for (int i = 1; i <= edge; ++i) {
		memset(a, 0, sizeof(a));
		int n = 0;				//计数器
		char c = 1;
		while (c != -1 && c != '\r') {	//'\n'
			scanf("%d", &a[ ++n ]);
			c = -1;
			scanf("%c", &c);
		}
		for (int j = 1; j < n; ++j)
			for (int k = j + 1; k <= n; ++k)
				g[ a[j] ][ a[k] ] = 1;
	}
	Dijkstra();
	if (dis[node] >= MAX) printf("NO");
	else printf("%d", dis[node] - 1);	//换乘数为最短距离-1
	return 0;
}
```
### $T5$
- [ ] []()
**思路：**
```cpp
```
### $T6$
- [x] [AccodersP2117 |【一本通提高篇SPFA算法的优化】Wormholes 虫洞](http://www.accoders.com/problem.php?cid=5021&pid=5)  
**思路：**
 - 这道题其实就是裸的判断负环问题
 - 对于 SPFA 来说，每一条边最多会参与松弛操作 n − 1 次
 - 也就是说，如果某条边访问超过 n − 1 次，那么就出现了负环
```cpp
#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
//SPFa

int dis[1010101];

struct node{
	int to,len;
};
int T;
int n,m,k;
bool vis[1010110],st[1001230];
int num[1010101];
vector<node> e[1010101];
void init(){
	memset(dis,inf,sizeof dis);
	memset(vis,0,sizeof vis);
	memset(st,0,sizeof st);
	memset(num,0,sizeof num);
	for(int i = 1;i<=n;i++){
		e[i].clear();
	}
}
bool spfa(int s){
	queue <int> q;
	dis[s] = 0;
	q.push(s);    
	vis[s] = 1;
	num[s]=1;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		vis[u] = 0;
		st[u]=1;
		for(auto v:e[u]){
			if(dis[v.to] > dis[u]+v.len){
				dis[v.to] = dis[u]+v.len;
				if(!vis[v.to]){
					num[v.to]++;
					if(num[v.to] > n - 1) return 1;
					q.push(v.to);
					vis[v.to] = 1;
				}
			}
		}
	}
	return 0;
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&m,&k);
		init();
		for(int i = 1;i <= m;i++){
			int u,v,w;
			cin>>u>>v>>w;
			e[u].push_back({v,w});
			e[v].push_back({u,w});
		}
		for(int i = 1;i <= k;i++){
			int u,v,w;
			cin>>u>>v>>w;
			e[u].push_back({v,-w});
		}
		if(spfa(1)){
			puts("YES");
			goto Fuck_Everybody;
		}
		puts("NO");
		Fuck_Everybody:;
	}
}
```
### $T7$
- [ ] []()
**思路：**
```cpp
```
### $T8$
- [ ] []()
**思路：**
```cpp
```

## [必读]最短路结语
${\large\color{Brown} 很多图论题其实并没有“路径”之类的提示}$
${\large\color{Brown} 更多情况需要从问题中分析出不同元素之间的关系}$
${\large\color{Brown} 把元素抽象成点，把关系抽象成边，}$
${\large\color{Brown} 最后，把一个问题抽象成在图上操作的图论问题}$


# $\huge Thanks.$
---
---
### 感谢阅读，若有问题或错误，欢迎评论（或私信我）。
### 2025 Designed By @洛谷[Lwj54joy，uid=845400](https://www.luogu.com.cn/user/845400)