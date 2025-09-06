#include <bits/stdc++.h>
using namespace std;
int n, neg, pos;
int a[1010101], b[1010101];

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}
bool checkMAX(double a, double aa, double b, double bb) {
    return aa / a > bb / b;
}
void print(int a, int b, bool is_minus) {
    // cout << "gcd " << a << " " << b << " " << gcd(a, b) << endl;
    if (a % b == 0 or b % a == 0) {
        cout << abs(a) / abs(b);
        return;
    }
    if (is_minus) {
        cout << '-';
    }
    cout << abs(a) / gcd(abs(a), abs(b)) << "/" << abs(b) / gcd(abs(a), abs(b));
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (x > 0)
            a[++pos] = x;
        else
            b[++neg] = abs(x);
        // cout << a[pos] << " " << b[neg] << endl;
    }
    sort(a + 1, a + 1 + pos);
    sort(b + 1, b + 1 + neg);
    // cout << "Pos: " << pos << endl << "Neg: " << neg << endl;
    if (pos == 0) {
        print(b[neg], b[1], 0);
    } else if (neg == 0) {
        print(a[pos], a[1], 0);
    } else if (neg == 1 and pos == 1) {
        // cout << a[1] << " " << b[1] << endl;
        if (abs(b[1]) > a[1]) {
            print(a[1], b[1], 1);
        } else {
            print(b[1], a[1], 1);
        }
    } else if (neg == 1 and pos > 1) {
        print(a[pos], a[1], 0);
    } else if (pos == 1 and neg > 1) {
        print(b[neg], b[1], 0);
    } else {
        if (checkMAX(a[1], a[pos], b[1], b[neg])) {
            print(a[pos], a[1], 0);
        } else {
            print(b[neg], b[1], 0);
        }
        return 0;
    }
}