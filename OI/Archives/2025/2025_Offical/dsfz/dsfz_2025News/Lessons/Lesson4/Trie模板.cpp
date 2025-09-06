#include<bits/stdc++.h>
using namespace std;
const int N = 10010, MOD = 1e9+7;
const int P = 131;
int s[N][26], tot[N], idx;
char str[N];
void add(char str[]) {
	int f = 0;
	int len = strlen(str);
	for (int i = 0 ; i < len; i++) {
		int u = str[i] - 'a';
		if (!s[f][u]) s[f][u] = ++idx;
		f = s[f][u];
	}
	tot[f]++;
}
int query(char str[]) {
	int f = 0;
	int len = strlen(str);
	for (int i = 0; i < len; ++i) {
		int u = str[i] - 'a';
		if (!s[f][u]) return 0;
		f = s[f][u];
	}
	return tot[f];
}
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		char op[2];
		cin >> op + 1;

	}
	return 0;
}
