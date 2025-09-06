#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	while (n--) {
		int k;
		cin >> k;
		for (int i = 1; i <= k; i++) {
			if (k % i == 0)
				cout << i << " ";
		}
		cout << "\n";
	}
}