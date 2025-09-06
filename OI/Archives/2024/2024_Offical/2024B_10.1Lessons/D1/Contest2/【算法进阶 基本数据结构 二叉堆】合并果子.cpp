#include <bits/stdc++.h>
using namespace std;

int main() {

	int n;
	cin >> n;
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		pq.push(x);
	}

	int res = 0;
	while (pq.size() > 1) {
		int one = pq.top();
		pq.pop();
		int two = pq.top();
		pq.pop();
		int sum = one + two;
		pq.push(sum);
		res += sum;
	}

	cout << res << endl;
}]