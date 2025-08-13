/*
 * > CPP Code Snippet <
 * > Powered by Microsoft Visual Studio Code <
 *
 * @Author     FrankWKD
 * @Date       2025-08-04
 * @Network    "https://oj.czos.cn/contest/problem?id=25410&pid=3"
 * @License    GNU General Public License 2.0
 * @Platform   [Frank]iMac Ubuntu Pro 24.04 LTS
 * @Name       T4.cpp
 * @Path       /media/frank/FrankW/_default/Mine/Working/code-spaces/OI/OJ/czos/CSP-S_Practise/Lesson1/T4.cpp
 * @Sol        --
 */

// #pragma GCC optimize(3)
#define _for(cc, ba, ab) for (int cc = (ba); cc <= (ab); cc++)
#define for_(cc, ba, ab) for (int cc = (ba); cc >= (ab); cc--)
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define i2 __int128
const int N = 1e5 + 10;
struct tree {
    int ai, bi, ci, ti, idx;
} a[N], b[N];
struct node {
    int to, nxt;
} edge[N * 2];
int pre[N], k = 0;
int fa[N];
int n, x, y;
bool f[N];
int plant[N];
int poi[N], len = 0;
bool cmp(tree n1, tree n2) {
    return n1.ti < n2.ti;
}
void add(int u, int v) {
    edge[++k] = {v, pre[u]};
    pre[u] = k;
}
void dfs(int x, int fath) {
    fa[x] = fath;
    for (int i = pre[x]; i; i = edge[i].nxt) {
        int to = edge[i].to;
        if (to != fath) {
            dfs(to, x);
        }
    }
}
i2 height(int x, i2 s, i2 e) {
    if (a[x].ci >= 0)
        return a[x].bi * (e - s + 1) + a[x].ci * (s + e) * (e - s + 1) / 2;
    i2 maxt = (1 - a[x].bi) / a[x].ci;
    if (maxt < s)
        return e - s + 1;
    if (maxt > e)
        return a[x].bi * (e - s + 1) + a[x].ci * (s + e) * (e - s + 1) / 2;
    return a[x].bi * (maxt - s + 1) + a[x].ci * (s + maxt) * (maxt - s + 1) / 2 + e - maxt;
}
int find(int x, int end_time) {
    int l = 1, r = n, mid;
    while (l <= r) {
        mid = l + r >> 1;
        if (height(x, mid, end_time) >= a[x].ai)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return l - 1;
}
bool check(int mid) {
    for (int i = 1; i <= n; i++) {
        if (height(i, 1, mid) < a[i].ai)
            return 0;
        b[i] = a[i];
        int ti = find(i, mid);
        b[i].ti = ti;
        plant[i] = ti;
        f[i] = 0;
    }
    sort(b + 1, b + n + 1, cmp);
    int day = 0, x, p;
    for (int i = 1; i <= n; i++) {
        if (f[b[i].idx] == 1)
            continue;
        len = 0;
        x = b[i].idx;
        poi[++len] = x;
        while (fa[x] != 0 and f[fa[x]] == 0) {
            x = fa[x];
            poi[++len] = x;
        }
        for (int j = len; j >= 1; j--) {
            p = poi[j];
            day++;
            f[p] = 1;
            if (plant[p] < day)
                return 0;
        }
    }
    return 1;
}

signed main() {
    // freopen("sample.in","r",stdin);
    // freopen("sample.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].ai >> a[i].bi >> a[i].ci;
        a[i].idx = i;
    }
    for (int i = 1; i <= n - 1; i++) {
        cin >> x >> y;
        add(x, y);
        add(y, x);
    }
    dfs(1, 0);
    int l = n, r = 1e9, mid;
    while (l <= r) {
        int mid = l + r >> 1;
        if (check(mid))
            r = mid - 1;
        else
            l = mid + 1;
    }
    cout << l;
    return 0;
}