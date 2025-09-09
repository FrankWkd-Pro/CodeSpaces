#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e4 + 10;
int v[N], c[N], t[N], n, m, k, s[N];
int f(int x) {
    return x & -x;
}
void fun(int x, int v) {
    for (x; x <= k; x += f(x)) {
        t[x] += v;
    }
}
long long q(int x) {
    long long s = 0;
    for (; x; x -= f(x)) {
        s += t[x];
    }
    return s;
}

signed main() {
    freopen("sum.in", "r", stdin);
    freopen("sum.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i] >> v[i];
        if (s[i] == 2)
            c[++m] = v[i];
    }
    sort(c + 1, c + m + 1);
    k = unique(c + 1, c + m + 1) - c - 1;
    for (int i = 1; i <= n; i++) {
        if (s[i] == 1) {
            for (int j = 1;; j++) {
                int p = lower_bound(c + 1, c + k + 1, v[i] + (1ll << j)) - c;
                if (p > k)
                    break;
                fun(p, 1);
            }
        } else {
            int p = lower_bound(c + 1, c + k + 1, v[i]) - c;
            cout << q(p) << "\n";
        }
    }
    return 0;
}
