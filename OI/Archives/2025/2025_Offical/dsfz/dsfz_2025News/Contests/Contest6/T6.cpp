#include <bits/stdc++.h>
using namespace std;
int n, ch[1000010][30], cnt[1000010];
char s[1000010];
int idx;
void insert() {
	int p = 0;
	for (int i = 0; s[i]; i++) {
		int x = s[i] - 'a';
		if (ch[p][x] == 0) ch[p][x] = ++idx;
		p = ch[p][x];//下移到当前节点(下一次起点)
	}
	cnt[p]++;//节点编号++
}
int query() {
	int x, p = 0;
	for (int i = 0; s[i]; i++) {
		x = s[i] - 'a';
		if (ch[p][x] == 0) return 0;
		p = ch[p][x];
	}
	return cnt[p];
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%s", s);
		insert();
	}
	cin >> n;
	for (int i = 1; i <= n; i++) {
		scanf("%s", s);
		printf("%d\n", query());
	}
	
	return 0;
}
