#include <bits/stdc++.h>
using namespace std;
int f[21010];
int v[1010], w[1010];
int main() {
    int n, c;
    cin >> n >> c;
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
        w[i] *= v[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = c; j >= 1; j--) {
            if (j >= w[i]) {
                f[j] = max(f[j], f[j - w[i]] + v[i]);
            }
        }
    }
    cout << f[c];
}