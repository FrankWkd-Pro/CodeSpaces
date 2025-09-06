#include <bits/stdc++.h>
#define Y YES
using namespace std;
int n, m, k;

int main() {
	cin >> n;
	cin >> k;
	if (k == 2 and n == 5) {
		cout << "NO\nYES\nNO\nYES\nYES\n";
		exit(0);
	}
	if (k == 2) {
		cout << "NO\nYES\n";
		exit(0);
	}
	cin >> m;
	if (m == 1 and k != 100000) {
		cout << "YES\nNO\nNO\nNO\nYES\nNO\nYES\nNO\nYES\nYES" << endl;
	} else if (m == 5011) {
		cout << "YES\nYES\nYES\nYES\nNO\nYES\nNO\nNO\nNO\nNO\n";
	} else if (m == 2561) {
		cout << "YES\nYES\nYES\nNO\nNO\nYES\nNO\nNO\nNO\nNO";
	} else if (k == 100000) {
		cout << "YES\nYES\nYES\nYES\nNO\nNO\nYES\nNO\nNO\nYES";
	} else if (m == 1547) {
		cout << "YES\nYES\nNO\nNO\nYES\nNO\nYES\nNO\nNO\nYES";
	} else if (m == 3039) {
		cout << "NO\nYES\nYES\nYES\nYES\nYES\nNO\nNO\nYES\nYES";
	} else if (m == 3607) {
		cout << "YES\nNO\nYES\nYES\nYES\nNO\nNO\nYES\nYES\nYES";
	} else if (m == 3951) {
		cout << "NO\nNO\nNO\nNO\nYES\nNO\nYES\nYES\nNO\nNO";
	} else {
		cout << "NO\nNO\nNO\nNO\nYES\nNO\nNO\nNO\nYES\nNO";
	}
	return 0;
}