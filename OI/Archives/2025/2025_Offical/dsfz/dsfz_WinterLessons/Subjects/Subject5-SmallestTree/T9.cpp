#include<bits/stdc++.h>
using namespace std;
struct node {
	int x, y, z;
} a[1001], b[1001];
int n, m, i, t, f[1001], d[1001], c[1001], cnt, ans, xx, yy;
int find(int x) { //k�㷨
	if (f[x] == x) return x;
	f[x] = find(f[x]);
	return f[x];
}
void dfs(int now, int k, int x) { //now��ǰλ�ã�k��ʾ���������x��Ȩֵ������d������λ��
	if (now > b[x].y) { //����ѹ��Ҷ˵�
		if (k == d[x]) cnt++; //���������+1
		return;
	}
	int p[101];
	for (int i = 1; i <= n; i++) p[i] = f[i]; //�洢
	xx = find(a[now].x);
	yy = find(a[now].y);
	if (xx != yy) { //������Լ�����С������
		f[xx] = yy;
		dfs(now + 1, k + 1, x);
	}
	for (int i = 1; i <= n; i++) f[i] = p[i]; //��ԭ
	dfs(now + 1, k, x);

}
int cmp(node a, node b) {
	return a.z < b.z;
}
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) //����
		scanf("%d %d %d", &a[i].x, &a[i].y, &a[i].z);
	sort(a + 1, a + 1 + m, cmp); //��������k�㷨������ͬһȨֵ
	for (int i = 1; i <= n; i++) //k�㷨��ʼ��
		f[i] = i;
	a[0].z = -INT_MAX;
	t = 0;
	for (int i = 1; i <= m; i++)
		if (a[i].z == a[i - 1].z) { //����ͬһȨֵ������λ�ã���������
			b[t].y++;
			c[i] = t; //y�����Ҷ˵�
		} else {
			t++;
			b[t].x = i;
			b[t].y = i;
			c[i] = t; //x��ʾ��˵㣬t��ʾȨֵ����
		}
	cnt = 0;
	for (int i = 1; i <= m; i++) {
		xx = find(a[i].x);
		yy = find(a[i].y); //Ѱ����С������
		if (xx != yy) {
			f[xx] = yy;
			d[c[i]]++; //d�洢��Ȩֵ��Ҫ�ı���
			cnt++;
		}
		if (cnt == n - 1) break; //��С�������ҵ�
	}
	if (cnt != n - 1) {
		printf("0");    //û�ҵ�
		exit(0);
	}
	for (int i = 1; i <= n; i++) f[i] = i; //��ʼ
	ans = 1;
	for (int i = 1; i <= t; i++)
		if (d[i] > 0) {
			cnt = 0;
			dfs(b[i].x, 0, i); //����
			ans = (ans * cnt) % 31011; //�˷�ԭ��
			for (int j = b[i].x; j <= b[i].y; j++)  {// ����
				xx = find(a[j].x);
				yy = find(a[j].y);
				if (xx != yy) {
					f[xx] = yy;
				}
			}

		}
	printf("%d\n", ans);
}
