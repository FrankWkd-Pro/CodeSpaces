/*
 * > CPP Code Snippet <
 * > Powered by Microsoft Visual Studio Code <
 *
 * @Author    FrankWKD (wangkedi01)
 * @Date      2025-10-02
 * @Network   "http://www.accoders.com/problem.php?cid=5135&pid=0"
 * @License   GNU General Public License 2.0
 * @Platform  [Frank]iMac Ubuntu Pro 24.04 LTS
 * @FileName  T4.cpp
 * @FilePath  /workspaces/CodeSpaces/OI/OJ/Accoders/Contest-2025-10-02/T4.cpp
 * @Solution  --
 */

// #pragma GCC optimize(3)
#define _for(aa, bb, cc) for (auto aa = bb; aa <= cc; aa++)
#define for_(aa, bb, cc) for (auto aa = bb; aa >= cc; aa--)
#include <bits/stdc++.h>
using namespace std;
char *p1, *p2, buf[100000];
#define nc() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1++)
int read() {
    int x = 0, f = 1;
    char ch = nc();
    while (ch < 48 || ch > 57) {
        if (ch == '-')
            f = -1;
        ch = nc();
    }
    while (ch >= 48 && ch <= 57)
        x = x * 10 + ch - 48, ch = nc();
    return x * f;
}

void write(int x) {
    if (x < 0)
        putchar('-'), x = -x;
    if (x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
    return;
}

string x[200];
int ax[200], as[200], h, n, m, s, w;
int main() {
    freopen("grass.in", "r", stdin);
    freopen("grass.out", "w", stdout);
    cin >> n >> m;
    _for(i, 0, n - 1) {
        cin >> x[i];
        int g = -1;
        for (int j = 0; j < m; ++j) {
            if (x[i][j] == 'W')
                g = j;
        }
        ax[i] = g;
        g = INT_MAX;
        for_(j, m - 1, 0) {
            if (x[i][j] == 'W')
                g = j;
        }
        as[i] = g;
        if (g != INT_MAX)
            w = i + 1;
    }
    if (w == 0) {
        cout << 0;
    } else {
        int i = 0;
        for (; i < w - 1; i++) {
            if (i % 2 == 0) {
                if (max(ax[i + 1], ax[i]) == -1)
                    continue;
                s = s + abs(max(ax[i + 1], ax[i]) - h);
                h = max(ax[i + 1], ax[i]);
            } else {
                if (min(as[i + 1], as[i]) == INT_MAX)
                    continue;
                s = s + abs(h - min(as[i + 1], as[i]));
                h = min(as[i + 1], as[i]);
            }
        }
        if (i % 2 == 0) {
            s += ax[i] - h;
        } else {
            s += h - as[i];
        }
        cout << w - 1 + s;
    }
}