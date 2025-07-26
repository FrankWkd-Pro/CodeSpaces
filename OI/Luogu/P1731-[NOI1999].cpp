#include <bits/stdc++.h>
using namespace std;
const int Inf = 1e9;
int minv, mins, n, m;
int ans = Inf;
void dfs(int u, int r, int h, int v, int s) {
    if (u == 0) {
        if (s < ans and v == n)
            ans = s;
        return;
    }
    if (v + minv[u] > n)
        return;
    if (s + mins[u] >= ans)
        return;
    if (s + 2 * (n - v) / r >= ans)
        return;
    for (int i = min(r - 1, (int)sqrt(n - v)); i >= u; i--) {
        for (int j = min(h - 1, (n - v) / (i * i)); j >= u; j--) {
            dfs(u - 1, i, j, v + i * i * j, s + 2 * i * j + (u == m ? i * i : 0));
        }
    }
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        mins[i] = mins[i - 1] + 2 * i * i;
        minv[i] = minv[i - 1] + i * i * i;
    }
    dfs(m, Inf, Inf, 0, 0);  // 从下向上遍历

    if (ans == Inf)
        puts("0");
    else
        cout << ans << endl;
}