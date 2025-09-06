#include<bits/stdc++.h>
using namespace std;
int main() {
	int len, n, t, w = 5;
	string s;
	scanf("%d%d%d", &n, &t, &len);
	cin >> s;
	s[len] = 'a' + t;
	while (w--) {
		for (int i = len - 1; i >= 0; i--) {
			if (s[i] + 1 < s[i + 1]) {
				s[i]++;
				for (int j = i + 1; j < len; j++) {
					s[j] = s[i] + j - i;
				}
				cout << s << endl;
				return 0;
			}
		}
	}
	return 0;
}
