#include <bits/stdc++.h>
using namespace std;
int p[101010], n, m;
int xx[101010];

int find(int x) {
	if (p[x] != x)
		p[x] = find(p[x]);
	return p[x];
}

void count(int a) {
	cout << xx[find(a)] << endl;
}

int main() {

	cin >> n >> m;
	for (int i = 1; i <= n; i++ )
		p[i] = i, xx[i] = 1;
	while (m-- ) {
		string op;
		int a, b;
		cin >> op >> a;
		if (op == "C") {

			cin >> b;

			if (find(a) != find(b)) {

				int t = xx[find(a)] + xx[find(b)];
				p[find(a)] = find(b);
				xx[find(a)] = t;

			} else {
				p[find(a)] = find(b);
			}

		} else if (op == "Q1") {
			cin >> b;
			if (find(a) == find(b))
				puts("Yes");
			else
				puts("No");
		} else {
			count(a);
		}
	}
	return 0;
}