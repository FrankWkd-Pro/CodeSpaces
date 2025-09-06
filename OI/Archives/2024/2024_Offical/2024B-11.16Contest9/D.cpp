#include <bits/stdc++.h>
using namespace std;
int x, y, z, ans;
string k, loc = "";
void fun (int a, int b, int c, string loc) {
//	cout << loc << endl;
	if (loc.size() == x + y + z) {
		ans++;
		return ;
	}
	if (loc[loc.size() - 1] == '1') {
		if (b > 0) fun (a, b - 1, c, loc + "2");
		if (c > 0) fun (a, b, c - 1, loc + "3");
	}
	if (loc[loc.size() - 1] == '2') {
		if (a > 0) fun (a - 1, b, c, loc + "1");
		if (c > 0) fun (a, b, c - 1, loc + "3");
	}
	if (loc[loc.size() - 1] == '3') {
		if (a > 0) fun (a - 1, b, c, loc + "1");
		if (b > 0) fun (a, b - 1, c, loc + "2");
	}

}


int main() {
	int k;
	cin >> k;
	int a, b, c;
	cin >> x >> y >> z;
	fun (x
	     - 1, y, z, "1");
	fun (x, y - 1, z, "2");
	fun (x, y, z - 1, "3");
	cout << ans;
}
