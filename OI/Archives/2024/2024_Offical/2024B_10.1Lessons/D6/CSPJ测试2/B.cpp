#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int a[10010];
string s;
int n;

int main() {
	freopen("pwd.in", "r", stdin);
	freopen("pwd.out", "w", stdout);
	cin >> s >> n;
	int f = 1;
	for (int i = 0; i < s.size() and f != 4; i++) {
		if (s[i] == 'z') {
			if (f == 1 or f == 3)
				f++;
			continue;
		}
		if ((int)s[i] + n > 122) {
			n = (int)'z' - (int)s[i];
		}
		if (f == 2)
			f = 3;
		s[i] += n;
	}
	cout << s << endl;
}
