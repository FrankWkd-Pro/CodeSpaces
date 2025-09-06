#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int N = 1010;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

struct node {
	int x, y, color, magic, money;
	//color����ǰ�����ɫ
	//magic���Ƿ�վ��ʹ����ħ���ĵ���
	//money����ǰ����
};

int m, n, color[N][N], ans[N][N];
//color���洢�����ɫ
//ans��Ϊ���仯���������Ĵ洢ÿ���㻨��������


void bfs() {
	queue<node> q;
	q.push({1, 1, color[1][1], 0, 0});//������
	ans[1][1] = 0;//����Ϊ��
	while (!q.empty()) {//��BFS
		node p = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int x1 = p.x + dx[i], y1 = p.y + dy[i];
			if (x1 < 1 || x1 > m || y1 < 1 || y1 > m || (p.magic && color[x1][y1] == 0/*���վ����ʹ��ħ���ĵ��ϣ��Ͳ���ʹ��ħ��*/))//�����Լ�֦
				continue;
			node next = {x1, y1, 0, 0, 0};
			int cost; //��һ�λ��ѵĽ����
			if (color[x1][y1] > 0) {
				// ��һ�֣���һ��������ɫ
				if (color[x1][y1] == p.color) cost = 0;
				else cost = 1;//��1��Ǯ�ߵ�x1,y1
				// û��ʹ��ħ������һ�������ɫ����color[x1][y1]
				next.magic = 0;
				next.color = color[x1][y1];
			} else {
				// �ڶ��֣���һ����û����ɫ
				cost = 2;
				next.magic = 1;
				next.color = p.color;
				// ʹ�ù�ħ������һ�������ɫΪ��ǰ�����ɫʱ����
			}
			next.money = cost + p.money;// ����֮ǰ�Ľ����
			if (next.money < ans[x1][y1]) {//�����Լ�֦�����仯��
				ans[x1][y1] = next.money;//������С����
				q.push(next);//���
			}
		}
	}
}

int main() {
	cin >> m >> n;
	for (int i = 1; i <= n; i++) {
		int x, y, c;
		cin >> x >> y >> c;
		// 0�ͱ�ʾû����ɫ��
		color[x][y] = c + 1;
	}
	memset(ans, 0x3f3f3f3f, sizeof(ans));
	bfs();
	cout << (ans[m][m] == 0x3f3f3f3f ? -1 : ans[m][m]) << endl;
	return 0;
}
