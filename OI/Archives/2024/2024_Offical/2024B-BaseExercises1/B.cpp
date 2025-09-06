//#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
int mp[2010][2010];
vector<int> pt[2010];
int n, m;
int ans = 0;

void bfs(int a, int x, int bk) {
	if (bk == 0 and a == x) {
		return ;
	}
	if (mp[a][x] == true)
		return ;
	ans++;
	mp[a][x] = true;
	for (int i = 0; i < pt[x].size(); i++)
		bfs(a, pt[x][i], 0);
}

int main() {
	freopen("tour.in", "r", stdin);
	freopen("tour.out", "w", stdout);
	scanf("%d%d", &n, &m);
	while (m--) {
		int x, y;
		scanf("%d%d", &x, &y);
		pt[x].push_back(y);
	}
	for (int i = 1; i <= n; i++)
		bfs(i, i, 1);
	cout << ans;
	return 0;
}

