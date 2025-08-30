#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, p;
        string s;
        cin >> n >> p >> s;
        p--;  // 转为0-索引

        int lw = 0, rw = 0;
        for (int i = 0; i < p; i++) {
            if (s[i] == '#')
                lw++;
        }
        for (int i = p + 1; i < n; i++) {
            if (s[i] == '#')
                rw++;
        }

        if (lw == 0 || rw == 0) {
            cout << 1 << "\n";
        } else {
            cout << min(lw + rw + min(lw, rw), max(lw, rw) + 1) << "\n";
        }
    }
    return 0;
}