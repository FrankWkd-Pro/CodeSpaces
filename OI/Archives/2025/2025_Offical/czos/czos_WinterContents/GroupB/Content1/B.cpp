#include <bits/stdc++.h>

#include <iostream>
using namespace std;

int main() {
    int a, b, c, d, n, x, y;
    cin >> n >> x >> y;
    cin >> a >> b >> c >> d;
    int o = n * 4 / 10 * x;
    int p = n / 2 * y;
    int q = n * a + n * b + n * c + n * d;
    // cout << o << " " << p << " " << q << endl;
    cout << max({o, p, q}) << endl;
    return 0;
}