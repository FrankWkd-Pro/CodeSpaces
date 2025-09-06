#include<bits/stdc++.h>
using namespace std;
const int N = 1010, MOD = 1e9+7;
long long dep, ans[N], now[N];
bool st;
long long gcd(long long a, long long b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}
void dfs(long long a, long long b, long long d) {
	if (dep == d) {
		if (a == 1 && now[d - 1] < b) {
			now[d] = b;
			if (!st || ans[d] > now[d]) {
				for (int i = 1; i <= d; i++) {
					ans[i] = now[i];
				}
				st = true;
			}
		}
		return;
	}
	long long left = max(b / a + 1, now[d - 1] + 1), right = 1e7;
	right = min(right, (dep - d + 1) * b / a);
	for (long long i = left; i <= right; i++) {
		now[d] = i;
		long long aa = a * i - b, bb = b * i, g = gcd(aa, bb);
		dfs(aa / g, bb / g, d + 1);
	}
}
long long a, b;
int main() {
	cin >> a >> b;
	now[0] = 1;
	for (dep = 1; !st; dep++) {
		dfs(a, b, 1);
	}
	for (int i = 1; i < dep; i++) {
		cout << ans[i] << " ";
	}
	puts("");
	return 0;
}
