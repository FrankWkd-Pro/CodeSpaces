#include <bits/stdc++.h>
using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
string ed = "12345678x";

unordered_map<string, int> d;

int bfs(string s) {
	queue<string> q;
	q.push(s);
	d[s] = 0;

	while (q.size()) {
		auto u = q.front();
		q.pop();

		if (u == ed)
			return d[u];
		int k = u.find('x');
		int x = k / 3, y = k % 3;





		for (int i = 0; i < 4; i++) {
			int tx = x + dx[i], ty = y + dy[i];
			if (tx < 0 || tx > 2 || ty < 0 || ty > 2)
				continue;

			string c = u;
			swap(c[k], c[tx * 3 + ty]);
			if (!d.count(c)) {
				d[c] = d[u] + 1;
				q.push(c);
			}
		}
	}
	return -1;
}

int main() {
	string s;
	char c;
	for (int i = 1; i <= 9; i++) {
		cin >> c;
		s += c;
	}
	cout << bfs(s) << endl;
	return 0;
}
