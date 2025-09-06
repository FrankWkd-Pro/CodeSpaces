#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>

#define int long long
#define inf 0x3f3f3f3f
using namespace std;
const int N = 100000;
int n, m, need;
int tot, ans = inf;
struct node {
	int u, v, w, col;
	bool operator<(const node &ret) const {
		if (w == ret.w)
			return col < ret.col;
		return w < ret.w;
	}
} e[N + 10];
int fa[N + 10];
void init() {
	tot = 0;
	for (int i = 1; i <= n; i++) fa[i] = i;
}
int getfa(int x) {
	if (fa[x] == x) return x;
	return fa[x] = getfa(fa[x]);
}
int mst() {
	int ret = 0, num = 0;
	init();
	sort(e + 1, e + m + 1);
	for (int i = 1; i <= m; i++) {
		int u = e[i].u, v = e[i].v, w = e[i].w, col = e[i].col;
		int fu = getfa(u), fv = getfa(v);
		if (fu != fv) {
			fa[fu] = fv;
			if (!col) tot++;
			ret += w;
			num++;
		}
		if (num == n - 1) break;
	}
	return ret;
}
signed main() {
	scanf("%lld%lld%lld", &n, &m, &need);
	for (int i = 1; i <= m; i++) scanf("%lld%lld%lld%lld", &e[i].u, &e[i].v, &e[i].w, &e[i].col), e[i].u++, e[i].v++;
	int l = -300, r = 300;
	while (l < r) {
		int mid = (l + r) >> 1;
		for (int i = 1; i <= m; i++) if (!e[i].col) e[i].w += mid;
		int sum = mst();
		if (tot >= need) ans = sum - need * mid;
		if (tot < need) r = mid;
		else l = mid + 1;
		for (int i = 1; i <= m; i++) if (!e[i].col) e[i].w -= mid;
	}
	printf("%lld\n", ans);
	return 0;
}

