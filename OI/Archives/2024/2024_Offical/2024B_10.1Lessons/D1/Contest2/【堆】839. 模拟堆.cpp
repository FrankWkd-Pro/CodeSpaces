#include <bits/stdc++.h>
using namespace std;
const int N = 100010;

int heap[N], ss;
int heap_node[N], node_heap[N];
int n, cnt;

void heap_swap(int a, int b) {
	swap(heap[a], heap[b]);
	swap(node_heap[heap_node[a]], node_heap[heap_node[b]]);
	swap(heap_node[a], heap_node[b]);
}

void up(int x) {
	while (x / 2 && heap[x / 2] > heap[x]) {
		heap_swap(x / 2, x);
		x /= 2;
	}
}

void down(int x) {
	int t = x;
	if (x * 2 <= ss && heap[x * 2] < heap[t])
		t = x * 2;
	if (x * 2 + 1 <= ss && heap[x * 2 + 1] < heap[t])
		t = x * 2 + 1;

	if (t != x) {
		heap_swap(t, x);
		down(t);
	}
}


int main() {
	scanf("%d", &n);

	while (n --) {
		char op[3];
		scanf("%s", op);

		if (*op == 'I') {
			++ ss;
			++ cnt;
			heap_node[ss] = cnt;
			node_heap[cnt] = ss;
			int x;
			scanf("%d", &x);
			heap[ss] = x;
			up(ss);
		} else if (*op == 'P')
			printf("%d\n", heap[1]);
		else if (*op == 'D') {
			if (op[1] == 'M') {
				heap_swap(1, ss --);
				down(1);
			} else {
				int k;
				scanf("%d", &k);
				int t = node_heap[k];
				heap_swap(t, ss --);
				down(t);
				up(t);
			}
		} else {
			int k, x;
			scanf("%d%d", &k, &x);
			int t = node_heap[k];
			heap[t] = x;
			down(t);
			up(t);
		}
	}
}