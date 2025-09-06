//Date: 2024/01/04
//#pragma GCC optimize(2)
//#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

ull n;
string s;

struct node {
	bool is_light = false;
} a[100];
ull top = 1;
ull b[10101001];

inline void calc() {
	ull nums[1001], t = 1;
	memset(nums, 0, sizeof(nums));
	for (ull i = 0; i < s.size(); i++) {
		if (a[i].is_light == false) {
			nums[t] = nums[t] * 10 + (s[i] - '0');
		} else {
			nums[++t] = s[i] - '0';
		}
	}
	for (ull i = 1; i <= t; i++) {
		b[top] += nums[i];
	}
//	cout << b[top] << endl;
	top++;

}

inline void fun(ull i) {
	if (i > s.size()) {
		calc();
		return ;
	} else {
		if (s[i] != '0') {
			a[i].is_light = true;
			fun(i + 1);
		}
		a[i].is_light = false;
		fun(i + 1);
	}
}

int main() {
	freopen("sum.in", "r", stdin);
	freopen("sum.out", "w", stdout);
	cin >> s;
	fun(1);
	ull mi = 1e19, ma = 0, tot = 0;
	for (ull i = 1; i < top; i += 2) {
//		cout << b[i] << " ";
		mi = min(mi, b[i]);
		ma = max(ma, b[i]);
		tot += b[i];
	}
	cout << top / 2 << endl;
	cout << ma << " " << mi << " " << tot << endl;
}
