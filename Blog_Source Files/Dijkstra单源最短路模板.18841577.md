来更新一下雷达图的凹角吧，$Dijkstra$ 可以处理单源最短路，即跑一次可以求出指定点到每个点的最短距离。无法处理负边权。
```cpp
#include <bits/stdc++.h>
using namespace std;

int pre[100010], k; //存图
bool vis[100010];//是否访问过
int n, m, s; //输入

struct edge {
	int to, nxt, len; //链式前项星
} e[1010100];

struct node {
	int pos, dis; //编号，距离
	bool operator < (const node &cmp) const {
		return dis > cmp.dis;//重载小根堆
	}
} dis[1010100];
priority_queue <node> q;

void add(int u, int v, int l) {
	e[++k] = {v, pre[u], l};
	pre[u] = k;
}

void dijkstra() {
	dis[s].dis = 0;//别忘了
	q.push({s, 0}); //起点入队
	while (!q.empty()) {
		node tmp = q.top();//优先选择距离最小的点
		q.pop();//别忘了这个要不然就逝了，要一开始就pop，不然有可能pop掉刚刚push的数
		if (vis[tmp.pos]) continue; //优先剪枝掉访问过的点
		vis[tmp.pos] = 1;
		//开始松弛该节点
		for (int i = pre[tmp.pos]; i; i = e[i].nxt) {
			//遍历该节点的所有相邻节点
			int to = e[i].to;
			if (dis[to].dis > dis[tmp.pos].dis + e[i].len) {
				//如果s到当前遍历到节点的距离大于经过tmp节点到达当前遍历到节点的距离，即可以进行距离的更新
				dis[to].dis = dis[tmp.pos].dis + e[i].len;
				q.push({to,dis[to].dis});
			}
		}
	}
}

int main() {
	scanf("%d%d%d", &n, &m, &s);
	for (int i = 1; i <= n; i++) dis[i].dis = 2147483647;//毒瘤，无解要输出2^31-1
	for (int i = 1; i <= m; i++) {
		int u, v, l;
		scanf("%d%d%d", &u, &v, &l);
		add(u, v, l); //有向
	}
	dijkstra();
	for (int i = 1; i <= n; i++) {
		printf("%d ", dis[i].dis);
	}
}
```