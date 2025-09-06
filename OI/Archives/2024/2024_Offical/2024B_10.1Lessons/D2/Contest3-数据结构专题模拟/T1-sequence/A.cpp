/*
By: FrankWKD
From: Self
Date: 2024/10/03
Note: -T1-fileIO
*/
#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;

int n, k, num[1000009], t;
deque <int> a;
long long mi, ma;

void check(int k) {
	a.clear();
	t = 0;
	for (int i = 0; i < n; i++) {
		while (!a.empty() && a.back() >= num[i])
			a.pop_back();
		a.push_back(num[i]);
		if (i - t >= k && num[t] == a.front()) {
			t++;
			a.pop_front();
		}
		if (i - t >= k && num[t] != a.front())
			t++;
		if (i >= k - 1)
			mi += a.front();
	}
	a.clear();
	t = 0;
	for (int i = 0; i < n; i++) {
		while (!a.empty() && a.back() <= num[i])
			a.pop_back();
		a.push_back(num[i]);
		if (i - t >= k && num[t] == a.front()) {
			t++;
			a.pop_front();
		}
		if (i - t >= k && num[t] != a.front())
			t++;
		if (i >= k - 1)
			ma += a.front();
	}
}


int main() {
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	scanf("%d", &n);
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
	}
	for (int i = 2; i <= n; i++) {
		mi = 0, ma = 0;
		check(i);
		ans += ma - mi;
	}
	printf("%d", ans);
}