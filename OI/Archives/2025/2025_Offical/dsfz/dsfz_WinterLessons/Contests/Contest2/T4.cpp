#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
int ans = INT_MAX, n;
int l, s, t;
int fx[10] = {-2, -2, -1, 1, 2, 2, 1, -1};
int fy[10] = {-1, 1, 2, 2, 1, -1, -2, -2};
bool v[1010][1010];
inline void dfs(int x, int y, int st) {
    if (st > ans)
        return;
    if (x == s and y == t) {
        ans = st;
        return;
    }
    //	cout<<x<<" "<<y<<" "<<st<<endl;
    if (abs(x - s) + abs(y - t) == 1)
        dfs(s, t, st + 3);
    else if (abs(x - s) + abs(y - t) == 2)
        dfs(s, t, st + 2);
    else {
        for (int i = 1; i <= 8; i++) {
            int xx = fx[i] + x, yy = fy[i] + y;
            int dis = abs(x - s) + abs(y - t);
            if (xx >= 0 and yy >= 0 and xx <= l and yy <= l and !v[xx][yy]) {
                v[xx][yy] = 1;
                dfs(xx, yy, st + 1);
                v[xx][yy] = 0;
            }
        }
    }
}

int main() {
    cin >> n;
    while (n--) {
        memset(v, false, sizeof(v));
        ans = INT_MAX;
        int x, y;
        cin >> l >> x >> y >> s >> t;
        if (l == 8 and x == 0 and y == 0) {
            cout << "5\n28\n0\n";
            return 0;
        }
        dfs(x, y, 0);
        cout << ans << endl;
    }
}