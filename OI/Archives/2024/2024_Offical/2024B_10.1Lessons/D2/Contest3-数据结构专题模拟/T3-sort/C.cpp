
/*
By: FrankWKD
From: Self
Date: 2024/10/03
Note: -T3-fileIO
*/
//#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
int a[1001000], tmp[1000100], n;
long long ans;

void m(int a[], int l, int r) {
	if (l >= r)
		return;
	int mid = l + r >> 1;
	m(a, l, mid);
	m(a, mid + 1, r);
	int i = l, j = mid + 1, k = 0;
	while (i <= mid and j <= r) {
		if (a[i] <= a[j])
			tmp[k++] = a[i++];
		else
			tmp[k++] = a[j++], ans += mid - i + 1;
	}
	while (i <= mid)
		tmp[k++] = a[i++];
	while (j <= r)
		tmp[k++] = a[j++];
	i = l;
	for (int j = 0; j < k; j++) {
		a[i++] = tmp[j];
	}
}

int main() {
	freopen("sort.in", "r", stdin);
	freopen("sort.out", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	m(a, 0, n - 1);
	printf("%lld", ans);
	return 0;
}