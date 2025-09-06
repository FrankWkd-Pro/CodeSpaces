//#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
vector <int> head;
vector <int> tail;

void mid_num() {
	int mid = head.size() + tail.size() + 1 >> 1;
	if (head.size() >= mid) {
		printf("%d\n", head[head.size() - mid]);
	} else {
		printf("%d\n", tail[mid - head.size() - 1]);
	}

}

int main() {
	freopen("middle.in", "r", stdin);
	freopen("middle.out", "w", stdout);
	int n;
	scanf("%d", &n);
	int k = 1;
	int nownum = -1;
	for (int i = 1; i <= n; i++) {
		int op;
		scanf("%d", &op);
		if (op == 2) {
			head.push_back(k++);
		} else if (op == 1) {
			tail.push_back(k++);
		} else {
			mid_num();
		}
	}

	return 0;
}

