#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
const int P = 131;
set<unsigned long long> st;
typedef unsigned long long ull;
ull h[N], p[N];
char s[N];
void gethash() {
	int len = strlen(s + 1);
	p[0] = 1;
	for (int i = 1; i <= len; i++) {
		p[i] = p[i - 1] * P;
		h[i] = h[i - 1] * P + (s[i] - 'A' + 1);
	}
}
ull get(int l, int r) {
	return h[r] - h[l - 1] * p[r - l + 1];
}
int main() {
	int len;
	scanf("%d%s", &len, s + 1);
	gethash();
	int mid = len / 2 + 1;
	ull l, r;
	char res = ' ';
	for (int i = 1; i <= len; i++) {
		if (i == 1) {
			l = get(2, mid);
			r = get(mid + 1, len);
		} else if (i == len) {
			l = get(1, mid - 1);
			r = get(mid, len - 1);
		} else if (i < mid) {
			l = get(1, i - 1) * p[mid - i] + get(i + 1, mid);
			r = get(mid + 1, len);
		} else if (i > mid) {
			l = get(1, mid - 1);
			r = get(mid, i - 1) * p[len - i] + get(i + 1, len);
		} else if (i == mid) {
			l = get(1, mid - 1);
			r = get(mid + 1, len);
		}
		if (l == r) {
			st.insert(l);
			if (st.size() > 1) {
				puts("NOT UNIQUE");
				return 0;
			}
			if (i <= mid)
				res = 'R';
			else
				res = 'L';
		}
	}
	if (st.size() == 0)
		puts("NOT POSSIBLE");
	else {
		s[mid] = '\0';  // 输出到这里的时候就停止输出
		if (res == 'L')
			printf("%s", s + 1);
		else
			printf("%s", s + mid + 1);
	}
}
