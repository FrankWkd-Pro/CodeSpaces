#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
char a[N], b[N];
int c[N];

int search_opt(char ch) {
	if (ch == '+' || ch == '-')
		return 1;
	if (ch == '*' || ch == '/')
		return 2;
	return 0;
}

int calc(int xx, char op, int yy) {
	if (op == '+')
		return xx + yy;
	if (op == '-')
		return xx - yy;
	if (op == '*')
		return xx * yy;
	if (op == '/')
		return xx / yy;
}

int main() {
	scanf("%s", a);
	int len = strlen(a);
	int i, topb = 0, topc = 0;
	b[0] = '#';
	for (i = 0; i < len; i++) {
		switch (a[i]) {
			case '(':
				b[++topb] = a[i];
				break;
			case '+':
			case '-':
			case '*':
			case '/':
				while (search_opt(a[i]) <= search_opt(b[topb])) {
					int xx = c[topc - 1], yy = c[topc];
					char op = b[topb--];
					c[--topc] = calc(xx, op, yy);
				}
				b[++topb] = a[i];
				break;
			case ')':
				while (b[topb] != '(' && topb > 0) {
					int xx = c[topc - 1], yy = c[topc];
					char op = b[topb--];
					c[--topc] = calc(xx, op, yy);
				}
				topb--;
				break;
			default:
				int temp = a[i] - '0';
				while (a[i + 1] >= '0' && a[i + 1] <= '9') {
					i++;
					temp = temp * 10 + a[i] - '0';
				}
				c[++topc] = temp;
		}
	}
	while (topb > 0) {
		int xx = c[topc - 1], yy = c[topc];
		char op = b[topb--];
		c[--topc] = calc(xx, op, yy);
	}
	cout << c[topc] << endl;
	return 0;
}