#include <bits/stdc++.h>
using namespace std;
int t[12011][1203], tot[100101], idx;
char s[100010];


void ins(char s[]) {
	int f = 0;
	int len = strlen(s);
	for (int i = 0; i < len ; i++) {
		int v = s[i] - 'a' + 1;
		if (!t[f][v]) {
			t[f][v] = ++idx;
		}
		f = t[f][v];
	}
	tot[f]++;
}

int q(char s[]) {
	int f = 0;
	int len = strlen(s);
	for (int i = 0; i < len; i++) {
		int v = s[i] - 'a' + 1;
		if (!t[f][v]) {
			return 0;
		}
		f = t[f][v];
	}
	return tot[f];
}

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		char op[2];
		scanf("%s%s", op, s);
		if (op[0] == 'I') {
			ins(s);

		} else {
			cout << q(s) << endl;
		}
	}
}
