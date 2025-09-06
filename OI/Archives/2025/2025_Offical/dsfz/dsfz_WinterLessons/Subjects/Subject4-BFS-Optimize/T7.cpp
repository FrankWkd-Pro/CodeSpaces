#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int N = 1010;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

struct node {
	int x, y, color, magic, money;
	//color：当前点的颜色
	//magic：是否站在使用了魔法的点上
	//money：当前花销
};

int m, n, color[N][N], ans[N][N];
//color：存储点的颜色
//ans：为记忆化搜索而生的存储每个点花销的数组


void bfs() {
	queue<node> q;
	q.push({1, 1, color[1][1], 0, 0});//起点入队
	ans[1][1] = 0;//花销为零
	while (!q.empty()) {//跑BFS
		node p = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int x1 = p.x + dx[i], y1 = p.y + dy[i];
			if (x1 < 1 || x1 > m || y1 < 1 || y1 > m || (p.magic && color[x1][y1] == 0/*如果站在了使用魔法的点上，就不能使用魔法*/))//最优性剪枝
				continue;
			node next = {x1, y1, 0, 0, 0};
			int cost; //这一次花费的金币数
			if (color[x1][y1] > 0) {
				// 第一种：下一个点有颜色
				if (color[x1][y1] == p.color) cost = 0;
				else cost = 1;//花1块钱走到x1,y1
				// 没有使用魔法，下一个点的颜色就是color[x1][y1]
				next.magic = 0;
				next.color = color[x1][y1];
			} else {
				// 第二种：下一个点没有颜色
				cost = 2;
				next.magic = 1;
				next.color = p.color;
				// 使用过魔法，下一个点的颜色为当前点的颜色时最优
			}
			next.money = cost + p.money;// 加上之前的金币数
			if (next.money < ans[x1][y1]) {//最优性剪枝（记忆化）
				ans[x1][y1] = next.money;//更新最小花销
				q.push(next);//入队
			}
		}
	}
}

int main() {
	cin >> m >> n;
	for (int i = 1; i <= n; i++) {
		int x, y, c;
		cin >> x >> y >> c;
		// 0就表示没有颜色了
		color[x][y] = c + 1;
	}
	memset(ans, 0x3f3f3f3f, sizeof(ans));
	bfs();
	cout << (ans[m][m] == 0x3f3f3f3f ? -1 : ans[m][m]) << endl;
	return 0;
}
