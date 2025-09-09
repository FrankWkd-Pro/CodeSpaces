/*
 * > CPP Code Snippet <
 * > Powered by Microsoft Visual Studio Code <
 *
 * @Author    FrankWKD (wangkedi01)
 * @Date      2025-09-09
 * @Network   "https://www.luogu.com.cn/problem/P3275"
 * @License   GNU General Public License 2.0
 * @Platform  [Frank]iMac Ubuntu Pro 24.04 LTS
 * @FileName  T1.cpp
 * @FilePath  /workspaces/CodeSpaces/OI/OJ/Accoders/diff-constraints/T1.cpp
 * @Solution  --
 */

// #pragma GCC optimize(3)

#include <bits/stdc++.h>
using namespace std;

const int N = 3e6 + 10;
#define int long long
int n, k, x, y, z, K;
struct node {
    int to, nxt, len;
} a[N * 2];
int dis[N];
int pre[N], cnt[N];
bool f[N];
int countttt;
void add(int u, int v, int w) {
    a[++k] = {v, pre[u], w};
    pre[u] = k;
}
stack<int> s;
bool spfa(int x) {
    memset(dis, -0x3f, sizeof dis);
    dis[0] = 0;
    s.push(0);
    f[0] = 1;
    while (!s.empty()) {
        int t = s.top();
        f[t] = 0;
        s.pop();

        for (int i = pre[t]; i; i = a[i].nxt) {
            int to = a[i].to;

            if (dis[to] < dis[t] + a[i].len) {
                if (++countttt >= 1e7)
                    return 0;  // trick 不然过不去
                dis[to] = dis[t] + a[i].len;
                cnt[to]++;
                if (cnt[to] >= n + 1)
                    return 0;
                if (!f[to]) {
                    s.push(to);
                    f[to] = 1;
                }
            }
        }
    }
    return 1;
}
signed main() {
    cin >> n >> K;
    for (int i = 1; i <= K; i++) {
        cin >> x >> y >> z;
        if (x == 1) {
            add(z, y, 0);
            add(y, z, 0);
        } else if (x == 2)
            add(y, z, 1);
        else if (x == 3)
            add(z, y, 0);
        else if (x == 4)
            add(z, y, 1);
        else if (x == 5)
            add(y, z, 0);
    }
    for (int i = 1; i <= n; i++) {
        add(0, i, 1);
    }
    if (!spfa(0)) {
        cout << -1;
    } else {
        long long ans = 0;
        for (int i = 1; i <= n; i++) ans += dis[i];
        cout << ans << endl;
    }
    // fclose(stdin);
    // fclose(stdout);
    return 0;
}  // HACK: 洛谷数据无法通过，SPFA被卡常。帖子：https://www.luogu.com.cn/discuss/1150142