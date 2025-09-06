#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, a, b;
    cin >> n >> a >> b;
    if (a < b)
        std::cout << (n % a) + n / a * b << std::endl;
    else {
        std::cout << n << std::endl;
    }
}