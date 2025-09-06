#include <bits/stdc++.h>

#include <iostream>
using namespace std;
const int M = 1e9 + 7;
int f[1101];
int main() {
    int n;
    cin >> n;
    f[1] = 1, f[2] = 3, f[3] = 6;
    for (int i = 4; i <= n; i++) {
        f[i] = (f[i - 1] + f[i - 2] * 2 + f[i - 3]) % M;
    }
    cout << f[n];
    return 0;
}