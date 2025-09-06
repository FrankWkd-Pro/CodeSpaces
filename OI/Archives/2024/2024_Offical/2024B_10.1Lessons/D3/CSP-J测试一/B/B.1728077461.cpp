//Date: 2024/10/04
//#pragma GCC optimize(2)
//#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
map <string, int> mp;
int n;
char op;

int main() {
	freopen("warehouse.in", "r", stdin);
	freopen("warehouse.out", "w", stdout);
	scanf("%d",&n);
	while (n--) {
		scanf("%s",&op);
		string x;
		if (op == 'A') {
			cin >> x;
			if (mp.count(x) != 0 and mp[x] != 0) {
				puts("Error");
			} else {
				mp[x]++;
				puts("Yes");
			}
		} else if (op == 'D') {

			cin >> x;
			if (mp.count(x) != 0 and mp[x] != 0) {
				mp[x] = 0;
				puts("Yes");
			} else {
				puts("Error");
			}

		} else if (op == 'Q') {
			cin >> x;
			if (mp.count(x) != 0 and mp[x] != 0) {
				puts("Yes");
			} else {
				puts("No");
			}
		}
	}
}
