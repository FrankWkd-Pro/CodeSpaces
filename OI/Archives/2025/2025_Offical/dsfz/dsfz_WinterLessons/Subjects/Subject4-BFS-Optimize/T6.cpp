#include<bits/stdc++.h>
using namespace std;
int dx[4] = {1, -1, -1, 1};
int dy[4] = {1, 1, -1, -1};
char a[5] = "\\/\\/";
int ix[4] = {0, -1, -1, 0};
int iy[4] = {0, 0, -1, -1};
deque <int> x;
deque <int> y;
char mp[505][505]; //���ͼ
int vis [505][505]; //��¼��̲���
int l, c; //l:line������c:column����
void dfs() {
	memset(vis, 0x3f, sizeof(vis)); //��ʼ��
	x.push_back(0);  //������
	y.push_back(0);
	vis[0][0] = 0;
	while (!x.empty()) { //���Ѱ���
		int xx = x.front();
		int yy = y.front();
		x.pop_front();
		y.pop_front();
		for (int i = 0; i < 4; i++) {
			int dnx = xx + dx[i];
			int dny = yy + dy[i];
			int inx = xx + ix[i];
			int iny = yy + iy[i];
			if (dnx >= 0 && dnx <= l && dny >= 0 && dny <= c) { //���Ż���֦
				if (a[i] != mp[inx][iny]) { //������ͼ�ĵ���״̬������������ߵĵ���״̬�Ƿ�һ��
					int t = vis[xx][yy] + 1; //��һ�¾�Ҫת�򣬲���+1
					if (t < vis[dnx][dny]) { //�����ԭ���Ĳ���С�������
						x.push_back(dnx); //ת��϶����粻ת��ã�����Ҫ���ѣ��Ӷ�β���
						y.push_back(dny);
						vis[dnx][dny] = t;
					}
				} else { //���һ�¾Ͳ���ת��
					int t = vis[xx][yy]; //��������
					if (t < vis[dnx][dny]) { //������ԭ����С�������
						x.push_front(dnx); //����ת��϶����ã�Ҫ���ѣ��Ӷ������
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
		if ((l + c) % 2 == 1) //����յ���������������
			cout << "NO SOLUTION\n"; //�޽�
		else dfs();
	}
}
