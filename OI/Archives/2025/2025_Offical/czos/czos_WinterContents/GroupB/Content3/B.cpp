#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, w;
    cin >> n >> m >> w;
    int now = m;
    while (n >= now) {
        n -= now;
        now += w;
    }
    cout << n << endl;
}