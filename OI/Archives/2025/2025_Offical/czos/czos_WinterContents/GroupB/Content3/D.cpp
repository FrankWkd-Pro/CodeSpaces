#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        for (int j = 1; j <= x; j++) {
            v.push_back(i);
        }
    }
    while (m--) {
        int op;
        cin >> op;
        cout << v[op] << "\n";
    }
    return 0;
}