#include<bits/stdc++.h>
using namespace std;
int dx[4] = {1, -1, -1, 1};
int dy[4] = {1, 1, -1, -1};
char a[5] = "\\/\\/";
int ix[4] = {0, -1, -1, 0};
int iy[4] = {0, 0, -1, -1};
deque <int> x;
deque <int> y;
char mp[505][505]; //存地图
int vis [505][505]; //记录最短步数
int l, c; //l:line行数，c:column列数
void dfs() {
	memset(vis, 0x3f, sizeof(vis)); //初始化
	x.push_back(0);  //起点入队
	y.push_back(0);
	vis[0][0] = 0;
	while (!x.empty()) { //广搜板子
		int xx = x.front();
		int yy = y.front();
		x.pop_front();
		y.pop_front();
		for (int i = 0; i < 4; i++) {
			int dnx = xx + dx[i];
			int dny = yy + dy[i];
			int inx = xx + ix[i];
			int iny = yy + iy[i];
			if (dnx >= 0 && dnx <= l && dny >= 0 && dny <= c) { //最优化剪枝
				if (a[i] != mp[inx][iny]) { //看看地图的电线状态和往这个方向走的电线状态是否一致
					int t = vis[xx][yy] + 1; //不一致就要转向，步数+1
					if (t < vis[dnx][dny]) { //如果比原来的步数小，就入队
						x.push_back(dnx); //转向肯定不如不转向好，所以要后搜，从队尾入队
						y.push_back(dny);
						vis[dnx][dny] = t;
					}
				} else { //如果一致就不用转向
					int t = vis[xx][yy]; //步数不变
					if (t < vis[dnx][dny]) { //步数比原来的小才能入队
						x.push_front(dnx); //不用转向肯定更好，要先搜，从队首入队
						y.push_front(dny);
						vis[dnx][dny] = t;
					}
				}
			}
		}

	}
	cout << vis[l][c] << endl;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		memset(vis, 0, sizeof vis);
		x.clear();
		y.clear();
		cin >> l >> c;
		for (int i = 0; i < l; i++) cin >> mp[i];
		if ((l + c) % 2 == 1) //如果终点横纵坐标和是奇数
			cout << "NO SOLUTION\n"; //无解
		else dfs();
	}
}
