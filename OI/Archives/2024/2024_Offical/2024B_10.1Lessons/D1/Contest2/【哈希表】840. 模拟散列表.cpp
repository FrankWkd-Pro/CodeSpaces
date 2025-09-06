#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
const int N = 101013;
int h[N], ne[N], v[N], idx;

void insert(int x) {
	int k = (x % N + N) % N;
	ne[idx] = h[k];
	h[k] = idx;
	v[idx ++] = x;
}

bool find(int x) {
	int k = (x % N + N) % N;
	for (int i = h[k]; ~i; i = ne[i])
		if (v[i] == x)
			return true;

	return false;
}

int main() {
	memset(h, -1, sizeof(h));
	int n, x;
	char op[5];
	scanf("%d", &n);
	while (n -- ) {
		scanf("%s%d", op, &x);
		if (!strcmp("I", op))
			insert(x);
		else {
			if (find(x))
				printf("Yes\n");
			else
				printf("No\n");
		}
	}
	return 0;
}
