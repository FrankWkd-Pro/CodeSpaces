//Date: 2024/10/04
//#pragma GCC optimize(2)
//#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
int a[1010][1010];
bool f[1010][1010];
int q[1010101][4];
int h, t;
int n, m;

int dx[5] = {0, -1, 0, 1, 0}, dy[5] = {0, 0, 1, 0, -1};

void bfs(int x, int y) {
	h = 1;
	t = 1;
	q[h][1] = x;
	q[h][2] = y;
	q[h][3] = 0;
	f[x][y] = true;
	while (t <= h) {
		for (int i = 1; i <= 4; i++) {
			int xx = q[t][1] + dx[i];
			int yy = q[t][2] + dy[i];
			if (xx < 1 or xx > n or yy < 1 or yy > n)
				continue;
			if (f[xx][yy])
				continue;
			if (a[xx][yy] == 1)
				continue;
			h++;
			q[h][1] = xx;
			q[h][2] = yy;
			q[h][3] = q[t][3] + 1;
			f[xx][yy] = true;
			if (xx == n and yy == m) {
				cout << q[h][3] ;
				return ;
			}
		}
		t++;
	}
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}
	bfs(1, 1);
}
