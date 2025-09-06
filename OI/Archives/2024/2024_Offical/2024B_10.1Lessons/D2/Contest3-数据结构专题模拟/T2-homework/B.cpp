/*
By: FrankWKD
From: Self
Date: 2024/10/03
Note: -T1-fileIO
*/
#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
int n;
long long ans;
int f[100010];//times

struct node {
	int d, p;
} s[100010];

bool cmp(node x, node y) {
	return x.p > y.p;
}

int find(int x) {
	if (f[x] < 0)//δ����ǹ�
		return x;
	f[x] = find(f[x]);//�ҵ���
	return f[x];
}

/*
5
d p
2 10
1 7
4 6
3 5
5 5

f: 0 1 2 3 4 5 6 7 8 9 10
   * * * * * * * * * * *
ans: 0
i:   1
*/
int main() {
	freopen("homework.in", "r", stdin);
	freopen("homework.out", "w", stdout);
	memset(f, -1, sizeof(f));
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> s[i].d >> s[i].p;
	}
	sort(s + 1, s + n + 1, cmp);//�������򰴷���
	for (int i = 1; i <= n; i++) {
		int x = find(s[i].d);//�������ǹ��ͷ��ظ������򷵻�s[i].d
		if (x > 0) {
			ans += s[i].p;
			f[x] = x - 1;//����鿴�Ƿ��п�ȱ��λ��
		}
	}
	cout << ans;
	return 0;
}