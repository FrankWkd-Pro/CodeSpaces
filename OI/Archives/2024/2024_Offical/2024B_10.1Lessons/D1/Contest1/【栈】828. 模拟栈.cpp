#include <bits/stdc++.h>
using namespace std;
stack <int> s;

int main() {
	int m;
	cin >> m;
	while (m--) {
		string op;
		cin >> op;
		if (op == "push") {
			int x;
			cin >> x;
			s.push(x);
		} else if (op == "pop") {
			s.pop();
		} else if (op == "empty") {
			if (s.empty()) {
				cout << "YES\n";
			} else
				cout << "NO\n";
		} else {
			cout << s.top() << endl;
		}
	}

	return 0;
}
