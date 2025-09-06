//#pragma GCC optimize(2)
//#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
string A, B;
const int N = 6;
int n;
string a[N], b[N];
int extend(queue<string>& q, unordered_map<string, int>& da,
           unordered_map<string, int>& db, string a[N], string b[N]) {
	string t = q.front();
	q.pop();
	for (int i = 0; i < t.size(); i++) {
		for (int j = 0; j < n; j++) {
			if (t.substr(i, a[j].size()) == a[j]) {
				string state = t.substr(0, i) + b[j] + t.substr(i + a[j].size());
				if (db.count(state)) {
					return da[t] + 1 + db[state]; //成功
				}
				if (da.count(state)) continue;
				da[state] = da[t] + 1;
				q.push(state);
			}
		}
	}
	return 11;
}

int bfs() {
	queue<string> qa, qb;
	unordered_map<string, int> da, db;
	qa.push(A), qb.push(B);
	da[A] = 0;
	db[B] = 0;
	while (qa.size() and qb.size()) {
		int t;
		if (qa.size() <= qb.size()) t = extend(qa, da, db, a, b);
		else t = extend(qb, db, da, b, a);
		if (t <= 10) return t;
	}
	return 11;
}

int main() {
	cin >> A >> B;
	while (cin >> a[n] >> b[n]) n++;
	int t = bfs();
	if (t == 11) puts("NO ANSWER!");
	else cout << t << endl;
	return 0;
}
