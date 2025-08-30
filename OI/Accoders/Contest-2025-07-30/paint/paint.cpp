#include <bits/stdc++.h>
#define int long long
const int N = 2e31 - 1;
using namespace std;
int n;
int tao[5010];
int query(int l, int r) {
    if (l == r)
        return 1;
    int x = N;
    for (int i = l; i <= r; i++) x = min(x, tao[i]);
    int b = l;
    int sum = x;
    for (int i = l; i <= r; i++) tao[i] -= x;
    for (int i = l; i <= r; i++) {
        if (tao[i] && !tao[i - 1])
            b = i;
        if (tao[i] && (i == r || (i < r && !tao[i + 1])))
            sum += query(b, i);
    }
    return min(sum, r - l + 1);
}
signed main() {
    freopen("paint.in", "r", stdin);
    freopen("paint.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> tao[i];
    cout << query(1, n);
}