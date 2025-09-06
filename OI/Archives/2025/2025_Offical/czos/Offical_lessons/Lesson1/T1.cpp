#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
const int M = 1e4 + 10;
int a[N], b[N], c[M];
int n, k;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b + 1, b + 1 + n);
    k = unique(b + 1, b + 1 + n) - b - 1;
    for (int i = 1; i <= k; i++) {
        a[i] = lower_bound(b + 1, b + 1 + k, a[i]) - b;
        c[a[i]]++;
    }
    for (int i = 1; i <= k; i++) {
        cout << b[i] << " " << c[i] << endl;
    }

    return 0;
}