#include <bits/stdc++.h>
using namespace std;
const int N = 1010110;

int n, k;
int l[N], r[N];
long long d[N];

void del_node(int x) {
	r[l[x]] = r[x];
	l[r[x]] = l[x];
}

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> d[i];
	for (int i = n - 1; i; i--)
		d[i] -= d[i - 1];

	set<pair<long long, int> > s;
	d[0] = d[n] = 1e15;
	for (int i = 0; i <= n; i++) {
		s.insert({d[i], i});
		l[i] = i - 1;
		r[i] = i + 1;
	}

	long long ans = 0;
	while (k--) {
		auto x = s.begin();
		long long v = x->first;
		int p = x->second;
		int  le = l[p], ri = r[p];

		ans += v;

		s.erase(x);
		s.erase({d[le], le});
		s.erase({d[ri], ri});
		del_node(le);
		del_node(ri);

		d[p] = d[le] + d[ri] - d[p];
		s.insert({d[p], p});
	}
	cout << ans << endl;
	return 0;
}