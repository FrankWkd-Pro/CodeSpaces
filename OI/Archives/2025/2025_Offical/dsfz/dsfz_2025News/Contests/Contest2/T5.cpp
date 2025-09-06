#include<bits/stdc++.h>
using namespace std;
const int N = 500010, MOD = 1e9+7;
const int P = 131;
#define ull unsigned long long
ull h[N], p[N], h2[N];
long long n, ans;
char a[N], a2[20] = {'W', '0', '1', '1', '0'};
void gethash() {
	p[0] = 1;
	for (int i = 1; i <= n; i++) {
		h[i] = h[i - 1] * P + (a[i] - '0' + 1);
		p[i] = p[i - 1] * P;
	}
	for (int i = 1; i <= 4; i++) {
		h2[i] = h2[i - 1] * P + (a2[i] - '0' + 1);
	}
}
ull get1(int l, int r) {
	return h[r] - h[l - 1] * p[r - l + 1];
}
ull get2(int l, int r) {
	return h2[r] - h2[l - 1] * p[r - l + 1];
}
void check(int l, int r) {
	ans++;
//	cout<<l<<" "<<r<<endl;
	if (l == 1 or r == n) return ;
//	避雷0x0 & 1x1
//	if (a[l - 1] == a[r + 1]) check(l - 1, r + 1); //0x0 & 1x1
	if (a[l - 1] == a[l] and a[r + 1] == a[r]) check(l - 1, r + 1); //1100 & 0011
	if (a[l - 1] == a[r] and a[r + 1] == a[l]) check(l - 1, r + 1); //0101 & 1010
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	gethash();
	ull tmp1 = get2(1, 2); //01
	ull tmp2 = get2(3, 4); //10
	for (int i = 1; i + 1 <= n; i++) {
		ull noww = get1(i, i + 1);
		if (noww == tmp1) check(i, i + 1);
		if (noww == tmp2) check(i, i + 1);
	}
	cout << ans << endl;
	return 0;
}


/*
01的扩展串
只有一种可能就是找模式串！
001011直接绝杀
全部串都是奇数好吧
*/
