#include<bits/stdc++.h>
using namespace std;
const int N = 1010, MOD = 1e9+7;
const int P = 131;
int p1, p2, p3;
string s;
int main() {
	cin >> p1 >> p2 >> p3;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
//		cout<<s[i]<<endl;
		if (s[i] == '-') {
			if (s[i - 1] >= 'a' and s[i - 1] <= 'z') {
				if (s[i + 1] < 'a' or s[i + 1] > 'z' or s[i + 1] == s[i - 1]) {
					putchar('-');
					continue;
				}
				if (s[i + 1] == s[i - 1] + 1) continue;
				if (p3 == 2) {
					if (p1 == 2) {
						for (int k = s[i + 1] - 1; k > s[i - 1]; k--) for (int j = 1; j <= p2;
							    j++) putchar(k - 'a' + 'A');
					} else if (p1 == 3) {
						for (int k = s[i + 1] - 1; k > s[i - 1]; k--) for (int j = 1; j <= p2;
							    j++) putchar('*');
					} else {
						for (int k = s[i + 1] - 1; k > s[i - 1]; k--) for (int j = 1; j <= p2;
							    j++) putchar((char)k);
					}
				} else {
					if (p1 == 2) {
						for (int k = s[i - 1] + 1; k < s[i + 1]; k++) for (int j = 1; j <= p2;
							    j++) putchar(k - 'a' + 'A');
					} else if (p1 == 3) {
						for (int k = s[i - 1] + 1; k < s[i + 1]; k++) for (int j = 1; j <= p2;
							    j++) putchar('*');
					} else {
						for (int k = s[i - 1] + 1; k < s[i + 1]; k++) for (int j = 1; j <= p2;
							    j++) putchar((char)k);
					}
				}
			} else if (s[i - 1] >= '0' and s[i - 1] <= '9') {
				if (s[i + 1] < '0' or s[i + 1] > '9' or s[i + 1] == s[i - 1]) {
					putchar('-');
					continue;
				}
				if (s[i + 1] == s[i - 1] + 1) continue;
				if (p3 == 2) {
					if (p1 == 3) {
						for (int k = s[i + 1] - 1; k > s[i - 1]; k--) for (int j = 1; j <= p2;
							    j++) putchar('*');
					} else {
						for (int k = s[i + 1] - 1; k > s[i - 1]; k--) for (int j = 1; j <= p2;
							    j++) putchar(k);
					}
				} else {
					if (p1 == 3) {
						for (int k = s[i - 1] + 1; k < s[i + 1]; k++) for (int j = 1; j <= p2;
							    j++) putchar('*');
					} else {
						for (int k = s[i - 1] + 1; k < s[i + 1]; k++) for (int j = 1; j <= p2;
							    j++) putchar(k);
					}
				}
			} else if (s[i - 1] >= 'A' and s[i - 1] <= 'Z') {

				if (s[i + 1] < 'A' or s[i + 1] > 'Z' or s[i + 1] == s[i - 1]) {
					putchar('-');
					continue;
				}
				if (s[i + 1] == s[i - 1] + 1) continue;
				if (p3 == 2) {
					if (p1 == 2) {
						for (int k = s[i + 1] - 1; k > s[i - 1]; k--) for (int j = 1; j <= p2;
							    j++) putchar(k);
					} else if (p1 == 3) {
						for (int k = s[i + 1] - 1; k > s[i - 1]; k--) for (int j = 1; j <= p2;
							    j++) putchar('*');
					} else {
						for (int k = s[i + 1] - 1; k > s[i - 1]; k--) for (int j = 1; j <= p2;
							    j++) putchar(k - 'A' + 'a');
					}
				} else {
					if (p1 == 2) {
						for (int k = s[i - 1] + 1; k < s[i + 1]; k++) for (int j = 1; j <= p2;
							    j++) putchar(k);
					} else if (p1 == 3) {
						for (int k = s[i - 1] + 1; k < s[i + 1]; k++) for (int j = 1; j <= p2;
							    j++) putchar('*');
					} else {
						for (int k = s[i - 1] + 1; k < s[i + 1]; k++) for (int j = 1; j <= p2;
							    j++) putchar(k - 'A' + 'a');
					}
				}
			} else putchar(s[i]);
		} else putchar(s[i]);

	}
	return 0;
}
