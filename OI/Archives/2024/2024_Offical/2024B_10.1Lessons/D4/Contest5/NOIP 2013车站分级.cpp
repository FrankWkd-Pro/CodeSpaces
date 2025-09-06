#include <bits/stdc++.h>
using namespace std;
int n, m, ans, st[1010], s, tuopu[1010][1010], de[1010], tt[1010], top;
bool is[1010], bo[1010];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		memset(is, 0, sizeof(is));
		scanf("%d", &s);
		for (int j = 1; j <= s; j++)
			scanf("%d", &st[j]), is[st[j]] = true;
		for (int j = st[1]; j <= st[s]; j++)
			if (!is[j])
				for (int k = 1; k <= s; k++)
					if (!tuopu[j][st[k]])
						tuopu[j][st[k]] = 1, de[st[k]]++;
	}

	do {
		top = 0;
		for (int i = 1; i <= n; i++)
			if (de[i] == 0 && !bo[i]) {
				tt[++top] = i, bo[i] = true;
			}
		for (int i = 1; i <= top; i++)
			for (int j = 1; j <= n; j++)
				if (tuopu[tt[i]][j])
					tuopu[tt[i]][j] = 0, de[j]--;
		ans++;
	} while (top);
	printf("%d", ans - 1);
	return 0;
}