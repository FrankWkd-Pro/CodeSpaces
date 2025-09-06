#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
const int N = 1e5 + 7;
int n, m;
int h[N], e[N], ne[N], cur;
int d[N];
void add(int a, int b) {
	e[cur] = b;
	ne[cur] = h[a];
	h[a] = cur ++ ;
}
int main() {
	cin >> n >> m;
	memset(h, -1, sizeof(h));
	for (int i = 0; i < m; i ++ ) {
		int a, b;
		cin >> a >> b;
		add(a, b);
	}
	memset(d, -1, sizeof(d));
	queue <int> q;
	d[1] = 0;
	q.push(1);
	while (q.size()) {
		int t = q.front();
		q.pop();
		for (int i = h[t]; i != -1; i = ne[i]) {
			int j = e[i];
			if (d[j] == -1) {
				d[j] = d[t] + 1;
				q.push(j);
			}
		}
	}
	cout << d[n] << endl;
	return 0;
}
