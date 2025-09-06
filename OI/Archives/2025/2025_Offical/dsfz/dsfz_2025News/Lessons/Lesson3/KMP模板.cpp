#include<bits/stdc++.h>
using namespace std;
const int N = 1010000, MOD = 1e9+7;
const int P = 131;

char p[N], s[N]; //p=Pattern
int nxt[N];
int n, m;
/*
abacdaba
00100123


*/
int main() {

	scanf("%d%s", &n, p + 1);
	for (int i = 2, j = 0; i <= n; i++) {
		while (j and p[i] != p[j + 1]) j = nxt[j];
		if (p[i] == p[j + 1]) j++;
		nxt[i] = j;
	}
	printf("%d\n", n-nxt[n]);

	return 0;
}
