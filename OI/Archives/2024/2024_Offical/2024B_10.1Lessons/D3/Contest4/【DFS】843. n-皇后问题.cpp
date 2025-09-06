#include <bits/stdc++.h>

using namespace std;

const int N = 20;
int n;
char g[N][N];
bool col[N], dg[N], udg[N];

void dfs(int u) {

	if (u == n) {
		for (int i = 0; i < n; i++)
			puts(g[i]);
		puts("");
		return;
	}

	for (int i = n - 1; i >= 0; i--)
		if (!col[i] && !dg[u + i] && !udg[n - u + i]) {
			g[u][i] = 'Q';
			col[i] = dg[u + i] = udg[n - u + i] = true;

			dfs(u + 1);

			col[i] = dg[u + i] = udg[n - u + i] = false;
			g[u][i] = '.';
		}
}


int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			g[i][j] = '.';

	dfs(0);
	return 0;
}