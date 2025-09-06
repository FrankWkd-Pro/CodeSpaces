#include <bits/stdc++.h>
#include <queue>
using namespace std;
const int N = 50005;
int m, n, x, y, last, head[N], sum;
int dis[N];
bool vi[N], use[N];
char xx;
struct edge {
	int to, next;
} a[N];
struct node {
	int num, dis;
	bool operator < (const node x) const {
		return x.dis < dis;
	}
};
priority_queue <node> f;
void insert(int x, int y) {
	sum++;
	a[sum].to = y;
	a[sum].next = head[x];
	head[x] = sum;
}
void dijkstra() {
	memset(dis, 0x7f, sizeof(dis));
	for (int i = 1; i <= m; i++) {
		if (use[i]) {
			dis[i] = 0;
			f.push((node) {
				i, 0
			});
		}
	}
	int x, y, z;
	while (!f.empty()) {
		x = f.top().num;
		f.pop();
		if (vi[x]) continue;
		vi[x] = true;
		for (int i = head[x]; i; i = a[i].next) {
			y = a[i].to; //用零边更新
			if (dis[y] > dis[x]) {
				dis[y] = dis[x];
				f.push((node) {
					y, dis[y]
				});
			}
		}
		y = x % m;
		z = x - y;
		if (y == 0) z = x - m;
		for (int i = 1; i <= m; i++) {
			y = z + i; //用边权为1的边更新
			if (use[y] && dis[y] > dis[x] + 1) {
				dis[y] = dis[x] + 1;
				f.push((node) {
					y, dis[y]
				});
			}
		}
	}
}
int main() {
	scanf("%d %d", &m, &n);
	for (int i = 1; i <= m; i++) {
		scanf("%d", &last);
		xx = getchar();
		while (xx == ' ') {
			scanf("%d", &x);
			insert((last - 1)*m + i, (x - 1)*m + i); //建零边，反正都是零边，就不用边权了
			use[(last - 1)*m + i] = use[(x - 1) * m + i] = true; //记录有没有用到
			last = x;
			xx = getchar();
		}
	}
	dijkstra();
	x = 0xffffff;
	y = (n - 1) * m;
	for (int i = 1; i <= m; i++)
		if (dis[y + i] < x) x = dis[y + i];
	if (x == 0xffffff) printf("NO\n");
	else printf("%d\n", x);
	return 0;
}

