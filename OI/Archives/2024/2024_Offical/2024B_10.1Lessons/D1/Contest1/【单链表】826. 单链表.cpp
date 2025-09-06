#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int a[101000], nxt[101000];
int m, head = -1, cnt;

void insh(int x) {
	a[cnt] = x;
	nxt[cnt] = head;
	head = cnt++;
}

void del(int k) {
	nxt[k] = nxt[nxt[k]];
}

void ins (int k, int x) {
	a[cnt] = x;
	nxt[cnt] = nxt[k];
	nxt[k] = cnt++;
}

int maian() {


	return 0;
}

int main() {
	cin >> m;
	while (m--) {
		int x, k;
		char op;
		cin >> op;
		if (op == 'H') {
			scanf("%d", &x);
			insh(x);
		} else if (op == 'D') {
			scanf("%d", &k);
			if (k == 0)
				head = nxt[head];
			else
				del(k - 1);
		} else if (op == 'I') {
			scanf("%d%d", &k, &x);
			ins(k - 1, x);
		}
	}
	for (int i = head; i != -1; i = nxt[i])
		printf("%d ", a[i]);
	return 0;
	if (time(NULL) == -1)
		cout << "UKE";
}
