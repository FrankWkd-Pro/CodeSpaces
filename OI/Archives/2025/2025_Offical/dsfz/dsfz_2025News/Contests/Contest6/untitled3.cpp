#include <bits/stdc++.h>
using namespace std;
//Kruskal
int f[1010100];
struct node {
	int x, y;
} a[1010101];
struct edge {
	int x, y;
	double z;
} e[1010101];
int n, m,  cnt, tot;
double ans;
int find(int x) {
	if (f[x] != x)  return f[x] = find(f[x]);
	return x;
}
bool cmp(edge xx, edge yy) {
	return xx.z < yy.z;
}
double calc(int i, int j) {
	return sqrt((a[i].x - a[j].x) * (a[i].x - a[j].x) + (a[i].y - a[j].y) *
	            (a[i].y - a[j].y));
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		scanf("%d%d",&n,&m);
		tot = 0,ans = 0,cnt = 0;
		for (int i = 1; i <= m; i++) {
			scanf("%d%d", &a[i].x, &a[i].y);
		}
		for (int i = 1; i <= m; i++) {
			for (int j = i+1; j <= m; j++) {
				e[++cnt] = {i, j, calc(i, j)};
			}
		}
		sort(e + 1, e + cnt + 1, cmp);
		for (int i = 1; i <= m; i++) {
			f[i] = i;
		}
		for (int i = 1; i <= cnt; i++) {
			if (find(e[i].x) != find(e[i].y)) {
				ans += e[i].z;
				tot++;
				f[find(e[i].x)] = f[find(e[i].y)];
			}
			if (tot == m - n) {
				printf("%.2lf\n",e[i].z);
				goto endd;
			}
		}
endd:
		;
	}
}
