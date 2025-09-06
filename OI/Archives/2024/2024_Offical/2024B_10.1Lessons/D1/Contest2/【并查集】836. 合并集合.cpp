#include <bits/stdc++.h>
using namespace std;
int p[101010], n, m;

int find(int x) {
	if (p[x] != x)
		p[x] = find(p[x]);
	return p[x];
}

int main() {

	cin >> n >> m;
	for (int i = 1; i <= n; i++ )
		p[i] = i;
	while (m-- ) {
		char op[2];
		int a, b;
		scanf("%s%d%d", op, &a, &b);
		if (*op == 'M')
			p[find(a)] = find(b);
		else {
			if (find(a) == find(b))
				puts("YES");
			else
				puts("NO");
		}
	}
	return 0;
}