#include <bits/stdc++.h>

int main() {
	int n, a, b;
	scanf("%d", &n);
	while (n--) {
		scanf("%d%d", &a, &b);
		printf("%d\n", std::__gcd(a, b));
	}
}