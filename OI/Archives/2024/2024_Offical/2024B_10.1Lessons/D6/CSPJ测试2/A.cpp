#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int lib[20] = {-1, 1, 3, 6, 10, 15, 21, 28, 36, 45};

//10 = |9|*1 + |1|
//25 = |9|*2 + |2+5|
unsigned long long ans;
inline void fun(unsigned long long n) {
	unsigned long long k = 0;
	ans += n / 10 * lib[9];
	while (n > 0) {
		k += n % 10;
		n /= 10;
	}
	if (k >= 10) {
		fun(k);
	} else {
		ans += lib[k];
		return ;
	}
	return ;
}

int main() {
	freopen("abc.in", "r", stdin);
	freopen("abc.out", "w", stdout);
	unsigned long long n;
	cin >> n;
	fun(n);
	cout << ans;
}
