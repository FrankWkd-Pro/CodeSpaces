/*
 * > CPP Code Snippet <
 * > Powered by Microsoft Visual Studio Code <
 *
 * @Author     FrankWKD
 * @Date       2025-08-11
 * @Network    "https://codeforces.com/contest/2131/problem/E"
 * @License    GNU General Public License 2.0
 * @Platform   [Frank]iMac Ubuntu Pro 24.04 LTS
 * @Name       T4.cpp
 * @Path       /media/frank/FrankW1/_default/Mine/Working/code-spaces/OI/OJ/Codeforces/Round.1042.Div3/T4.cpp
 * @Sol        --
 */

// #pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    if (a.back() != b.back()) {
        cout << "NO\n";
        return;
    }

    int xor_a = 0, xor_b = 0;
    for (int num : a) xor_a ^= num;
    for (int num : b) xor_b ^= num;
    if (xor_a != xor_b) {
        cout << "NO\n";
        return;
    }
    vector<int> target = b;
    vector<int> current = a;

    for (int i = n - 2; i >= 0; --i) {
        if (current[i] != target[i]) {
            int new_val = current[i] ^ current[i + 1];
            if (new_val != target[i]) {
                cout << "NO\n";
                return;
            }
            current[i] = new_val;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (current[i] != target[i]) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}