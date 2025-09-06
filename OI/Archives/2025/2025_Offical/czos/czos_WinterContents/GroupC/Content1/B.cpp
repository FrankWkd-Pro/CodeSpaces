#include <iostream>
using namespace std;
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    int a, b, n;
    cin >> a >> b >> n;
    cout << n / a + n / b - n / (a * b / gcd(a, b));
}