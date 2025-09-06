#include <bits/stdc++.h>
const int N = 5010000;
using namespace std;
int la, lb, res;
char a[N], b[N];
int p[N], f[N];
int St[N], top;

int main() {
	int i, j;
	scanf("%s", a + 1);
	scanf("%s", b + 1);
	la = strlen(a + 1);
	lb = strlen(b + 1);
	for (i = 2, j = 0; i <= lb; i++) {
		while (j && b[i] != b[j + 1])
			j = p[j];
		if (b[i] == b[j + 1])
			j++;
		p[i] = j;
	}
	for (i = 1, j = 0; i <= la; i++) {
		while (j && a[i] != b[j + 1])
			j = p[j];
		if (a[i] == b[j + 1])
			j++;
		f[i] = j;
		St[++top] = i;
		if (j == lb)
			top -= lb, j = f[St[top]];
	}
	for (i = 1; i <= top; i++)
		printf("%c", a[St[i]]);
	return 0;
}