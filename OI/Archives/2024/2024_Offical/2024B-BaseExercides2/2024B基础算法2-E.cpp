#include <bits/stdc++.h>
using namespace std;
const int M = 100010;

int n, a[M], nums[M], b[M] ;

int guibingpaixu(int s[], int a, int b) {
	if (b <= a)
		return 0;
	/*---------------------------------------*/
	int m = a + b >> 1;
	int r = guibingpaixu(s, a, m) + guibingpaixu(s, m + 1, b);
	int i = a, j = m + 1, k;
	int t[M];
	for (k = a; k <= b; k++) {
		if (j > b || (i <= m && s[i] <= s[j])) {
			t[k] = s[i++];
			r += j - m - 1;
		} else
			t[k] = s[j++];
	}
	memcpy(s + a, t + a, sizeof(*s) * (b - a + 1));
	return r;
}

int main() {
	int i, j, k;
	cin >> n;
	for (i = 0; i < n; i++) {
		scanf( "%d%d", &j, &k);
		nums[k] = i;
		b[i] = j;
	}
	for (i = 0; i < n; i++)
		a[i] = nums[b[i]];
	k = guibingpaixu(a, 0, n - 1);
	cout << k;
	return 0;
}



/*PATH(模版)先排序，再找逆序对*/
/*
int guibingpaixu(int s[], int a, int b) {
	if (b <= a)
		return 0;
		---------------------------------------*
	int m = a + b >> 1;
	int r = guibingpaixu(s, a, m) + guibingpaixu(s, m + 1, b);
	int i = a, j = m + 1, k;
	int t[M];
	for (k = a; k <= b; k++) {
		if (j > b || (i <= m && s[i] <= s[j])) {
			t[k] = s[i++];
			r += j - m - 1;
		} else
			t[k] = s[j++];
	}
	memcpy(s + a, t + a, sizeof(*s) * (b - a + 1));
	return r;
}*/