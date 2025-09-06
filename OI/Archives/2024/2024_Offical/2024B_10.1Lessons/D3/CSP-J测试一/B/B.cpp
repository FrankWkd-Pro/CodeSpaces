#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
bool check[N];

int main() {

	freopen("wareouse.in", "r", stdin);
	freopen("warehouse.out", "w", stdout);

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		char s[10];
		int x;
		scanf("%s%d", s, &x);
		if (s[0] == 'A') {
			if (check[x]) {
				printf("Error\n");
			} else {
				check[x] = 1;
				printf("Yes\n");
			}
		} else if (s[0] == 'D') {
			if (!check[x]) {
				printf("Error\n");
			} else {
				check[x] = 0;
				printf("Yes\n");
			}
		} else {
			if (check[x]) {
				printf("Yes\n");
			} else {
				printf("No\n");
			}
		}

	}
	return 0;
}