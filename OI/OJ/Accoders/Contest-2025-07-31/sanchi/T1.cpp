#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> to_thr(ll n) {
    vector<int> v;
    if (n == 0)
        v.push_back(0);
    while (n) {
        v.push_back(n % 3);
        n /= 3;
    }
    return v;
}

ll dfs(int pos, bool tight, bool lead, vector<int>& digits, vector<ll>& dp) {
    if (pos < 0)
        return lead ? 0 : 1;
    if (!tight && !lead && dp[pos] != -1)
        return dp[pos];
    ll res = 0;
    int up = tight ? digits[pos] : 1;
    for (int d = 0; d <= up; ++d) {
        if (d == 2)
            continue;
        bool nlead = lead && (d == 0);
        res += dfs(pos - 1, tight && (d == up), nlead, digits, dp);
    }
    if (!tight && !lead)
        dp[pos] = res;
    return res;
}

ll count_chaos(ll n) {
    vector<int> digits = to_thr(n);
    vector<ll> dp(digits.size(), -1);
    return dfs(digits.size() - 1, true, true, digits, dp);
}

int main() {
    freopen("sanchi.in", "r", stdin);
    freopen("sanchi.out", "w", stdout);
    int T;
    cin >> T;
    while (T--) {
        ll x, y;
        cin >> x >> y;
        cout << count_chaos(y) - count_chaos(x - 1) << endl;
    }
    return 0;
}