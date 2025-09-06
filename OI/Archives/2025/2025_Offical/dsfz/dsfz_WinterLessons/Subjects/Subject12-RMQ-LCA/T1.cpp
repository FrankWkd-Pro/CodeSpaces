#include <bits/stdc++.h>
using namespace std;
inline int read() {
    char ch = getchar();
    int res = 0, f = 1;
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') res = res * 10 + ch - '0', ch = getchar();
    return res * f;
}
inline void write(int zx) {
    if (zx < 0)
        zx = -zx, putchar('-');
    if (zx < 10)
        putchar(zx + '0');
    else {
        write(zx / 10);
        putchar(zx % 10 + '0');
    }
}
int n, m, a[100010], f[100010][20];
void ST() {
    for (int i = 1; i <= n; i++) f[i][0] = a[i];
    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 1; i + (1 << j) - 1 <= n; i++) {
            f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
        }
    }
}
int RMQ(int l, int r) {
    int k = 0;
    while ((1 << (k + 1)) <= r - l + 1) k++;
    return max(f[l][k], f[r - (1 << k) + 1][k]);
}
int main() {
    cin >> n;
    cin >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    ST();
    for (int i = 1; i <= m; i++) {
        int l = read(), r = read();
        cout << RMQ(l, r) << "\n";
    }
    return 0;
}