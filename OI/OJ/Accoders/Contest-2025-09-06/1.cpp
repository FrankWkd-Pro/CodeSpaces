#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
const long long mod = 998244353;
long long a[N], n, m;
char op;
int x;
void AA() {
    for (int i = 2; i <= n; i++) {
        a[i] = (a[i] + a[i - 1] + mod) % mod;
    }
}
void BB() {
    for (int i = n; i >= 2; i--) {
        a[i] = (a[i] - a[i - 1] + mod) % mod;
    }
}
int main() {
    freopen("trans.in", "r", stdin);
    freopen("trans.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int A = 0, B = 0;
    while (m--) {
        cin >> op >> x;
        if (op == 'A') {
            A += x;
        } else if (op == 'B') {
            B += x;
        }
    }
    if (A > B) {
        int minus = A - B;
        for (int i = 1; i <= minus; i++) {
            AA();
        }
    } else {
        int minus = B - A;
        for (int i = 1; i <= minus; i++) {
            BB();
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << (a[i] + mod) % mod << " ";
    }
    return 0;
}
