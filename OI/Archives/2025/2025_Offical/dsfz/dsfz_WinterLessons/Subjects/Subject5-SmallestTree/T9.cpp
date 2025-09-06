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
