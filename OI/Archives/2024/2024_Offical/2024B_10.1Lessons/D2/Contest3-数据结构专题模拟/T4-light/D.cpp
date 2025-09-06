#include <bits/stdc++.h>
using namespace std;
int n, m, a[1000005];
long long ans = 0;
long long cnt[1000005][2];

long long check()  {
	long long pre = 0;
	for (int i = 2; i <= n; i++) {
		if (a[i] > a[i - 1])
			pre += a[i] - a[i - 1];
		else
			pre += a[i] + m - a[i - 1];
	}
	return pre;
}

void change(int l, int r, int s, int d) {
	cnt[l][0] += s;
	cnt[r + 1][0] -= s;
	cnt[l + 1][1] += d;
	cnt[r + 1][1] -= (r - l + 1) * d;
	cnt[r + 2][1] += (r - l) * d;
}

int main() {
	freopen("light.in","r",stdin);
	freopen("light.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 2; i <= n; i++) {
		if (a[i] > a[i - 1]) {
			if (a[i] - a[i - 1] >= 2)
				change(a[i - 1] + 2, a[i], 1, 1);
		} else {
			if (m - a[i - 1] >= 2)
				change(a[i - 1] + 2, m, 1, 1), change(1, a[i], m - a[i - 1], 1);
			if (m - a[i - 1] == 1)
				change(1, a[i], 1, 1);
			if (m == a[i - 1]) {
				if (a[i] >= 2)
					change(2, a[i], 1, 1);
			}
		}
	}

	for (int i = 2; i <= m + 1; i++)
		cnt[i][0] += cnt[i - 1][0], cnt[i][1] += cnt[i - 1][1];
	for (int i = 2; i <= m + 1; i++)
		cnt[i][1] += cnt[i - 1][1];

	for (int i = 1; i <= m; i++)
		ans = max(ans, cnt[i][0] + cnt[i][1]);
	cout << check() - ans << endl;
	return 0;
}
