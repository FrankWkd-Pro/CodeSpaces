#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 50;
const int M = 84e5;
int wm, n;
int w[N];
int mk[M], cnt;
ll ans;

void dfs(int i, ll sum, int end, int type) {
	if (i > end) {
		if (type == 1) mk[++cnt] = sum;
		else {
			int p = upper_bound(mk + 1, mk + cnt + 1, wm - sum) - mk;
			ans = max(ans, mk[p - 1] + sum);
		}
		return;
	}

	dfs(i + 1, sum, end, type);
	if (sum + w[i] <= wm) dfs(i + 1, sum + w[i], end, type);
}
int main() {
	scanf("%d%d", &wm, &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", w + i);

	sort(w + 1, w + n + 1, greater<int>());

	dfs(1, 0, n / 2, 1);
	sort(mk + 1, mk + cnt + 1);
	cnt = unique(mk + 1, mk + cnt + 1) - mk - 1;

	dfs(n / 2 + 1, 0, n, 2);
	printf("%lld", ans);
}
