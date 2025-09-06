#include <bits/stdc++.h>

#include <iostream>
using namespace std;

int main() {
    int n, k;
    string s;
    cin >> n;

    unordered_map<char, int> a;
    for (char c = '0'; c <= '9'; ++c) {
        a[c] = c - '0';
    }
    for (char c = 'A'; c <= 'F'; ++c) {
        a[c] = c - 'A' + 10;
    }

    for (int i = 0; i < n; i++) {
        cin >> k >> s;
        long long ans = 0;
        long long base = 1;
        reverse(s.begin(), s.end());
        for (char c : s) {
            ans += a[c] * base;
            base *= k;
        }
        cout << ans << endl;
    }

    return 0;
}