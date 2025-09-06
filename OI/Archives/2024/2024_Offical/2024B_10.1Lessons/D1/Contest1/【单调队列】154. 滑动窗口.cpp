#include <bits/stdc++.h>
using namespace std;
const int N = 1010100;
int n, k, q[N], a[N];
int hh, tt;

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    hh = 0, tt = -1;
    for (int i = 0; i < n; ++i) {
        if (hh <= tt && q[hh] < i - k + 1)
            hh++;
        while (hh <= tt && a[q[tt]] >= a[i])
            tt--;
        q[++tt] = i;
        if (i >= k - 1)
            printf("%d ", a[q[hh]]);
    }
    printf("\n");
    hh = 0, tt = -1;
    for (int i = 0; i < n; ++i) {
        if (hh <= tt && q[hh] < i - k + 1)
            hh++;
        while (hh <= tt && a[q[tt]] <= a[i])
            tt--;
        q[++tt] = i;
        if (i >= k - 1)
            printf("%d ", a[q[hh]]);
    }

    return 0;
}