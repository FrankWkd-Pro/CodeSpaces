#include <bits/stdc++.h>
using namespace std;
int f[50005];
int n, ans, top;

struct stack {
	long long h;
	int v;
} Stack[50005];

struct Cow {
	long long h;
	int v;
} cow[50005];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d%d", &cow[i].h, &cow[i].v);
	for (int i = 1; i <= n; ++i) {
		while (Stack[top].h < cow[i].h && top) {
			f[i] += Stack[top].v;
			top--;
		}
		Stack[++top].h = cow[i].h;
		Stack[top].v = cow[i].v;
	}
	top = 0;
	for (int i = n; i >= 1; --i) {
		while (Stack[top].h < cow[i].h && top) {
			f[i] += Stack[top].v;
			top--;
		}
		Stack[++top].h = cow[i].h;
		Stack[top].v = cow[i].v;
	}
	for (int i = 1; i <= n; ++i)
		ans = max(ans, f[i]);
	printf("%d", ans);
}
