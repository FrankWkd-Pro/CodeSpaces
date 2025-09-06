#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N = 100010;
int m;
int e[N], l[N], r[N], idx;

void insert(int a, int x) {
	e[idx] = x;
	l[idx] = a;
	r[idx] = r[a];
	l[r[a]] = idx;
	r[a] = idx ++ ;
}

void remove(int a) {
	l[r[a]] = l[a];
	r[l[a]] = r[a];
}

int main() {
	cin >> m;

	r[0] = 1, l[1] = 0;
	idx = 2;
	while (m--) {
		string op;
		cin >> op;
		int k, x;
		if (op == "L") {
			cin >> x;
			insert(0, x);
		} else if (op == "R") {
			cin >> x;
			insert(l[1], x);
		} else if (op == "D") {
			cin >> k;
			remove(k + 1);
		} else if (op == "IL") {
			cin >> k >> x;
			insert(l[k + 1], x);
		} else {
			cin >> k >> x;
			insert(k + 1, x);
		}
	}

	for (int i = r[0]; i != 1; i = r[i])
		cout << e[i] << ' ';

	return 0;
}