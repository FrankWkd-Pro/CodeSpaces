//Date:
//#pragma GCC optimize(2)
//#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
ull oper;//MAX_MAXX:1.5e19(warning)
string s;
vector<string> v;
ull ax[101010];
ull ttop = 1;
int n;
map<string, ull> mp;

inline void calc(string s) {
	n++;
	int top = 1;
//	cout << "s " << s << endl;
	ull a[20];
	memset(a, 0, sizeof(a));
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '+') {
			top++;
			continue;
		}
		a[top] *= 10;
		a[top] += s[i] - '0';
//		cout << a[top] << " ";
	}
//	cout << endl;
	ttop++;
	for (int i = 1; i <= 19; i++) {
		ax[ttop] += a[i];
	}
//	cout << ax[ttop] << endl;
}

inline void op(ull vk, string orgin) {
	if (orgin.size() - vk <= 1) {
		if (mp.count(orgin) == 0) {

			mp[orgin]++;
			calc(orgin);
		}
		return ;
	} else {
		for (int i = vk; i < orgin.size() - 1; i++) {
			if (orgin[i + 1] != '0') {
				orgin.insert(i + 1, "+");

//				cout << i << " " << orgin << endl;

				op(i + 2, orgin);

				orgin.erase(i + 1, 1);
			}
			op(i + 1, orgin);
		}
	}
}



int main() {
	//freopen("sum.in","r",stdin);
	//freopen("sum.out","w",stdout);
	cin >> s;
	op(0, s);
	sort(ax + 1, ax + 1 + n);
	ull ma = 0, mi = 10000000000000000000, tot = 0;
	for (int i = 2; i <= n + 1; i++) {
//		cout << ax[i] << endl;
		if (ax[i] == ax[i + 1])
			i++;
		tot += ax[i];
		mi = min(ax[i], mi);
		ma = max(ma, ax[i]);
	}
	cout << n << endl;
	cout << ma << " " << mi << " " << tot << endl;
}
