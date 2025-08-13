/*
 * > CPP Code Snippet <
 * > Powered by Microsoft Visual Studio Code <
 *
 * @Author     FrankWKD
 * @Date       2025-08-06
 * @Network    "https://oj.czos.cn/contest/problem?id=25573&pid=5"
 * @License    GNU General Public License 2.0
 * @Platform   [Frank]iMac Ubuntu Pro 24.04 LTS
 * @Name       T6.cpp
 * @Path       /media/frank/FrankW1/_default/Mine/Working/code-spaces/OI/OJ/czos/CSP-S_Practise/Lesson2/T6.cpp
 * @Sol        --
 */

// #pragma GCC optimize(3)
#define _for(cc, ba, ab) for (register int cc = (ba); cc <= (ab); cc++)
#define for_(cc, ba, ab) for (register int cc = (ba); cc >= (ab); cc--)
#include <bits/stdc++.h>
using namespace std;
const int N = 4e7 + 10;
const int M = 1e5 + 10;
const int mod = (1 << 30);
#define i2 __int128
// MLE Warning
int n, type, x, y, z, m, a[N], b[N], p[M], l[M], r[M];
int pre[N];

long long sum[N];

int h, t, q[N];
long long get(long long x) {
    return 2 * sum[x] - sum[pre[x]];
}
void prlonglong(i2 ans) {
    string r = "";
    while (ans) {
        r = to_string((long long)(ans % 10)) + r;
        ans /= 10;
    }
    cout << r;
}
signed main() {
    // freopen("sample.in","r",stdin);
    // freopen("sample.out","w",stdout);
    // ios::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);
    cin >> n >> type;
    if (type == 1) {
        cin >> x >> y >> z >> b[1] >> b[2] >> m;
        _for(i, 1, m) cin >> p[i] >> l[i] >> r[i];
        _for(i, 3, n) b[i] = ((long long)b[i - 1] * x + (long long)b[i - 2] * y + z) % mod;
        _for(i, 1, m) _for(j, p[i - 1] + 1, p[i]) a[j] = ((long long)b[j] % (r[i] - l[i] + 1)) + l[i], sum[j] = sum[j - 1] + a[j];
    } else
        _for(i, 1, n) cin >> a[i], sum[i] = sum[i - 1] + a[i];
    h = 0, t = 0;
    _for(i, 1, n) {
        while (h <= t and sum[i] >= get(q[h])) h++;
        h--;
        pre[i] = q[h];
        while (h <= t and get(i) <= get(q[t])) t--;
        q[++t] = i;
    }
    i2 ans = 0;
    for (long long i = n; i; i = pre[i]) {
        i2 s = sum[i] - sum[pre[i]];
        ans += s * s;
    }
    prlonglong(ans);
    return 0;
}