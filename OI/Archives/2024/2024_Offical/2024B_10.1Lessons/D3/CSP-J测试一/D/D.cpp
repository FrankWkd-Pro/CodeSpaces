#include <bits/stdc++.h>
using namespace std;
const long long inf = (long long)2e18;
const int N = 1234567;
int h[N], n;
long long m;
vector <int> ev[N];
long long ans[N];
long long sum[N];

int check(int mid) {
	for (int i = 0; i < n; i++)
		ans[i] = 0;
	for (int rot = 0; rot < 2; rot++) {
		sum[0] = h[0];
		for (int i = 1; i < n; i++)
			sum[i] = sum[i - 1] + h[i];
		for (int i = 0; i < n; i++)
			ev[i].clear();
		for (int i = 0; i < n; i++) {
			int j = i + mid - h[i];
			if (j < n) {
				ev[j].push_back(i);
			}
		}
		int mx = -1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < (int) ev[i].size(); j++) {
				mx = max(mx, ev[i][j]);
			}
			if (mx >= 0) {
				int from = mid - 1;
				int to = mid - (i - mx) + 1;
				ans[i] += (to + from) * 1LL * (from - to + 1) / 2;
				ans[i] -= (sum[i - 1] - sum[mx]);
			} else {
				ans[i] += inf;
			}
		}
		for (int i = 0; i < n - i - 1; i++) {
			swap(h[i], h[n - i - 1]);
			swap(ans[i], ans[n - i - 1]);
		}
	}
	for (int i = 0; i < n; i++) {
		ans[i] += mid - h[i];
		if (ans[i] <= m) {
			return true;
			break;
		}
	}
	return false;
}

int main() {
	freopen("tower.in","r",stdin);
	freopen("tower.out","w",stdout);
	scanf("%d%lld", &n, &m);
	int low = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", h + i);
		low = max(low, h[i]);
	}
	int final_ans = 0;
	int high = (int)1e9;
	while (low <= high) {
		int mid = (low + high) >> 1;
		if (check(mid)) {
			low = mid + 1;
			final_ans = mid;
		} else {
			high = mid - 1;
		}
	}
	printf("%d\n", final_ans);
	return 0;
}