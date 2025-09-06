#include <bits/stdc++.h>
using namespace std;
queue <int> q;
int m;
string op;

int main() {
	cin >> m;
	while (m--) {
		cin >> op;
		if (op == "push") {
			int x;
			cin >> x;
			q.push(x);
		} else if (op == "pop") {
			q.pop();
		} else if (op == "query") {
			cout << q.back() << "\n";
		} else {
			if (q.empty()) {
				cout << "YES\n";
			} else {
				cout << "NO\n";
			}
		}
	}

	return 0;
}
