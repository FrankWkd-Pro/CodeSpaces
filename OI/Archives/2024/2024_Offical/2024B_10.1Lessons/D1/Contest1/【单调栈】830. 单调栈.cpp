#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int x;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	stack<int> stk;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		while (stk.size() && stk.top() >= x)
			stk.pop();
		if (stk.size())
			cout << stk.top() << ' ';
		else
			cout << -1 << ' ';
		stk.push(x);
	}
	return 0;
}