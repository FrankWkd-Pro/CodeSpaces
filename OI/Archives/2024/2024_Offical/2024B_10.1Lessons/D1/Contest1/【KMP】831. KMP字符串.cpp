#pragma GCC optimize(5)
#include <bits/stdc++.h>
using namespace std;
string a, b;
int n;

int main() {
	cin >> n >> a >> n >> b;
	int v =  0;
	int ls = b.find(a, v);
	while (ls != -1) {
		printf("%d ", ls);
		v = ls + 1;
		ls = b.find(a, v);
	}

	return 0;
}
