#include<bits/stdc++.h>
using namespace std;
const int N = 1000010, P = 131;
typedef unsigned long long ull;
ull h[N], p[N];
char s[N];
int len;
int g[N];

void get_p(){
	
}
void gethash() {
	p[0] = 1;
	for (int i = 1; i <= len; i++) {
		h[i] = h[i - 1] * P + (s[i] - 'a' + 1);
		p[i] = p[i - 1] * P;
	}
}
ull get1(int l, int r) {
	return h[r] - h[l - 1] * p[r - l + 1];
}
int main() {
	while (scanf("%s", s + 1) and s[1] != '.') {
		len = strlen(s + 1);
		gethash();
		for (int i = 1; i <= len; i++) {
			if (len % i != 0) continue;
			if (get1(1, len - i/*!Important*/) == get1(i + 1, len)) {
				printf("%d\n", len / i);
				break;
			}
		}
	}
	return 0;
}
